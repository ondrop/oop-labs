#include "stdafx.h"
#include "VectorProcessor.h"

using namespace std;

vector<float> ReadArray()
{
    vector<float> numberVector;
    copy(istream_iterator<float>(cin), istream_iterator<float>(), back_inserter(numberVector));

    return numberVector;
}

float GetHalfOfMaxElement(const vector<float>& numberVector)
{
    return *max_element(numberVector.begin(), numberVector.end()) / TWO;
}

bool VectorProcessing(vector<float>& numberVector)
{
    if (numberVector.empty())
    {
        cout << ELEMENTS_NOT_RECEIVED << endl;
        return false;
    }

    float halfOfMaxElement = GetHalfOfMaxElement(numberVector);
    if (halfOfMaxElement == 0)
    {
        cout << DIVISION_BY_ZERO << endl;
        return false;
    }

    for (float& number : numberVector)
    {
        number /= halfOfMaxElement;
    }

    return true;
}

void PrintVector(const vector<float>& numberVector)
{
    for (float number : numberVector)
    {
        cout << number << ' ';
    }

    cout << endl;
}

void SortVector(vector<float>& numberVector)
{
    sort(numberVector.begin(), numberVector.end());
}