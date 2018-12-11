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
#define MSG(fmt,...) char msg[256];\
	sprintf_s(msg, 256, fmt, ##__VA_ARGS__);

#define LOG_DEBUG(fmt,...) {\
	MSG(fmt)\
	Config::GetInstance()->log_debug(msg);}

#define LOG_INFO(fmt,...)  {\
	MSG(fmt)\
	Config::GetInstance()->log_info(msg);}

#define LOG_ERROR(fmt,...)  {\
	MSG(fmt)\
	Config::GetInstance()->log_error(msg);}

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
	void log_error(const std::string& error);
	void log_info(const std::string& info);
	void log_debug(const std::string& debug);

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
