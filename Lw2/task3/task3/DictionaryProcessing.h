#pragma once

#include "stdafx.h"

using namespace std;

const int ARG_COUNT = 2;
const string INVALID_ARG_COUNT = "Invalid arguments count";
const string USAGE_ARG = "Usage: task3.exe <dictionary file name>";
const string EXIT_FROM_DIALOG = "...";
const string SAVE_CONFIRM = "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.";
const string SAVE_VALUE = "y";
const string DATA_SAVED = "Изменения сохранены. До свидания.";
const string GOODBYE = "До свидания.";
const string STRANGE_WORD = "Неизвестное слово \"";
const string GOT_WORD = "Слово \"";
const string WORD_IGNORED = "\" проигнорировано.";
const string DOUBLE_QUOTE_AND_DOT = "\".";
const string SAVED_AS = "\" сохранено в словаре как \"";
const string ENTER_REQUEST = "\". Введите перевод или пустую строку для отказа.";
const string ENTER_WORD = "Введите слово";
const string OUTPUT_FILE_OPEN_ERROR = "Can't open output file to write";

struct Args
{
    string dictionaryFileName;
};

optional<Args> ParseArgs(int argc, char* argv[]);
map<string, string> DeserializeDictionary(const string& inputFileName);
bool SaveDictionary(const string& outputFileName, map<string, string> dictionary);
bool ExitFromDictionaryDialog(istream& input, ostream& output, int startDictionarySize, map<string, string> dictionary, bool& needToSave);
void AddValueToDictionary(istream& input, ostream& output, map<string, string>& dictionary, const string& searchStr);
optional<map<string, string>> UseDictionary(istream& input, ostream& output, map<string, string>& dictionary, const string& dictionaryFileName);