#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

const int MATRIX_DIMENTION = 3;
const int AFTER_POINT_COUNT = 3;
const int MINOR_MATRIX_DIMENTION = 2;
const int ARG_COUNT = 2;
const int ROUND_NUMBER = 1000;
const string INVALID_ARG_COUNT = "Invalid arguments count";
const string USAGE_ARG = "Usage: Invert.exe <matrix file name>";
const string FAILED_READ_DATA = "Failed to read data from input file";
const string FAILED_TO_OPEN = "Failed to open '";
const string FAILED_FOR_READING = "' for reading";
const string GOT_EMPTY_FILE = "Got empty file";
const string MATRIX_NOT_COMPLETELY_FILED = "The matrix is not completely filled";
const string NOT_ENOUGH_SYMBOLS = "There are not enough symbols in the string";
const string MUST_CONSIST_NUMBERS = "Matrix must consist of numbers";
const string ERROR_CONVERTING_STRING_TO_FLOAT = "Error converting string to float";
const string MANY_ITEM_IN_STRING = "Matrix contains many items in string";
const string MANY_ITEM = "There are many symbols in the matrix";
const string ZERO_DETERMINANT = "Determinant is 0.";
const string INVERT_MATRIX_NOT_FOUND = "The inverse matrix could not be found";

struct Args
{
    string inputFileName;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != ARG_COUNT)
    {
        cout << INVALID_ARG_COUNT << endl;
        cout << USAGE_ARG << endl;
        return nullopt;
    }

    Args args;
    args.inputFileName = argv[1];
    return args;
}

float** CreateMatrix(int lineCount, int columnCount)
{
    float** matrix;
    matrix = new float* [lineCount];
    for (int i = 0; i < columnCount; i++)
    {
        matrix[i] = new float[columnCount];
    }

    return matrix;
}

float** GetTwoByTwoMatrix(float** matrix, int lineIndex, int columnIndex) {
    float** newMatrix = CreateMatrix(MINOR_MATRIX_DIMENTION, MINOR_MATRIX_DIMENTION);
    int newMatrixLineIndex = 0;
    for (int i = 0; i < MINOR_MATRIX_DIMENTION; i++) {
        if (i == lineIndex)
        {
            newMatrixLineIndex = 1;
        }

        int newMatrixColumnIndex = 0;
        for (int j = 0; j < MINOR_MATRIX_DIMENTION; j++) {
            if (j == columnIndex)
            {
                newMatrixColumnIndex = 1;
            }

            newMatrix[i][j] = matrix[i + newMatrixLineIndex][j + newMatrixColumnIndex];
        }
    }

    return newMatrix;
}

