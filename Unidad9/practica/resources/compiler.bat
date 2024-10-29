@echo off
rem Set the compiler command
set COMPILER=g++

rem Set the output executable name
set OUTPUT=../main.exe

rem List of .cpp files to compile
set SOURCES=../src/main.cpp ../src/cpp/students.cpp ../src/cpp/menuHandling.cpp ../src/cpp/enums.cpp ../src/cpp/fileHandling.cpp ../src/cpp/utils.cpp

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