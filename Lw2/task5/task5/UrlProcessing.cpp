#include "stdafx.h"
#include "UrlProcessing.h"

using namespace std;

map<string, int> protocol_to_port = {
    {"http", 80},
    {"https", 443},
    {"ftp", 21}
};

int GetPort(const string& protocol, string port)
{
    if (port.length())
    {
        return stoi(port);
    }
    else
    {
        return protocol_to_port[protocol];
    }
}

bool ParseURL(const string& url, UrlInfo& urlinfo)
{
    string lowerUrl = url;
    boost::algorithm::to_lower(lowerUrl);
    const regex r("(https?|ftp):\/\/([^:/]+):?([0-9]+)?\/?(.+)?");
    smatch matches;
    if (regex_match(lowerUrl, matches, r))
    {
        string protocol = matches[1];
        urlinfo.host = matches[2];
        urlinfo.port = GetPort(protocol, matches[3]);
        urlinfo.document = matches[4];
    }
    else
    {
        return false;
    }

    return true;
}

void PrintUrlInfo(ostream& output, const string& url, const UrlInfo& urlinfo)
{
    output << url << endl;
    output << HOST << urlinfo.host << endl;
    output << PORT << urlinfo.port << endl;
    output << DOC << urlinfo.document << endl;
}

