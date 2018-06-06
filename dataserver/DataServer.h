#ifndef __DATASERVER_H__
#define __DATASERVER_H__

#include <string>

class DataServer
{
public:
	static DataServer * GetInstance();
	int UploadData(const std::string& cardno, const std::string& imgpath);
	~DataServer();

private:
	DataServer();
	static DataServer* m_instance;
};

#endif //__DATASERVER_H__

