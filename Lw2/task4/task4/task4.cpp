#include "stdafx.h"
#include "PrimeNumberGenerator.h"

using namespace std;

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }

    int upperBound = args->upperBound;
    if (!IsCorrectUpperBound(upperBound))
    {
        return 1;
    }

    set<int> primeNumbersSet = GeneratePrimeNumbersSet(upperBound);
    if (!ArePrimeNumbersExist)
    {
        cout << PRIME_NUMBERS_NOT_EXIST << endl;
        return 0;
    }

    copy(primeNumbersSet.begin(), primeNumbersSet.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
