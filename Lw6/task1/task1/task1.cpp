#include "stdafx.h"
#include "CHttpUrl.h"

using namespace std;

const string APP_MESSAGE = "Enter url. To exit enter \"Ctrl + Z\"";

int main()
{
	string url;
	cout << APP_MESSAGE << endl;
	while (getline(cin, url))
	{
		try
		{
			CHttpUrl httpUrl(url);
			cout << httpUrl.toString() << endl;
		}
		catch (const exception& exc)
		{
			cout << exc.what() << endl;
		}
	}
}
