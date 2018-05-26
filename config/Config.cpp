#include "stdafx.h"
#include "Config.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <direct.h>
#include <io.h>
#include <iostream>  


using json = nlohmann::json;
namespace ns {


	void to_json(json& j, const configdata& p) {
		j = json{ { "camera", p.camera },{ "certcar",p.certcard },{ "storage",p.storage },{ "server",p.server } };
	}

	void to_json(json& j, const camera& p) {
		j = json{ { "port", p.port } };
	}

	void to_json(json& j, const certcard& p) {
		j = json{ { "port", p.port } };
	}
	void to_json(json& j, const storage& p) {
		j = json{ { "ip", p.ip },{ "port",p.port } };
	}

	void to_json(json& j, const server& p) {
		j = json{ { "ip", p.ip },{ "port",p.port } };
	}

	void from_json(const json& j, configdata& p) {
		p.camera = j.at("camera").get<camera>();
		p.certcard = j.at("certcard").get<certcard>();
		p.server = j.at("server").get<server>();
		p.storage = j.at("storage").get<storage>();
	}


	void from_json(const json& j, camera& p) {
		p.port = j.at("port").get<int>();
	}

	void from_json(const json& j, certcard& p) {
		p.port = j.at("port").get<int>();
	}


	void from_json(const json& j, server& p) {
		p.ip = j.at("ip").get<std::string>();
		p.port = j.at("port").get<int>();
	}

	void from_json(const json& j, storage& p) {
		p.ip = j.at("ip").get<std::string>();
		p.port = j.at("port").get<int>();
	}
};

const std::string confile = "./etc/config.json";

Config* Config::m_instance = new Config();

Config::Config()
{

	std::ifstream in(confile, std::ios::in);
	bool result=true;// = json::accept(in, j);
	if (!result)
	{
		this->m_data.camera.port = 0;
		this->m_data.certcard.port = 1001;
		this->m_data.server.ip = "127.0.0.1";
		this->m_data.server.port = 443;
		this->m_data.storage.ip = "127.0.0.1";
		this->m_data.storage.port = 443;

		this->SaveDataToFile(confile);
	}
	else {
		json j;
		in >> j;

		//json j=json::parse(in);
		//in >> j;		
		this->m_data = j;
	}
	in.close();
}

Config::~Config()
{

}

Config* Config::GetInstance()
{
	return m_instance;
}

ns::configdata Config::GetData()
{
	return this->m_data;
}

void Config::SaveDataToFile(std::string filepath)
{
	char drive[10];
	char dir[256];
	char fname[256];
	char ext[256];

	_splitpath_s(filepath.c_str(), drive, dir, fname, ext);
	if (_access(dir, 6) == -1)
	{
		_mkdir(dir);  //创建成功返回0 不成功返回-1  
	}
	json j = m_data;
	std::ofstream out(filepath);
	//out << std::setw(4) << j << std::endl;
	out << j << std::endl;
}