/***************************************************************
* Name:      ImgStorage.h
* Purpose:   Communication utility class with remote file server.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#include "ImgStorage.h"
//#include "FastSDK.h"
#include "../config/Config.h"
#include <fastdfs/fdfs_client.h>
#include <fastdfs/fdfs_global.h>
#include <fastcommon/base64.h>
#include <fastcommon/sockopt.h>
#include <fastcommon/logger.h>
#include <fastdfs/fdfs_http_shared.h>

ImgStorage* ImgStorage::m_pInstance = new ImgStorage();

ImgStorage::Garbo ImgStorage::garbo;

ImgStorage::ImgStorage()
{

}

ImgStorage::~ImgStorage()
{

}

int ImgStorage::UploadFile(const std::string& filename,std::string& remoteurl)
{
    /*
    	std::string ip = Config::GetInstance()->GetData().storage.ip;
    	int port = Config::GetInstance()->GetData().storage.port;
    	fastdfs_sdk sdk;
    	int code = sdk.connect(ip.c_str(), port);
    	ST_RETURN_DATA data = sdk.upload_file(filename.c_str(), true);
    	char url[256];
    	memset(url, 0, 256);
    	code = sdk.remote_file_to_ulr(data, url);
    	remoteurl = url;

    	return code;
    	*/
}


