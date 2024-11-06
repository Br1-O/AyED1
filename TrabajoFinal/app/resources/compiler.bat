@echo off
rem Set the compiler command
set COMPILER=g++

rem Set the output executable name
set OUTPUT=../main.exe

rem List of .cpp files to compile
set SOURCES=../main.cpp ../businessService/src/model/Article.cpp ../businessService/src/controller/ArticleManager.cpp ../businessService/src/model/Client.cpp ../businessService/src/controller/ClientManager.cpp ../businessService/src/model/Employee.cpp ../businessService/src/controller/EmployeeManager.cpp ../businessService/src/model/Order.cpp ../businessService/src/controller/OrderManager.cpp ../utils/src/Utils.cpp ../businessService/resources/data/dataExample.cpp ../utils/src/FileHandler.cpp

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