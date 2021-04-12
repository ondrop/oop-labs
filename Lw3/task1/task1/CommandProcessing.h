#pragma once
#include "stdafx.h"
#include "CarControl.h"

struct CommandData
{
	string command;
	int param;
};

const string EXIT = "Exit";
const string ENTER_COMMAND = "Enter command";
const string PARAMETER_NOT_PASSED = "Parameter not passed";
const string PARAMETER_NOT_INT = "The received parameter is not an integer";
const string PARAMETER_IS_LARGE = "The parameter is too large";

bool GetCommandParam(stringstream& streamStr, int& param, ostream& output);
optional<CommandData> GetCommandData(string command, ostream& output);
