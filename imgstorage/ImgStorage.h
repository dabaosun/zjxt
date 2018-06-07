/***************************************************************
* Name:      ImgStorage.h
* Purpose:   Communication utility class with remote file server.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#ifndef __IMGSTORAGE__
#define __IMGSTORAGE__
#include <string>

class ImgStorage
{
public:
	static ImgStorage* GetInstance() {
		return m_pInstance;
	}
	int UploadFile(const std::string& filename, std::string& remoteurl);

private:
	static ImgStorage* m_pInstance;
	ImgStorage();
	~ImgStorage();

	class Garbo

	{
	public:
		~Garbo()
		{
			if (ImgStorage::m_pInstance)
			{
				delete ImgStorage::m_pInstance;
			}
		}
	};

	static Garbo garbo;
};

#endif //__IMGSTORAGE__
