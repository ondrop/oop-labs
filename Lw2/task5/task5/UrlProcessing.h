#pragma once

#include "stdafx.h"

using namespace std;

const string ENTER_URL = "Enter URL";
const string HOST = "HOST: ";
const string PORT = "PORT: ";
const string DOC = "DOC: ";
const string ERROR_CONVERTING_STRING_TO_INT = "Error converting string to int";
const string PORT_OUT_OF_RANGE = "Port is out of range 1 to 65535";
const string URL_NOT_VALID = "Url isn't valid";
const int MIN_PORT_VALUE = 1;
const int MAX_PORT_VALUE = 65535;

enum class Protocol
{
    HTTP,
    HTTPS,
    FTP
};

struct UrlInfo
{
    string host;
    int port;
    string document;
};

bool GetPort(const string& protocol, const string& givenPort, int& port);
bool ParseURL(const string& url, UrlInfo& urlinfo);
void PrintUrlInfo(ostream& output, const string& url, const UrlInfo& urlinfo);