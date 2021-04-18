#include "stdafx.h"
#include "CShapeControl.h"

using namespace std;

const string ENTER_SHAPES = "Enter shapes";

int main()
{
	cout << ENTER_SHAPES << endl;
	string workStr;
	CShapeControl shapeControl(cout);
	while (getline(cin, workStr))
	{
		if (workStr.empty())
		{
			continue;
		}

		stringstream streamStr;
		streamStr << workStr;
		shapeControl.AddShape(streamStr);		
	}

	shapeControl.PrintInfo();

	return 0;
}