#include "DataServer.h"
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include "../config/Config.h"

using namespace utility;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

DataServer* DataServer::m_instance = new DataServer();

DataServer::DataServer()
{

}

DataServer::~DataServer()
{

}

DataServer* DataServer::GetInstance()
{
	return m_instance;
}

int DataServer::UploadData(const std::string& cardno, const std::string& imgpath)
{
	const string_t host = utility::conversions::to_string_t(Config::GetInstance()->GetData().server.ip);
	web::uri_builder clientbuilder;
	clientbuilder.set_scheme(U("http"));
	clientbuilder.set_host(host);
	clientbuilder.set_port(Config::GetInstance()->GetData().server.port);

	// Create http_client to send the request.
	http_client client(clientbuilder.to_uri());

	// Build request URI and start the request.
	uri_builder builder(U("/device/register/register.do"));
	builder.append_query(U("cardID"), utility::conversions::to_string_t(cardno));
	builder.append_query(U("path"), utility::conversions::to_string_t(imgpath));
	http_response response = client.request(methods::GET, builder.to_string()).get();

	if (200 == response.status_code()) {
		const web::json::value& v = response.extract_json().get();
		const web::json::value& a = v.at(U("code"));
		return a.as_integer();
	}
	return response.status_code();

}