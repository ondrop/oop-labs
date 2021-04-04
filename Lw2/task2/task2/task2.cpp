#include "stdafx.h"
#include "StringProcessor.h"

using namespace std;

int main()
{
    cout << ENTER_STRING << endl;
	string workStr;
	getline(cin, workStr);
    if (!CheckEmptyString(workStr))
    {
        return 1;
    }

    string outStr = HtmlDecode(workStr);
    cout << outStr << endl;

    return 0;
}