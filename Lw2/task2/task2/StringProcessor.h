#pragma once

#include "stdafx.h"

using namespace std;

const string ENTER_STRING = "Enter string to decode";
const string EMPTY_STRING = "Empty string received";
const char SEMICOLON = ';';
const char AMPERSAND = '&';

bool CheckEmptyString(const string& workStr);
string HtmlDecode(string workStr);