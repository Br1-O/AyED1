@echo off
rem Set the compiler command
set COMPILER=g++

rem Set the output executable name
set OUTPUT=../main.exe

rem List of .cpp files to compile
set SOURCES=../main.cpp ../src/entity/Branch/Branch.cpp ../src/entity/Employee/IEmployee.cpp  ../src/entity/Employee/EmployeeParticular.cpp ../src/entity/Employee/EmployeeProfessional.cpp ../src/entity/Employee/EmployeeCompany.cpp ../src/entity/Employee/Notificator.cpp ../src/repository/Repository.cpp ../src/service/EmployeeBranchService.cpp

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