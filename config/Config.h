#ifndef __CERTCARD__
#define __CERTCARD__
#include "string"
#include "json.hpp"
namespace ns {
	struct camera
	{
		int port;
	};

	struct certcard
	{
		int port;
	};

	struct storage
	{
		std::string ip;
		int port;
	};

	struct server
	{
		std::string ip;
		int port;
	};


	struct configdata
	{
		ns::camera camera;
		ns::certcard certcard;
		ns::storage storage;
		ns::server server;
	};
}
class Config
{
public:
	static Config* GetInstance();
	ns::configdata GetData();
	void SaveDataToFile(std::string filepath);

	~Config();
private:
	Config();
	static Config* m_instance;
	ns::configdata m_data;
	

};

#endif //__CERTCARD__

