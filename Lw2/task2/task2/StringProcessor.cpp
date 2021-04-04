#include "stdafx.h"
#include "StringProcessor.h"

using namespace std;

map<string, char> encodeDictionary = {
    {"&quot;", '"'},
    {"&apos;", '\''},
    {"&lt;", '<'},
    {"&gt;", '>'},
    {"&amp;", '&'}
};

bool CheckEmptyString(const string& workStr)
{
    if (workStr.length() == 0)
    {
        cout << EMPTY_STRING << endl;
        return false;
    }

    return true;
}

string HtmlDecode(string workStr)
{
    string outStr;
    while (workStr.length() > 0)
    {
        int firstPos = workStr.find(AMPERSAND);
        int secondPos = workStr.find(SEMICOLON);
        if (secondPos <= firstPos)
        {
            int pos = firstPos;
            firstPos = secondPos;
            secondPos = pos;
        }

        secondPos++;
        if (firstPos != string::npos && secondPos != string::npos)
        {
            outStr += workStr.substr(0, firstPos);
            string searchStr = workStr.substr(firstPos, secondPos - firstPos);
            if (encodeDictionary[searchStr])
            {
                outStr.push_back(encodeDictionary[searchStr]);
            }
            else
            {
                outStr += searchStr;
            }

            workStr = workStr.substr(secondPos);
        }
        else
        {
            outStr += workStr;
            workStr = "";
        }
    }

    return outStr;
}