int UploadFile()
{
    char *conf_filename;
    char *local_filename;
    ConnectionInfo *pTrackerServer;
    ConnectionInfo *pStorageServer;
    int result;
    ConnectionInfo storageServer;
    char group_name[FDFS_GROUP_NAME_MAX_LEN + 1];
    char remote_filename[256];
    char master_filename[256];
    FDFSMetaData meta_list[32];
    int meta_count;
    char token[32 + 1];
    char file_id[128];
    char file_url[256];
    char szDatetime[20];
    char szPortPart[16];
    int url_len;
    time_t ts;
    int store_path_index;
    FDFSFileInfo file_info;

    conf_filename = (char*)"client.conf";
    if ((result=fdfs_client_init(conf_filename)) != 0)
    {
        return result;
    }

    pTrackerServer = tracker_get_connection();
    if (pTrackerServer == NULL)
    {
        fdfs_client_destroy();
        return errno != 0 ? errno : ECONNREFUSED;
    }

    pStorageServer = NULL;
    *group_name = '\0';
    local_filename = NULL;

    char *prefix_name;
    const char *file_ext_name;
    char slave_filename[256];
    int slave_filename_len;

    store_path_index = 0;

    ConnectionInfo storageServers[FDFS_MAX_SERVERS_EACH_GROUP];
    ConnectionInfo *pServer;
    ConnectionInfo *pServerEnd;
    int storage_count;

    if ((result=tracker_query_storage_store_list_without_group( pTrackerServer, storageServers, FDFS_MAX_SERVERS_EACH_GROUP, &storage_count, group_name, &store_path_index)) == 0)
    {
        printf("tracker_query_storage_store_list_without_group: \n");
        pServerEnd = storageServers + storage_count;
        for (pServer=storageServers; pServer<pServerEnd; pServer++)
        {
            printf("\tserver %d. group_name=%s, ip_addr=%s, port=%d\n", (int)(pServer - storageServers) + 1, group_name, pServer->ip_addr, pServer->port);
        }
        printf("\n");
    }

    if ((result=tracker_query_storage_store(pTrackerServer, \
                                            &storageServer, group_name, &store_path_index)) != 0)
    {
        fdfs_client_destroy();
        printf("tracker_query_storage fail, error no: %d, error info: %s\n", result, STRERROR(result));
        return result;
    }

    printf("group_name=%s, ip_addr=%s, port=%d\n", group_name, storageServer.ip_addr, storageServer.port);

    if ((pStorageServer=tracker_connect_server(&storageServer, &result)) == NULL)
    {
        fdfs_client_destroy();
        return result;
    }

    const char *filename = basename(local_filename);
    memset(&meta_list, 0, sizeof(meta_list));
    meta_count = 0;
    strcpy(meta_list[meta_count].name, "file_name");
    strcpy(meta_list[meta_count].value, filename);
    meta_count++;

    file_ext_name = fdfs_get_file_ext_name(local_filename);
    *group_name = '\0';

    result = storage_upload_by_filename(pTrackerServer, \
                                        pStorageServer, store_path_index, \
                                        local_filename, file_ext_name, \
                                        meta_list, meta_count, \
                                        group_name, remote_filename);

    printf("storage_upload_by_filename\n");

    if (result != 0)
    {
        printf("upload file fail, " \
               "error no: %d, error info: %s\n", \
               result, STRERROR(result));
        tracker_disconnect_server_ex(pStorageServer, true);
        fdfs_client_destroy();
        return result;
    }

    if (g_tracker_server_http_port == 80)
    {
        *szPortPart = '\0';
    }
    else
    {
        sprintf(szPortPart, ":%d", g_tracker_server_http_port);
    }

    sprintf(file_id, "%s/%s", group_name, remote_filename);
    url_len = sprintf(file_url, "http://%s%s/%s", \
                      pStorageServer->ip_addr, szPortPart, file_id);
    if (g_anti_steal_token)
    {
        ts = time(NULL);
        fdfs_http_gen_token(&g_anti_steal_secret_key, file_id, \
                            ts, token);
        sprintf(file_url + url_len, "?token=%s&ts=%d", \
                token, (int)ts);
    }

    printf("group_name=%s, remote_filename=%s\n", \
           group_name, remote_filename);

    fdfs_get_file_info(group_name, remote_filename, &file_info);
    printf("source ip address: %s\n", file_info.source_ip_addr);
    printf("file timestamp=%s\n", formatDatetime(
               file_info.create_timestamp, "%Y-%m-%d %H:%M:%S", \
               szDatetime, sizeof(szDatetime)));
    printf("file size=%" PRId64 "\n", file_info.file_size);
    printf("file crc32=%u\n", file_info.crc32);
    printf("example file url: %s\n", file_url);

    strcpy(master_filename, remote_filename);
    *remote_filename = '\0';

    prefix_name = (char*)"_big";
    result = storage_upload_slave_by_filename(pTrackerServer,
             NULL, local_filename, master_filename, \
             prefix_name, file_ext_name, \
             meta_list, meta_count, \
             group_name, remote_filename);

    printf("storage_upload_slave_by_filename\n");


    if (result != 0)
    {
        printf("upload slave file fail, " \
               "error no: %d, error info: %s\n", \
               result, STRERROR(result));
        tracker_disconnect_server_ex(pStorageServer, true);
        fdfs_client_destroy();
        return result;
    }

    if (g_tracker_server_http_port == 80)
    {
        *szPortPart = '\0';
    }
    else
    {
        sprintf(szPortPart, ":%d", g_tracker_server_http_port);
    }

    sprintf(file_id, "%s/%s", group_name, remote_filename);
    url_len = sprintf(file_url, "http://%s%s/%s", \
                      pStorageServer->ip_addr, szPortPart, file_id);
    if (g_anti_steal_token)
    {
        ts = time(NULL);
        fdfs_http_gen_token(&g_anti_steal_secret_key, file_id, \
                            ts, token);
        sprintf(file_url + url_len, "?token=%s&ts=%d", \
                token, (int)ts);
    }

    printf("group_name=%s, remote_filename=%s\n", \
           group_name, remote_filename);

    fdfs_get_file_info(group_name, remote_filename, &file_info);

    printf("source ip address: %s\n", file_info.source_ip_addr);
    printf("file timestamp=%s\n", formatDatetime(
               file_info.create_timestamp, "%Y-%m-%d %H:%M:%S", \
               szDatetime, sizeof(szDatetime)));
    printf("file size=%" PRId64 "\n", file_info.file_size);
    printf("file crc32=%u\n", file_info.crc32);
    printf("example file url: %s\n", file_url);

    if (fdfs_gen_slave_filename(master_filename, \
                                prefix_name, file_ext_name, \
                                slave_filename, &slave_filename_len) == 0)
    {

        if (strcmp(remote_filename, slave_filename) != 0)
        {
            printf("slave_filename=%s\n" \
                   "remote_filename=%s\n" \
                   "not equal!\n", \
                   slave_filename, remote_filename);
        }
    }


    tracker_disconnect_server_ex(pStorageServer, true);
    tracker_disconnect_server_ex(pTrackerServer, true);

    fdfs_client_destroy();
}

