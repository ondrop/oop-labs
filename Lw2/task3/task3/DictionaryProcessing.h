#pragma once

#include "stdafx.h"

using namespace std;

const int ARG_COUNT = 2;
const string INVALID_ARG_COUNT = "Invalid arguments count";
const string USAGE_ARG = "Usage: task3.exe <dictionary file name>";
const string EXIT_FROM_DIALOG = "...";
const string SAVE_CONFIRM = "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.";
const string SAVE_VALUE = "y";
const string DATA_SAVED = "��������� ���������. �� ��������.";
const string GOODBYE = "�� ��������.";
const string STRANGE_WORD = "����������� ����� \"";
const string GOT_WORD = "����� \"";
const string WORD_IGNORED = "\" ���������������.";
const string DOUBLE_QUOTE_AND_DOT = "\".";
const string SAVED_AS = "\" ��������� � ������� ��� \"";
const string ENTER_REQUEST = "\". ������� ������� ��� ������ ������ ��� ������.";
const string ENTER_WORD = "������� �����";
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