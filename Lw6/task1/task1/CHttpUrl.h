#pragma once
#include "stdafx.h"

using namespace std;

enum class Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(string const& url);
	CHttpUrl(
		string const& domain,
		string const& document,
		Protocol protocol = Protocol::HTTP
	);
	CHttpUrl(
		string const& domain,
		string const& document,
		Protocol protocol,
		unsigned short port
	);

	string GetURL() const;
	string GetDomain() const;
	string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;
	string toString() const;

private:
	string m_domain, m_document;
	unsigned short m_port;
	Protocol m_protocol;

	void ParseUrl(string const& url);
	Protocol ParseProtocol(string const& strProtocol);
	unsigned short ParsePort(string const& strPort);
	unsigned short GetDefaultPort() const;
	string ProtocolToString() const;
};
