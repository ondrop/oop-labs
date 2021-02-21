#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <cmath>

using namespace std;

struct Args
{
    string matrixFileName;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Invalid arguments count" << endl;
        cout << "Usage: Invert.exe <matrix file name>" << endl;
        return nullopt;
    }

    Args args;
    args.matrixFileName = argv[1];
    return args;
}

float** CreateMatrix(const int& lineCount, const int& columnCount)
{
    float** matrix;
    matrix = new float* [lineCount];
    for (int i = 0; i < columnCount; i++)
    {
        matrix[i] = new float[columnCount];
    }

    return matrix;
}

float** GetTwoByTwoMatrix(float** &matrix, const int &lineIndex, const int &columnIndex) {
    float** newMatrix = CreateMatrix(2, 2);
    int newMatrixLineIndex = 0;
    for (int i = 0; i < 2; i++) {
        if (i == lineIndex)
        {
            newMatrixLineIndex = 1;
        }

        int newMatrixColumnIndex = 0;
        for (int j = 0; j < 2; j++) {
            if (j == columnIndex)
            {
                newMatrixColumnIndex = 1;
            }

            newMatrix[i][j] = matrix[i + newMatrixLineIndex][j + newMatrixColumnIndex];
        }
    }

    return newMatrix;
}

float GetDeterminant(float** &matrix, int matrixDimension)
{
    float determinant = 0;
    if (matrixDimension == 2)
    {
        determinant = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    else if (matrixDimension == 3)
    {
        int coefficient = 1;
        for (int i = 0; i < 3; i++)
        {
            float** newMatrix = GetTwoByTwoMatrix(matrix, i, 0);
            int newMatrixDimension = 2;
            determinant += coefficient * matrix[i][0] * GetDeterminant(newMatrix, newMatrixDimension);
            coefficient = -coefficient;
        }
    }

    return determinant;
}

float** GetMinorMatrix(float** &matrix, float** minorMatrix, const int& matrixDimension)
{
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

float** GetTransposeMatrix(float** &matrix, float** &transposeMatrix, const int& matrixDimension)
{
    for (int i = 0; i < matrixDimension; i++)
    {
        for (int j = 0; j < matrixDimension; j++)
        {
            transposeMatrix[j][i] = matrix[i][j];
        }
    }

    return transposeMatrix;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }

    ifstream input;
    input.open(args->matrixFileName);
    if (!input.is_open())
    {
        cout << "Failed to open '" << args->matrixFileName << "' for reading" << endl;
        return 1;
    }

    const int matrixDimension = 3;
    float** matrix = CreateMatrix(matrixDimension, matrixDimension);

    string str = "";
    for (int i = 0; i < matrixDimension; i++)
    {
        for (int j = 0; j < matrixDimension; j++)
        {
            if (input.eof())
            {
                cout << "The matrix is not completely filled" << endl;
                return 1;
            }

            input >> str;
            if (str.length() == 0)
            {
                cout << "Empty file received" << endl;
                return 1;
            }

            try
            {
                size_t pos;
                float matrixItem = stof(str, &pos);
                if (pos != str.length())
                {
                    cout << "Matrix must consist of numbers" << endl;
                    return 1;
                }

                matrix[i][j] = matrixItem;
            }
            catch (const exception&)
            {
                cout << "Error converting string to float" << endl;
                return 1;
            }
        }
    }

    const float determinant = GetDeterminant(matrix, matrixDimension);
    if (determinant == 0)
    {
        cout << "Determinant is 0." << endl;
        cout << "The inverse matrix could not be found" << endl;
        return 1;
    }

    float** minorMatrix = CreateMatrix(matrixDimension, matrixDimension);
    minorMatrix = GetMinorMatrix(matrix, minorMatrix, matrixDimension);

    float** transposeMatrix = CreateMatrix(matrixDimension, matrixDimension);
    transposeMatrix = GetTransposeMatrix(minorMatrix, transposeMatrix, matrixDimension);

    float** invertMatrix = transposeMatrix;
    for (int i = 0; i < matrixDimension; i++)
    {
        for (int j = 0; j < matrixDimension; j++)
        {
            invertMatrix[i][j] = round(1 / determinant * transposeMatrix[i][j] * 1000) / 1000;
            cout << invertMatrix[i][j] << ' ';
        }

        cout << endl;
    }


    if (input.bad())
    {
        cout << "Failed to read data from input file" << endl;
        return 1;
    }

    return 0;
}
