// hdconsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <HDstdapi.h>
#include <memory>
#include <ostream>
#include <fstream>
#include <stdio.h>  
#include <direct.h>  

int main()
{
	int result = HD_InitComm(1001);
	if (0 == result) {
		char pwd[256];
		memset(pwd, 0, 256);
		_getcwd(pwd, sizeof(pwd));

		std::string bmpfile(pwd);
		bmpfile.append("/certcard.bmp");

		std::string datafile(pwd);
		datafile.append("/data.txt");

		do {
			result = HD_Authenticate();
			if (0 == result) {
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

					printf_s("%s", name);
					printf_s("%s", gendar);
					printf_s("%s", nation);
					printf_s("%s", birth);
					printf_s("%s", address);
					printf_s("%s", certno);
					printf_s("%s", department);
					printf_s("%s", effectdata);
					printf_s("%s", expire);
				}
			}
		}
		while (0 != result);
	}

	HD_CloseComm(1001);

    return result;
}

