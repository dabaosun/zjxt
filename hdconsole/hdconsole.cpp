// hdconsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <HDstdapi.h>
#include <memory>
#include <ostream>
#include <fstream>
#include <stdio.h>  
#include <direct.h>  
#include <chrono>
#include <thread>
#include "./Config.h"

const std::string& pwd = Config::GetInstance()->GetPwd();
std::ofstream resultout(pwd + "/hdconsole.log", std::ios::out);

void RecordLog(const std::string msg, int errorcode);

int main()
{
	Config::GetInstance()->LoadConfig();
	const ns::configdata& configdata = Config::GetInstance()->GetData();
	const int port = configdata.certcard.port;

	int result = HD_InitComm(port);
	RecordLog("HD_InitComm",result);
	if (0 == result) {
		std::string pwd = Config::GetInstance()->GetPwd();
		std::string bmpfile(pwd + "/certcard.bmp");
		std::string datafile(pwd + "/data.txt");
		
		do {
			result = HD_Authenticate();
			if (0 == result) {
				RecordLog("HD_Authenticate", result);

				char name[256];
				memset(name, 0, 256);

				char gendar[256];
				memset(gendar, 0, 256);

				char nation[256];
				memset(nation, 0, 256);

				char birth[256];
				memset(birth, 0, 256);

				char address[256];
				memset(address, 0, 256);

				char certno[256];
				memset(certno, 0, 256);

				char department[256];
				memset(department, 0, 256);

				char effectdata[256];
				memset(effectdata, 0, 256);

				char expire[256];
				memset(expire, 0, 256);

				result = HD_Read_BaseMsg(bmpfile.c_str(), name, gendar, nation,
					birth, address, certno, department, effectdata, expire);
				RecordLog("HD_Read_BaseMsg", result);
				if (0 == result) {
					std::ofstream out;
					out.open(datafile, std::ios::out);
					if (out.is_open()) {
						out << name << std::endl;
						out << gendar << std::endl;
						out << nation << std::endl;
						out << birth << std::endl;
						out << address << std::endl;
						out << certno << std::endl;
						out << department << std::endl;
						out << effectdata << std::endl;
						out << expire << std::endl;
						out.close();
					}
				}
				break;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
		while (0 != result);

		RecordLog("HD_CloseComm", HD_CloseComm(port));
	}
    return result;
}

void RecordLog(const std::string msg, int errorcode)
{
	if (resultout.is_open()) {
		time_t time_seconds = time(0);
		struct tm now_time;
		localtime_s(&now_time, &time_seconds);
		char tmp[64];
		strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &now_time);

		resultout << tmp << "--" << msg << ":" << errorcode << std::endl;
	}
}
