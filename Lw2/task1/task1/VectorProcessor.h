#pragma once

#include "stdafx.h"

using namespace std;

const float TWO = 2.0;
const string ENTER_ELEMENTS = "Enter array elements separated by space";
const string ELEMENTS_NOT_RECEIVED = "Array elements not received";
const string DIVISION_BY_ZERO = "You cannot divide by zero";

vector<float> ReadArray();
float GetHalfOfMaxElement(const vector<float>& numberVector);
bool VectorProcessing(vector<float>& numberVector);
void PrintVector(const vector<float>& numberVector);
void SortVector(vector<float>& numberVector);