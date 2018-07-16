/***************************************************************
* Name:      DataServer.cpp
* Purpose:   Communication utility class with remote server.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#include "DataServer.h"
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include "../config/Config.h"

/*
using namespace utility;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;
*/
DataServer* DataServer::m_pInstance = new DataServer();

//DataServer::Garbo DataServer::garbo;

DataServer::DataServer()
{

}

DataServer::~DataServer()
{

}

int DataServer::UploadData(const std::string& cardno, const std::string& imgpath)
{
/*
	const string_t host = utility::conversions::to_string_t(Config::GetInstance()->GetData().server.ip);
	web::uri_builder clientbuilder;
	clientbuilder.set_scheme(U("http"));
	clientbuilder.set_host(host);
	clientbuilder.set_port(Config::GetInstance()->GetData().server.port);

	// Create http_client to send the request.
	http_client client(clientbuilder.to_uri());

	// Build request URI and start the request.
	uri_builder builder(U("/device/register/register.do"));
	builder.append_query(U("cardID"), cardno.c_str());
	builder.append_query(U("path"), imgpath.c_str());
	http_response response = client.request(methods::GET, builder.to_string()).get();

	if (200 == response.status_code()) {
		try
		{
			const web::json::value& v = response.extract_json().get();
			if (v.has_string_field(U("code"))) {
				const web::json::value& a = v.at(U("code"));
				auto code = utility::conversions::to_utf8string(a.as_string());
				return atoi(code.c_str());
			}
			return 500;
		}
		catch (...)
		{
			return 500;
		}
	}
	return response.status_code();
*/
}
