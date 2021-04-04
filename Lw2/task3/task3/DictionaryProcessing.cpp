#include "stdafx.h"
#include "DictionaryProcessing.h"

using namespace std;

optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != ARG_COUNT)
    {
        cout << INVALID_ARG_COUNT << endl;
        cout << USAGE_ARG << endl;
        return nullopt;
    }

    Args args;
    args.dictionaryFileName = argv[1];
    return args;
}

map<string, string> DeserializeDictionary(const string& inputFileName)
{
    map<string, string> dictionary;
    ifstream input;
    input.open(inputFileName);
    if (!input.is_open())
    {
        input.close();
        return dictionary;
    }

    boost::archive::text_iarchive iarch(input);
    iarch >> dictionary;

    input.close();

    return dictionary;
}

bool SaveDictionary(const string& outputFileName, map<string, string> dictionary)
{
    ofstream output(outputFileName);
    if (!output.is_open())
    {
        return false;
    }

    boost::archive::text_oarchive oarch(output);
    oarch << dictionary;
    output.close();

    return true;
}

bool ExitFromDictionaryDialog(istream& input, ostream& output, int startDictionarySize, map<string, string> dictionary, bool& needToSave)
{
    if (startDictionarySize < dictionary.size())
    {
        output << SAVE_CONFIRM << endl;
        string requestStr;
        getline(input, requestStr);
        boost::algorithm::to_lower(requestStr);
        if (requestStr == SAVE_VALUE)
        {
            needToSave = true;
            output << DATA_SAVED << endl;
        }
        else
        {
            needToSave = false;
            output << GOODBYE << endl;
        }
    }
    else
    {
        needToSave = false;
        output << GOODBYE << endl;
    }

    return needToSave;
}

void AddValueToDictionary(istream& input, ostream& output, map<string, string>& dictionary, const string& searchStr)
{
    output << STRANGE_WORD + searchStr + ENTER_REQUEST << endl;
    string valueStr;
    getline(input, valueStr);
    if (!valueStr.empty())
    {
        dictionary.insert({ searchStr, valueStr });
        output << GOT_WORD + searchStr + SAVED_AS + valueStr + DOUBLE_QUOTE_AND_DOT << endl;
    }
    else
    {
        output << GOT_WORD + searchStr + WORD_IGNORED << endl;
    }
}

optional<map<string, string>> UseDictionary(istream& input, ostream& output, map<string, string>& dictionary, const string& dictionaryFileName)
{
    output << ENTER_WORD << endl;
    string searchStr;
    int startDictionarySize = dictionary.size();
    map<string, string> prevDictionary = dictionary;
    bool needToSave = false;
    while (getline(input, searchStr))
    {
        string lowerSearchStr = searchStr;
        boost::algorithm::to_lower(lowerSearchStr);
        auto find = dictionary.find(lowerSearchStr);
        if (find != dictionary.end())
        {
            output << dictionary[lowerSearchStr] << endl;
        }
        else if (searchStr == EXIT_FROM_DIALOG)
        {
            needToSave = ExitFromDictionaryDialog(input, output, startDictionarySize, dictionary, needToSave);
            break;
        }
        else if (!searchStr.empty())
        {
            AddValueToDictionary(input, output, dictionary, searchStr);
        }
    }

    if (needToSave)
    {
        if (!SaveDictionary(dictionaryFileName, dictionary))
        {
            output << OUTPUT_FILE_OPEN_ERROR << endl;
            return nullopt;
        }
    }
    else
    {
        dictionary = prevDictionary;
    }

    return dictionary;
}