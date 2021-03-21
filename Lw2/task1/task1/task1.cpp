#include "stdafx.h"
#include "VectorProcessor.h"

using namespace std;

int main()
{
    cout << ENTER_ELEMENTS << endl;
    vector<float> numberVector = ReadArray();
    if (!VectorProcessing(numberVector))
    {
        return 1;
    }

    SortVector(numberVector);
    PrintVector(numberVector);

    return 0;
}