float GetDeterminant(float** matrix, int matrixDimension)
{
    float determinant = 0;
    if (matrixDimension == MINOR_MATRIX_DIMENTION)
    {
        determinant = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    else if (matrixDimension == MATRIX_DIMENTION)
    {
        int coefficient = 1;
        for (int i = 0; i < MATRIX_DIMENTION; i++)
        {
            float** newMatrix = GetTwoByTwoMatrix(matrix, i, 0);
            determinant += coefficient * matrix[i][0] * GetDeterminant(newMatrix, MINOR_MATRIX_DIMENTION);
            coefficient = -coefficient;
        }
    }

    return determinant;
}

float** GetMinorMatrix(float** matrix, int matrixDimension)
{
    float** minorMatrix = CreateMatrix(matrixDimension, matrixDimension);
    int coefficient = 1;
    for (int i = 0; i < matrixDimension; i++)
    {
        for (int j = 0; j < matrixDimension; j++)
        {
            float** newMatrix = GetTwoByTwoMatrix(matrix, i, j);
            float determinant = GetDeterminant(newMatrix, matrixDimension - 1);
            minorMatrix[i][j] = coefficient * determinant;
            coefficient = -coefficient;
        }
    }

    return minorMatrix;
}

float** GetTransposeMatrix(float** matrix, int matrixDimension)
{
    float** transposeMatrix = CreateMatrix(matrixDimension, matrixDimension);
    for (int i = 0; i < matrixDimension; i++)
    {
        for (int j = 0; j < matrixDimension; j++)
        {
            transposeMatrix[j][i] = matrix[i][j];
        }
    }

    return transposeMatrix;
}

float** GetInvertMatrix(int matrixDimension, const float& determinant, float** &transposeMatrix)
{
    float** invertMatrix = CreateMatrix(matrixDimension, matrixDimension);
    for (int i = 0; i < matrixDimension; i++)
    {
        for (int j = 0; j < matrixDimension; j++)
        {
            invertMatrix[i][j] = 1 / determinant * transposeMatrix[i][j];
        }
    }

    return invertMatrix;
}

void PrintInvertMatrix(int matrixDimension, float** invertMatrix)
{
    for (int i = 0; i < matrixDimension; i++)
    {
        for (int j = 0; j < matrixDimension; j++)
        {
            cout << setprecision(AFTER_POINT_COUNT);
            cout << fixed;
            cout << invertMatrix[i][j] << ' ';
        }

        cout << endl;
    }
}

bool FillMatrix(int matrixDimension, istream &input, float** matrix)
{
    string str;
    stringstream streamStr;
    for (int i = 0; i < MATRIX_DIMENTION; i++)
    {
        if (input.eof())
        {
            cout << MATRIX_NOT_COMPLETELY_FILED << endl;
            return false;
        }
        else
        {
            getline(input, str);
            if (input.bad())
            {
                cout << FAILED_READ_DATA << endl;
                return false;
            }

            streamStr << str;
        }

        for (int j = 0; j < MATRIX_DIMENTION; j++)
        {
            streamStr >> str;
            if (streamStr.fail())
            {
                cout << NOT_ENOUGH_SYMBOLS << endl;
                return false;
            }

            if (str.length() == 0)
            {
                cout << GOT_EMPTY_FILE << endl;
                return false;
            }

            try
            {
                size_t pos;
                float matrixItem = stof(str, &pos);
                if (pos != str.length())
                {
                    cout << MUST_CONSIST_NUMBERS << endl;
                    return false;
                }

                matrix[i][j] = matrixItem;
            }
            catch (const exception&)
            {
                cout << ERROR_CONVERTING_STRING_TO_FLOAT << endl;
                return false;
            }
        }

        if (streamStr >> str)
        {
            cout << MANY_ITEM_IN_STRING << endl;
            return false;
        }

        stringstream().swap(streamStr);
    }

    if (!input.eof())
    {
        cout << MANY_ITEM_IN_STRING << endl;
        return false;
    }

    return true;
}

void CleanPointer(float** matrix, int matrixDimension)
{
    for (int i = 0; i < matrixDimension; i++)
    {
        delete matrix[i];
    }

    delete[] matrix;
}

bool InvertMatrix(istream &input)
{
    float** matrix = CreateMatrix(MATRIX_DIMENTION, MATRIX_DIMENTION);
    if (!FillMatrix(MATRIX_DIMENTION, input, matrix))
    {
        return false;
    }

    const float DETERMINANT = GetDeterminant(matrix, MATRIX_DIMENTION);
    if (DETERMINANT == 0)
    {
        cout << ZERO_DETERMINANT << endl;
        cout << INVERT_MATRIX_NOT_FOUND << endl;
        return false;
    }

    float** minorMatrix = GetMinorMatrix(matrix, MATRIX_DIMENTION);
    float** transposeMatrix = GetTransposeMatrix(minorMatrix, MATRIX_DIMENTION);
    float** invertMatrix = GetInvertMatrix(MATRIX_DIMENTION, DETERMINANT, transposeMatrix);
    PrintInvertMatrix(MATRIX_DIMENTION, invertMatrix);
    CleanPointer(matrix, MATRIX_DIMENTION);
    CleanPointer(minorMatrix, MATRIX_DIMENTION);
    CleanPointer(transposeMatrix, MATRIX_DIMENTION);
    CleanPointer(invertMatrix, MATRIX_DIMENTION);

    return true;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }

    ifstream input;
    input.open(args->inputFileName);
    if (!input.is_open())
    {
        cout << FAILED_TO_OPEN << args->inputFileName << FAILED_FOR_READING << endl;
        return 1;
    }

    if (!InvertMatrix(input))
    {
        return 1;
    }

    return 0;
}
