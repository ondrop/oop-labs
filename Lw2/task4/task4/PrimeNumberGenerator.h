#pragma once

#include "stdafx.h"

using namespace std;

const int TWO = 2;
const int ARG_COUNT = 2;
const int MAX_GIVEN_NUMBER = 100000000;
const string INVALID_ARG_COUNT = "Invalid arguments count";
const string USAGE_ARG = "Usage: task4.exe <upper bound>";
const string PRIME_NUMBERS_NOT_EXIST = "Prime numbers don't exist";

struct Args
{
    int upperBound;
};

set<int> GetPrimeNumberSet(int upperBound, vector<bool> boolAllNumbers);
vector<bool> GetFiltredBoolVector(int upperBound);
set<int> GeneratePrimeNumbersSet(int upperBound);
bool IsCorrectUpperBound(int upperBound);
optional<Args> ParseArgs(int argc, char* argv[]);
bool ArePrimeNumbersExist(set<int> primeNumbersSet);