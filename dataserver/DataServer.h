/***************************************************************
* Name:      DataServer.h
* Purpose:   Communication utility class with remote server.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#ifndef __DATASERVER_H__
#define __DATASERVER_H__

#include <string>

class DataServer
{
public:
	static DataServer * GetInstance() {
		return m_pInstance;
	}

	int UploadData(const std::string& cardno, const std::string& imgpath);

private:
	DataServer();
	~DataServer();

	static DataServer* m_pInstance;

	class Garbo

	{
	public:
		~Garbo()
		{
			if (DataServer::m_pInstance)
			{
				delete DataServer::m_pInstance;
			}
		}
	};

	static Garbo garbo;
};

#endif //__DATASERVER_H__

