#include <iostream>
#include <fstream>
#include <optional>
#include <string>

using namespace std;

struct Args
{
    string inputFileName;
    string outputFileName;
    string searchString;
    string replaceString;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 5)
    {
        cout << "Invalid arguments count" << endl;
        cout << "Usage: Replace.exe <input file name> <output file name> <search string> <replace string>" << endl;
        return nullopt;
    }
    
    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    args.searchString = argv[3];
    args.replaceString = argv[4];
    return args;
}

bool AreStringsEqual(string workStr, string searchString, int firstPosOfStr)
{
    int searchStringLength = searchString.length();
    for (int i = 0; i < searchStringLength; i++)
    {
        if (workStr[firstPosOfStr + i] != searchString[i])
        {
            return false;
        }
    }

    return true;
}

int FindFirstSearchStringPos(string workStr, string searchString)
{
    int strLength = workStr.length();
    int searchStringLength = searchString.length();
    if (strLength < searchStringLength)
    {
        return -1;
    }

    for (int i = 0; i < strLength; i++)
    {
        if (strLength - i < searchStringLength) {
            return -1;
        }

        if (workStr[i] == searchString[0])
        {
            return i;
        }
    }

    return -1;
}

string ReplaceStr(string workStr, string searchString, string replaceString)
{
    string replacedStr = "";
    if (workStr.length() == 0)
    {
        if (searchString == "")
        {
            return replaceString;
        }

        return workStr;
    }

    while (workStr.length() > 0)
    {
        int firstPos = FindFirstSearchStringPos(workStr, searchString);
        if (firstPos != -1)
        {
            bool isFindText = AreStringsEqual(workStr, searchString, firstPos);
            for (int j = 0; j < firstPos; j++)
            {
                replacedStr += workStr[j];
            }

            int replaceCount = firstPos;
            if (isFindText)
            {
                replacedStr += replaceString;
                replaceCount += searchString.length();
            }
            else
            {
                replacedStr += workStr[firstPos];
                replaceCount++;
            }

            workStr.erase(0, replaceCount);
        }
        else
        {
            replacedStr += workStr;
            workStr = "";
        }
    }

    return replacedStr;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }

    ifstream input;
    input.open(args->inputFileName);
    if (!input.is_open())
    {
        cout << "Failed to open '" << args->inputFileName << "' for reading" << endl;
        return 1;
    }

    ofstream output;
    output.open(args->outputFileName);
    if (!output.is_open())
    {
        cout << "Failed to open '" << args->outputFileName << "' for writing" << endl;
        return 1;
    }

    string workStr = "";
    string outputStr = "";
    while (getline(input, workStr))
    {
        outputStr = ReplaceStr(workStr, args->searchString, args->replaceString);
        output << outputStr << endl;
    }

    if (input.bad())
    {
        cout << "Failed to read data from input file" << endl;
        return 1;
    }

    if (!output.flush())
    {
        cout << "Failed to write data to output file" << endl;
        return 1;
    }

    return 0;
}
