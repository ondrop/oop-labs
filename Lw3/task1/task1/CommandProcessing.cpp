#include "CommandProcessing.h"

bool GetCommandParam(stringstream& streamStr, int& param, ostream& output)
{
	string strParam;
	streamStr >> strParam;
	if (streamStr.fail())
	{
		output << PARAMETER_NOT_PASSED << endl;
		return false;
	}

	try
	{
		size_t pos;
		param = stoi(strParam, &pos);
		if (pos != strParam.length())
		{
			output << PARAMETER_NOT_INT << endl;
			return false;
		}
	}
	catch (const exception&)
	{
		output << PARAMETER_IS_LARGE << endl;
		return false;
	}

	return true;
}

optional<CommandData> GetCommandData(string command, ostream& output)
{
	stringstream streamStr;
	streamStr << command;
	streamStr >> command;
	int param = 0;
	if (command == SET_GEAR || command == SET_SPEED)
	{
		bool canGetParam = GetCommandParam(streamStr, param, output);
		if (!canGetParam)
		{
			return nullopt;
		}
	}

	CommandData commandData = { command, param };

	return commandData;
}