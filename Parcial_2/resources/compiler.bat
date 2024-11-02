@echo off
rem Set the compiler command
set COMPILER=g++

rem Set the output executable name
set OUTPUT=../main.exe

rem List of .cpp files to compile
set SOURCES=../src/main.cpp ../src/cpp/Article.cpp ../src/cpp/ArticleManager.cpp ../src/cpp/Client.cpp ../src/cpp/ClientManager.cpp ../src/cpp/Employee.cpp ../src/cpp/EmployeeManager.cpp ../src/cpp/Order.cpp ../src/cpp/OrderManager.cpp ../src/cpp/Utils.cpp data/data.cpp

rem Compile the .cpp files
%COMPILER% -o %OUTPUT% %SOURCES%

rem Check if the compilation was successful
if %ERRORLEVEL% NEQ 0 (
    echo Compilation failed!
    pause
    exit /b
)

echo Compilation successful! Executable created: %OUTPUT%
pause