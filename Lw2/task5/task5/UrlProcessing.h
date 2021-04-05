#pragma once

#include "stdafx.h"

using namespace std;

const string ENTER_URL = "Enter URL";
const string HOST = "HOST: ";
const string PORT = "PORT: ";
const string DOC = "DOC: ";

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

int GetPort(const string& protocol, string port);
bool ParseURL(const string& url, UrlInfo& urlinfo);
void PrintUrlInfo(ostream& output, const string& url, const UrlInfo& urlinfo);