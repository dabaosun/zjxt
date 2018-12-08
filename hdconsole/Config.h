/***************************************************************
* Name:      Config.h
* Purpose:   Config utility class including read and initial config file.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#ifndef __CONFIG__
#define __CONFIG__
#include <string>
#include "json.hpp"

namespace ns {
	struct camera
	{
		int index;
		float threshold;
		int elapsed;
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
	static Config* GetInstance() {
		return m_pInstance;
	};

	int LoadConfig();
	ns::configdata GetData();
	std::string GetPwd();

private:
	Config();
	~Config();
	static Config* m_pInstance;

	ns::configdata m_data;
	std::string m_pwd;

	void SaveDataToFile(const std::string& filepath);

private:
	class Garbo

	{
	public:
		~Garbo()
		{
			if (Config::m_pInstance)
			{
				delete Config::m_pInstance;
			}
		}
	};

	static Garbo garbo;
};

#endif //__CONFIG__
