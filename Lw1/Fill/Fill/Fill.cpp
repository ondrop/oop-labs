#include <iostream>
#include <fstream>
#include <optional>
#include <string>

using namespace std;

struct Args
{
    string inputFileName;
    string outputFileName;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Invalid arguments count" << endl;
        cout << "Usage: Fill.exe <input file name> <output file name>" << endl;
        return nullopt;
    }

    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    return args;
}

void PushToStack(const int& i, const int& j, int &topOfStack, char** &matrix, int* &stackX, int* &stackY)
{
    if (matrix[i][j] == ' ')
    {
        matrix[i][j] = '.';
        topOfStack++;
        stackX[topOfStack] = i;
        stackY[topOfStack] = j;
    }
}

void GotFromStack(int& i, int& j, int* stackX, int* stackY, int &topOfStack)
{
    i = stackX[topOfStack];
    j = stackY[topOfStack];
    topOfStack = topOfStack - 1;
}

void Fill(int& i, int& j, char** &matrix, int* &stackX, int* &stackY, const int &lineCount, const int &columnCount)
{
    int topOfStack = 1;
    stackX[topOfStack] = i;
    stackY[topOfStack] = j;
    while (topOfStack > 0)
    {
        GotFromStack(i, j, stackX, stackY, topOfStack);
        if (i + 1 < lineCount)
        {
            PushToStack(i + 1, j, topOfStack, matrix, stackX, stackY);
        }

        if (i - 1 >= 0)
        {
            PushToStack(i - 1, j, topOfStack, matrix, stackX, stackY);
        }

        if (j + 1 < columnCount)
        {
            PushToStack(i, j + 1, topOfStack, matrix, stackX, stackY);
        }

        if (j - 1 >= 0)
        {
            PushToStack(i, j - 1, topOfStack, matrix, stackX, stackY);
        }
    }
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
        cout << "Failed to open '" << args->inputFileName << "' for reading" << endl;
        return 1;
    }

    ofstream output;
    output.open(args->outputFileName);
    if (!output.is_open())
    {
        cout << "Failed to open '" << args->outputFileName << "' for writing" << endl;
        return 1;
    }

    string str = "";
    int lineCount = 0;
    int columnCount = 0;
    const int maxMatrixDimension = 100;
    while (getline(input, str))
    {
        if (lineCount + 1 > maxMatrixDimension)
        {
            break;
        }

        lineCount++;
        if (str.length() > columnCount)
        {
            columnCount = str.length();
        }
    }

    if (lineCount == 0)
    {
        return 0;
    }

    if (columnCount > maxMatrixDimension)
    {
        columnCount = maxMatrixDimension;
    }

    char** matrix;
    matrix = new char* [lineCount];
    for (int i = 0; i < lineCount; i++)
    {
        matrix[i] = new char[columnCount];
    }

    for (int i = 0; i < lineCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            matrix[i][j] = ' ';
        }
    }

    input.clear();
    input.seekg(0, ios::beg);
    string workStr = "";
    for (int i = 0; i < lineCount; i++)
    {
        if (input.eof()) {
            break;
        }

        getline(input, workStr);
        for (int j = 0; j < columnCount; j++)
        {
            if (j >= workStr.length())
            {
                break;
            }

            matrix[i][j] = workStr[j];
        }
    }

    int* stackX = new int[lineCount * columnCount];
    int* stackY = new int[lineCount * columnCount];
    for (int i = 0; i < lineCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            if (matrix[i][j] == 'O')
            {
                Fill(i, j, matrix, stackX, stackY, lineCount, columnCount);
            }
        }
    }

    for (int i = 0; i < lineCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            output << matrix[i][j];
        }

        output << endl;
    }

    if (input.bad())
    {
        cout << "Failed to read data from input file" << endl;
        return 1;
    }

    if (!output.flush())
    {
        cout << "Failed to write data to output file" << endl;
        return 1;
    }

    return 0;
}
