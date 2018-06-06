#ifndef __CONFIG__
#define __CONFIG__
#include "string"
#include "json.hpp"
namespace ns {
	struct camera
	{
		int index;
		float threshold;
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
	std::string GetPwd();
	void SaveDataToFile(std::string filepath);

	~Config();
private:
	Config();
	static Config* m_instance;
	ns::configdata m_data;
	std::string m_pwd;
};

#endif //__CONFIG__
