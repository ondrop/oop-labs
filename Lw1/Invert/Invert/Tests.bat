REM @echo off

REM Путь к тестируемой программе передается через первый аргумент командной строки
SET MyProgram="%~1"

REM Защита запуска без аргумента, задающего путь к программе
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Invert matrix from empty file
echo Invert matrix from empty file
%MyProgram% Empty.txt && goto err
echo Test 1 passed

REM Invert correct matrix from non-empty file
echo Invert correct matrix from non-empty file
%MyProgram% CorrectMatrix.txt > "%TEMP%\output.txt" || goto err
fc CorrectMatrixOutput.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2 passed

REM Invert matrix that contains non number symbol
echo Invert matrix that contains non number symbol
%MyProgram% NonNumberFile.txt && goto err
echo Test 3 passed

REM Invert matrix in which one number is missing
echo Invert matrix in which one number is missing
%MyProgram% MissingOneNumber.txt && goto err
echo Test 4 passed

REM Invert matrix from missing file should fail
echo Invert matrix from missing file should fail
%MyProgram% MissingFile.txt && goto err
echo Test 5 passed

REM IF input file param is not specified, programm should fail
echo Input file param is not specified, programm should fail
%MyProgram% && goto err
echo Test 6 passed

REM Invert matrix in which determinant is zero
echo Invert matrix in which determinant is zero
%MyProgram% DeterminantIsZero.txt && goto err
echo Test 7 passed

REM Invert matrix which has very big number
echo Invert matrix which has very big number
%MyProgram% BigNumber.txt && goto err
echo Test 8 passed

REM Invert matrix which has many lines
echo Invert matrix which has many lines
%MyProgram% ManyLines.txt && goto err
echo Test 9 passed

REM Invert matrix which has many columns
echo Invert matrix which has many columns
%MyProgram% ManyColumns.txt && goto err
echo Test 10 passed

REM Invert incorrect matrix
echo Invert incorrect matrix
%MyProgram% IncorrectMatrix.txt && goto err
echo Test 11 passed

REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0

REM Сюда будем попадать в случае ошибки
:err
echo Test failed
exit /B 1