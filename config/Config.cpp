/***************************************************************
* Name:      Config.cpp
* Purpose:   Config utility class including read and initial config file.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#include "Config.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
//#include <direct.h>
//#include <io.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <libgen.h>
#include <sys/unistd.h>

using json = nlohmann::json;
namespace ns {


	void to_json(json& j, const configdata& p) {
		j = json{ { "camera", p.camera },{ "certcard",p.certcard },{ "storage",p.storage },{ "server",p.server } };
	}

	void to_json(json& j, const camera& p) {
		j = json{ { "index", p.index }, {"threshold", p.threshold } ,{ "elapsed", p.elapsed } };
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
		p.index = j.at("index").get<int>();
		p.threshold = j.at("threshold").get<float>();
		p.elapsed = j.at("elapsed").get<int>();
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

const std::string confile =  "etc/config.json";

Config* Config::m_pInstance = new Config();

Config::Garbo Config::garbo;

Config::Config()
{
/*
	char pwd[256];
	std::memset(pwd, 0, 256);
	_getcwd(pwd, sizeof(pwd));
	this->m_pwd = pwd;
	this->m_pwd.append("/");
*/
}

Config::~Config()
{

}

ns::configdata Config::GetData()
{
	return this->m_data;
}
std::string Config::GetPwd()
{
	return this->m_pwd;
}

void Config::SaveDataToFile(const std::string& filepath)
{
	if (access(dirname((char*)filepath.c_str()),6) == -1)
	{
		mkdir(dirname((char*)filepath.c_str()),0755);
	}

	json j = m_data;
	std::ofstream out(filepath);

	out << j << std::endl;
}


int Config::LoadConfig()
{
	std::ifstream in(this->m_pwd + confile, std::ios::in);
	if (!in)
	{
		this->m_data.camera.index = 0;
		this->m_data.camera.threshold = 0.90;
		this->m_data.camera.elapsed = 10;

		this->m_data.certcard.port = 1001;

		this->m_data.server.ip = "115.28.84.22";
		this->m_data.server.port = 8060;

		this->m_data.storage.ip = "121.42.50.172";
		this->m_data.storage.port = 22122;

		this->SaveDataToFile(this->m_pwd + confile);
	}
	else {
		json j;
		in >> j;
		this->m_data = j;
		in.close();
	}
	return 0;
}
