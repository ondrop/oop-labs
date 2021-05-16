#include "CHttpUrl.h"
#include "CUrlParsingError.h"

const string HTTP = "http";
const string HTTPS = "https";
const string PORT_OUT_OF_RANGE = "Port is out of range 1 to 65535";
const string INVALID_URL = "Received invalid Url";
const string INVALID_PROTOCOL = "Url protocol is invalid";
const string PORT_NOT_NUMERIC = "Port should be is number";
const string PROTOCOL = "Protocol: ";
const string URL_DOMAIN = "Domain: ";
const string PORT = "Port: ";
const string DOCUMENT = "Document: ";
const int MIN_PORT_VALUE = 1;
const int MAX_PORT_VALUE = 65535;
const regex URL_REGEX("(https?):\/\/([^:/]+):?([0-9]+)?\/?(.+)?");

const map<Protocol, unsigned short> PROTOCOL_TO_PORT = {
    {Protocol::HTTP, 80},
    {Protocol::HTTPS, 443}
};

const map<Protocol, string> PROTOCOL_TO_STR = {
    {Protocol::HTTP, HTTP},
    {Protocol::HTTPS, HTTPS}
};

CHttpUrl::CHttpUrl(string const& url)
{
    ParseUrl(url);
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol)
	:m_domain(domain),
	m_document(document),
	m_protocol(protocol)
{
    m_port = GetDefaultPort();
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port)
	:m_domain(domain),
	m_document(document),
	m_protocol(protocol),
	m_port(port)
{
}

string CHttpUrl::GetURL() const
{
    auto it = PROTOCOL_TO_PORT.find(GetProtocol());
    if (it != PROTOCOL_TO_PORT.end())
    {
        if ((*it).second != GetPort())
        {
            return ProtocolToString() + "://" + GetDomain() + ":" + to_string(GetPort()) + "/" + GetDocument();
        }
        else
        {
            return ProtocolToString() + "://" + GetDomain() + "/" + GetDocument();
        }
    }
}

string CHttpUrl::GetDomain() const
{
	return m_domain;
}

string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

string CHttpUrl::toString() const
{
    stringstream streamStr;
    streamStr << PROTOCOL << ProtocolToString() << endl;
    streamStr << URL_DOMAIN << GetDomain() << endl;
    streamStr << PORT << to_string(GetPort()) << endl;
    streamStr << DOCUMENT << GetDocument();

    return streamStr.str();
}

void CHttpUrl::ParseUrl(string const& url)
{
    smatch matches;
    if (regex_match(url, matches, URL_REGEX))
    {
        m_protocol = ParseProtocol(matches[1]);
        m_domain = matches[2];
        m_port = matches[3].str().empty() ? GetDefaultPort() : ParsePort(matches[3]);
        m_document = matches[4];
    }
    else
    {
        throw CUrlParsingError(INVALID_URL);
    }
}

Protocol CHttpUrl::ParseProtocol(string const& strProtocol)
{
    if (strProtocol == HTTP)
    {
        return Protocol::HTTP;
    }
    else if (strProtocol == HTTPS)
    {
        return Protocol::HTTPS;
    }

    throw CUrlParsingError(INVALID_PROTOCOL);
}

unsigned short CHttpUrl::ParsePort(string const& strPort)
{
    int port = 0;
    try
    {
        port = stoi(strPort);
    }
    catch (const exception&)
    {
        throw CUrlParsingError(PORT_NOT_NUMERIC);
    }

    if (port < MIN_PORT_VALUE || port > MAX_PORT_VALUE)
    {
        throw CUrlParsingError(PORT_OUT_OF_RANGE);
    }

    return port;
}

unsigned short CHttpUrl::GetDefaultPort() const
{
    auto it = PROTOCOL_TO_PORT.find(m_protocol);
    if (it != PROTOCOL_TO_PORT.end())
    {
        return (*it).second;
    }
}

string CHttpUrl::ProtocolToString() const
{
    auto it = PROTOCOL_TO_STR.find(m_protocol);
    if (it != PROTOCOL_TO_STR.end())
    {
        return (*it).second;
    }
}
