@echo off
cd /d "%~dp0"

set "PATH=C:\msys64\mingw64\bin;C:\msys64\usr\bin;%SystemRoot%\system32"

set "BUILD_DIR=build-debug"
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"
cd "%BUILD_DIR%"

qmake ..\WindowsProjectFile.pro -spec win32-g++ CONFIG+=debug

echo Compiling project...
mingw32-make -j%NUMBER_OF_PROCESSORS%

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ---------------------------------------
    echo  Compilation Succss!
    echo ---------------------------------------
) else (
    echo.
    echo Compilation failed.
)
pause
