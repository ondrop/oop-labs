#include "CommandProcessing.h"

using namespace std;

int main()
{
	cout << ENTER_COMMAND << endl;
	string workStr;
	Car car;
	CarControl carControl(car, cout);
	while (getline(cin, workStr))
	{
		if (workStr == EXIT)
		{
			return 0;
		}

		auto commandData = GetCommandData(workStr, cout);
		if (commandData)
		{
			carControl.CallCommand(commandData->command, commandData->param);
		}
	}

	return 0;
}