@echo off
REM Простой скрипт сборки компилятора Sup без CMake
REM Требует g++ в PATH

echo ========================================
echo   Сборка компилятора Sup
echo ========================================
echo.

REM Проверка наличия g++
where g++ >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ОШИБКА: g++ не найден в PATH
    echo Установите MinGW или добавьте его в PATH
    pause
    exit /b 1
)

echo Компилятор найден:
g++ --version | findstr "g++"
echo.

REM Создание директории для сборки
if not exist "build_simple" mkdir build_simple

echo Компиляция исходных файлов...
echo.

REM Компиляция всех .cpp файлов
echo [1/5] Компиляция Lexer.cpp...
g++ -std=c++17 -c src/Lexer.cpp -o build_simple/Lexer.o -Iinclude
if %ERRORLEVEL% NEQ 0 (
    echo ОШИБКА при компиляции Lexer.cpp
    pause
    exit /b 1
)

echo [2/5] Компиляция Parser.cpp...
g++ -std=c++17 -c src/Parser.cpp -o build_simple/Parser.o -Iinclude
if %ERRORLEVEL% NEQ 0 (
    echo ОШИБКА при компиляции Parser.cpp
    pause
    exit /b 1
)

echo [3/5] Компиляция SemanticAnalyzer.cpp...
g++ -std=c++17 -c src/SemanticAnalyzer.cpp -o build_simple/SemanticAnalyzer.o -Iinclude
if %ERRORLEVEL% NEQ 0 (
    echo ОШИБКА при компиляции SemanticAnalyzer.cpp
    pause
    exit /b 1
)

echo [4/5] Компиляция CodeGenerator.cpp...
g++ -std=c++17 -c src/CodeGenerator.cpp -o build_simple/CodeGenerator.o -Iinclude
if %ERRORLEVEL% NEQ 0 (
    echo ОШИБКА при компиляции CodeGenerator.cpp
    pause
    exit /b 1
)

echo [5/5] Компиляция main.cpp...
g++ -std=c++17 -c src/main.cpp -o build_simple/main.o -Iinclude
if %ERRORLEVEL% NEQ 0 (
    echo ОШИБКА при компиляции main.cpp
    pause
    exit /b 1
)

echo.
echo Линковка исполняемого файла...
g++ -std=c++17 build_simple/Lexer.o build_simple/Parser.o build_simple/SemanticAnalyzer.o build_simple/CodeGenerator.o build_simple/main.o -o sup.exe
if %ERRORLEVEL% NEQ 0 (
    echo ОШИБКА при линковке
    pause
    exit /b 1
)

echo.
echo ========================================
echo   Сборка завершена успешно!
echo ========================================
echo.
echo Исполняемый файл: sup.exe
echo.
echo Использование:
echo   sup.exe version
echo   sup.exe compile examples\hello.sup
echo   sup.exe dev examples\hello.sup
echo.

REM Тестирование
echo Тестирование компилятора...
sup.exe version
echo.

pause
