REM @echo off

REM Путь к тестируемой программе передается через первый аргумент командной строки
SET MyProgram="%~1"

REM Защита запуска без аргумента, задающего путь к программе
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Replace empty file
%MyProgram% Empty.txt "%TEMP%\output.txt" "34" "78" || goto err
fc Empty.txt "%TEMP%\output.txt" > nul || goto err
echo Test 1 passed

REM Replace non empty file with not found search text
%MyProgram% NonEmptyFile.txt "%TEMP%\output.txt" "34" "78" || goto err
fc NonEmptyFile.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2 passed

REM Replace non empty file with found search text
%MyProgram% NonEmptyFile.txt "%TEMP%\output.txt" "search" "replace" || goto err
fc NonEmptyFile.txt "%TEMP%\output.txt"
if ERRORLEVEL 2 (
	goto err;
)
if ERRORLEVEL 1 (
	echo Test 3 passed
) ELSE (
	goto err;
)

REM Replace missing file should fail
%MyProgram% MissingFile.txt "%TEMP%\output.txt" "34" "78" && goto err
echo Test 4 passed

REM IF replace string is not specified, programm should fail
%MyProgram% MissingFile.txt "%TEMP%\output.txt" "34" && goto err
echo Test 5 passed

REM IF search string is not specified, programm should fail
%MyProgram% MissingFile.txt "%TEMP%\output.txt" && goto err
echo Test 6 passed

REM IF output file is not specified, programm should fail
%MyProgram% MissingFile.txt && goto err
echo Test 7 passed

REM IF all params are not specified, programm should fail
%MyProgram% && goto err
echo Test 8 passed

REM Replace non empty file with found search text
%MyProgram% NonEmptyFile.txt "%TEMP%\output.txt" "search" "search" || goto err
fc NonEmptyFile.txt "%TEMP%\output.txt" > nul || goto err
echo Test 9 passed

REM Replace non empty file with found search text
%MyProgram% NonEmptyFile.txt "%TEMP%\output.txt" "" "" || goto err
fc NonEmptyFile.txt "%TEMP%\output.txt" > nul || goto err
echo Test 10 passed

REM Replace non empty file with found search text
%MyProgram% NonEmptyFile.txt "%TEMP%\output.txt" " " "test12" || goto err
fc NonEmptyFile.txt "%TEMP%\output.txt"
if ERRORLEVEL 2 (
	goto err;
)
if ERRORLEVEL 1 (
	echo Test 11 passed
) ELSE (
	goto err;
)

REM Replace non empty file with found search text
%MyProgram% NonEmptyFile.txt "%TEMP%\output.txt" "" " " || goto err
fc NonEmptyFile.txt "%TEMP%\output.txt"
if ERRORLEVEL 2 (
	goto err;
)
if ERRORLEVEL 1 (
	echo Test 12 passed
) ELSE (
	goto err;
)

REM Replace empty string to number
%MyProgram% Empty.txt "%TEMP%\output.txt" "" "78" || goto err
fc Empty.txt "%TEMP%\output.txt" || goto err
echo Test 13 passed

REM Replace text
%MyProgram% longtext.txt "%TEMP%\output.txt" "is" "TEXTSTRING" || goto err
fc longtext.txt "%TEMP%\output.txt"
if ERRORLEVEL 2 (
	goto err;
)
if ERRORLEVEL 1 (
	echo Test 14 passed
) ELSE (
	goto err;
)

REM Replace whitespace to nothing
%MyProgram% longtext.txt "%TEMP%\output.txt" " " "" || goto err
fc longtext.txt "%TEMP%\output.txt"
if ERRORLEVEL 2 (
	goto err;
)
if ERRORLEVEL 1 (
	echo Test 15 passed
) ELSE (
	goto err;
)


REM Replace whitespace to text
%MyProgram% longtext.txt "%TEMP%\output.txt" " " "BLA_BLA" || goto err
fc longtext.txt "%TEMP%\output.txt"
if ERRORLEVEL 2 (
	goto err;
)
if ERRORLEVEL 1 (
	echo Test 16 passed
) ELSE (
	goto err;
)

REM Replace whitespace to text
%MyProgram% longtext.txt "%TEMP%\output.txt" "\n" "BLA_BLA" || goto err
fc longtext.txt "%TEMP%\output.txt" > nul || goto err
echo Test 17 passed

REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0

REM Сюда будем попадать в случае ошибки
:err
echo Test failed
exit /B 1