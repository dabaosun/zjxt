/***************************************************************
* Name:      ImgStorage.h
* Purpose:   Communication utility class with remote file server.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#include "ImgStorage.h"
#include "FastSDK.h"
#include "../config/Config.h"

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
	try
	{
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
	}
	catch (...) {
		return -1;
	}
}


