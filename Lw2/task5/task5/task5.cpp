#include "stdafx.h"
#include "UrlProcessing.h"

using namespace std;

int main()
{
    cout << ENTER_URL << endl;
    string url;
    getline(cin, url);
    UrlInfo urlinfo;
    bool validUrl = ParseURL(url, urlinfo);
    if (validUrl)
    {
        PrintUrlInfo(cout, url, urlinfo);
    }
    else
    {
        return 1;
    }

    return 0;
}