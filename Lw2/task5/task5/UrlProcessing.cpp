#include "stdafx.h"
#include "UrlProcessing.h"

using namespace std;

map<string, int> protocol_to_port = {
    {"http", 80},
    {"https", 443},
    {"ftp", 21}
};

bool GetPort(const string& protocol, const string& givenPort, int& port)
{
    if (givenPort.length())
    {
        try
        {
            port = stoi(givenPort);
        }
        catch (const exception&)
        {
            cout << ERROR_CONVERTING_STRING_TO_INT << endl;
            cout << PORT_OUT_OF_RANGE << endl;
            return false;
        }

        if (port >= MIN_PORT_VALUE && port <= MAX_PORT_VALUE)
        {
            return true;
        }
        else
        {
            cout << PORT_OUT_OF_RANGE << endl;
            return false;
        }
    }
    else
    {
        port = protocol_to_port[protocol];
        return true;
    }
}

bool ParseURL(const string& url, UrlInfo& urlinfo)
{
    string lowerUrl = url;
    boost::algorithm::to_lower(lowerUrl);
    const regex urlRegex("(https?|ftp):\/\/([^:/]+):?([0-9]+)?\/?(.+)?");
    smatch matches;
    if (regex_match(lowerUrl, matches, urlRegex))
    {
        string protocol = matches[1];
        urlinfo.host = matches[2];
        bool validPort = GetPort(protocol, matches[3], urlinfo.port);
        if (!validPort)
        {
            return false;
        }

        urlinfo.document = matches[4];
    }
    else
    {
        cout << URL_NOT_VALID << endl;
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

