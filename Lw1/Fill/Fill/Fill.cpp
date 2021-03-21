#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <queue>

using namespace std;

const int FILL_SIZE = 100;
const int ARG_COUNT = 3;
const string INVALID_ARG_COUNT = "Invalid arguments count";
const string USAGE_ARG = "Usage: Fill.exe <input file name> <output file name>";
const string FAILED_WRITE_DATA = "Failed to write data to output file";
const string FAILED_READ_DATA = "Failed to read data from input file";
const string FAILED_TO_OPEN = "Failed to open '";
const string FAILED_FOR_READING = "' for reading";
const string FAILED_FOR_WRITING = "' for writing";
const string GOT_EMPTY_FILE = "Got empty file";
const char START_SYMBOL = 'O';

struct Args
{
    string inputFileName;
    string outputFileName;
};

struct Pos
{
    int x;
    int y;
};

bool CheckFailedReadData(istream& input)
{
    if (input.bad())
    {
        cout << FAILED_READ_DATA << endl;
        return false;
    }

    return true;
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
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    return args;
}

void PushToStack(int i, int j, char(&matrix)[FILL_SIZE][FILL_SIZE], queue <Pos> & queue)
{
    if (matrix[i][j] == ' ')
    {
        matrix[i][j] = '.';
        queue.push({ i, j });
    }
}

void PaintTheMatrix(int i, int j, char (&matrix)[FILL_SIZE][FILL_SIZE], int lineCount, int columnCount)
{
    queue <Pos> queue;
    queue.push({ i, j });
    while (!queue.empty())
    {
        Pos pos = queue.front();
        queue.pop();
        i = pos.x;
        j = pos.y;
        if (i + 1 < lineCount)
        {
            PushToStack(i + 1, j, matrix, queue);
        }

        if (i - 1 >= 0)
        {
            PushToStack(i - 1, j, matrix, queue);
        }

        if (j + 1 < columnCount)
        {
            PushToStack(i, j + 1, matrix, queue);
        }

        if (j - 1 >= 0)
        {
            PushToStack(i, j - 1, matrix, queue);
        }
    }
}

bool PrintMatrix(int lineCount, int columnCount, ostream &output, const char (&matrix)[FILL_SIZE][FILL_SIZE])
{
    for (int i = 0; i < lineCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            output << matrix[i][j];
        }

        output << endl;
        if (!output.flush())
        {
            cout << FAILED_WRITE_DATA << endl;
            return false;
        }
    }

    return true;
}

bool GetMatrixDimension(istream &input, int& lineCount, int& columnCount)
{
    string str;
    while (getline(input, str))
    {
        if (lineCount + 1 > FILL_SIZE)
        {
            break;
        }

        lineCount++;
        if (str.length() > columnCount)
        {
            columnCount = str.length();
        }
    }

    if (!CheckFailedReadData(input))
    {
        return false;
    }

    if (columnCount > FILL_SIZE)
    {
        columnCount = FILL_SIZE;
    }

    input.clear();
    input.seekg(0, ios::beg);

    return lineCount != 0 && columnCount != 0;
}

void FillMatrixBySpaces(char (&matrix)[FILL_SIZE][FILL_SIZE])
{
    for (int i = 0; i < FILL_SIZE; i++)
    {
        for (int j = 0; j < FILL_SIZE; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}

bool FillMatrixFromInputFile(int lineCount, int columnCount, char (&matrix)[FILL_SIZE][FILL_SIZE], istream& input)
{
    FillMatrixBySpaces(matrix);
    string workStr;
    for (int i = 0; i < lineCount; i++)
    {
        if (input.eof()) {
            break;
        }

        getline(input, workStr);
        if (!CheckFailedReadData(input))
        {
            return false;
        }

        for (int j = 0; j < columnCount; j++)
        {
            if (j >= workStr.length())
            {
                break;
            }

            matrix[i][j] = workStr[j];
        }
    }

    return true;
}

void FillMatrix(int lineCount, int columnCount, char (&matrix)[FILL_SIZE][FILL_SIZE])
{
    for (int i = 0; i < lineCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            if (matrix[i][j] == START_SYMBOL)
            {
                PaintTheMatrix(i, j, matrix, lineCount, columnCount);
            }
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
        cout << FAILED_TO_OPEN << args->inputFileName << FAILED_FOR_READING << endl;
        return 1;
    }

    ofstream output;
    output.open(args->outputFileName);
    if (!output.is_open())
    {
        cout << FAILED_TO_OPEN << args->outputFileName << FAILED_FOR_WRITING << endl;
        return 1;
    }

    int lineCount = 0;
    int columnCount = 0;
    if (!GetMatrixDimension(input, lineCount, columnCount))
    {
        cout << GOT_EMPTY_FILE << endl;
        return 1;
    }

    char matrix[FILL_SIZE][FILL_SIZE];
    if (!FillMatrixFromInputFile(lineCount, columnCount, matrix, input))
    {
        return 1;
    }

    FillMatrix(lineCount, columnCount, matrix);
    if (!PrintMatrix(lineCount, columnCount, output, matrix))
    {
        return 1;
    }

    return 0;
}
