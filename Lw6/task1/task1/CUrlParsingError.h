#pragma once
#include "stdafx.h"

using namespace std;

class CUrlParsingError : public invalid_argument
{
public:
	CUrlParsingError(const string& message);
};
