REM @echo off

REM Путь к тестируемой программе передается через первый аргумент командной строки
SET MyProgram="%~1"

REM Защита запуска без аргумента, задающего путь к программе
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Fill empty file
echo Fill empty file
%MyProgram% Empty.txt "%TEMP%\output.txt" && goto err
echo Test 1 passed

REM Fill file in which one boundary of the contour contains a gap
echo Fill file in which one boundary of the contour contains a gap
%MyProgram% ContainsGap.txt "%TEMP%\output.txt" || goto err
fc ContainsGapOutput.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2 passed

REM Fill file in which one boundary of the contour contains a gaps
echo Fill file in which one boundary of the contour contains a gaps
%MyProgram% ContainsGap2.txt "%TEMP%\output.txt" || goto err
fc ContainsGap2Output.txt "%TEMP%\output.txt" > nul || goto err
echo Test 3 passed

REM IF output file is not specified, programm should fail
echo "If output file is not specified, programm should fail"
%MyProgram% MissingFile.txt && goto err
echo Test 4 passed

REM IF all params are not specified, programm should fail
echo "If all params are not specified, programm should fail"
%MyProgram% && goto err
echo Test 5 passed

REM Fill a file with no leading symbol
echo Fill a file with no leading symbol
%MyProgram% WithoutStartSymbol.txt "%TEMP%\output.txt" || goto err
fc WithoutStartSymbolOutput.txt "%TEMP%\output.txt" > nul || goto err
echo Test 6 passed

REM Fill a large file
echo Fill a large file
%MyProgram% LargeFile.txt "%TEMP%\output.txt" || goto err
fc LargeFileOutput.txt "%TEMP%\output.txt" > nul || goto err
echo Test 7 passed

REM Fill a large file which contains 101 lines and columns
echo Fill a large file which contains 101 lines and columns
%MyProgram% LargeFile101x101.txt "%TEMP%\output.txt" || goto err
fc LargeFile101x101Output.txt "%TEMP%\output.txt" > nul || goto err
echo Test 8 passedsed

REM Fill a large file which contains 101 lines and columns
echo Fill a large file which contains 100 lines and columns
%MyProgram% File100x100.txt "%TEMP%\output.txt" || goto err
fc File100x100Output.txt "%TEMP%\output.txt" > nul || goto err
echo Test 9 passed

REM Fill empty file with one line without any symbols
echo Fill empty file with one line without any symbols
%MyProgram% EmptyWithOneLineWithoutSymbols.txt "%TEMP%\output.txt" && goto err
echo Test 10 passed

REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0

REM Сюда будем попадать в случае ошибки
:err
echo Test failed
exit /B 1