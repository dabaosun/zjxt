#include "ImgStorage.h"
#include "FastSDK.h"
#include "../config/Config.h"

ImgStorage* ImgStorage::m_instance = new ImgStorage();

ImgStorage::ImgStorage()
{

}

ImgStorage::~ImgStorage()
{

}

ImgStorage* ImgStorage::GetInstance()
{
	return m_instance;
}

int ImgStorage::UploadFile(std::string filename,std::string& remoteurl)
{
	std::string ip = Config::GetInstance()->GetData().storage.ip;
	int port = Config::GetInstance()->GetData().storage.port;
	fastdfs_sdk sdk;
	int code = sdk.connect(ip.c_str(), port);
	ST_RETURN_DATA data = sdk.upload_file(filename.c_str(), true);
	char url[256];
	code = sdk.remote_file_to_ulr(data, url);
	remoteurl = url;
	return code;
}


