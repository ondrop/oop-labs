#pragma once

#include "stdafx.h"

using namespace std;

const string ENTER_STRING = "Enter string";
const string EMPTY_STRING = "Empty string received";

map<string, char> dictionary = {
    {"&quot;", '"'},
    {"&apos;", '\''},
    {"&lt;", '<'},
    {"&gt;", '>'},
    {"&amp;", '&'}
};

string HtmlDecode(string workStr);