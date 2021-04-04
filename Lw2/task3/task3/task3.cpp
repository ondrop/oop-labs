#include "stdafx.h"
#include "DictionaryProcessing.h"

using namespace std;

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }

    map<string, string> dictionary = DeserializeDictionary(args->dictionaryFileName);

    if (!UseDictionary(cin, cout, dictionary, args->dictionaryFileName))
    {
        return 1;
    }

    return 0;    
}