#include "stdafx.h"
#include "PrimeNumberGenerator.h"

using namespace std;

bool ArePrimeNumbersExist(set<int> primeNumbersSet)
{
    return !primeNumbersSet.empty();
}

set<int> GetPrimeNumberSet(int upperBound, vector<bool> boolAllNumbers)
{
    set<int> primeNumbersSet;
    for (int i = TWO; i <= upperBound; i++)
    {
        if (boolAllNumbers[i])
        {
            primeNumbersSet.insert(i);
        }
    }

    return primeNumbersSet;
}

vector<bool> GetFiltredBoolVector(int upperBound)
{
    vector<bool> boolAllNumbers(upperBound + 1, true);

    for (int i = TWO; i * i <= upperBound; i++)
    {
        if (boolAllNumbers[i])
        {
            for (int j = i * i; j <= upperBound; j += i)
            {
                boolAllNumbers[j] = false;
            }
        }
    }

    return boolAllNumbers;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
    vector<bool> boolAllNumbers = GetFiltredBoolVector(upperBound);

    set<int> primeNumbersSet;
    for (int i = TWO; i <= upperBound; i++)
    {
        if (boolAllNumbers[i])
        {
            primeNumbersSet.insert(i);
        }
    }

    return primeNumbersSet;
}

bool IsCorrectUpperBound(int upperBound)
{
    return upperBound >= 1 && upperBound <= MAX_GIVEN_NUMBER;
}

optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != ARG_COUNT)
    {
        cout << INVALID_ARG_COUNT << endl;
        cout << USAGE_ARG << endl;
        return nullopt;
    }

    Args args;
    args.upperBound = stoi(argv[1]);
    return args;
}