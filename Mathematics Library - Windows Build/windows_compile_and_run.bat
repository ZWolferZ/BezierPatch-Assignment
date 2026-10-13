@echo off
cd /d "%~dp0"

where qmake >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: could not find qmake
	pause
    exit /b 1

)
for /f "delims=" %%I in ('where qmake') do set "QMAKE_PATH=%%~dpI"

:: Check and locate mingw32-make
where mingw32-make >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
        echo ERROR: could not find mingw32-make
    pause
    exit /b 1
)
for /f "delims=" %%I in ('where mingw32-make') do set "MAKE_PATH=%%~dpI"

set "PATH=%MAKE_PATH%;%QMAKE_PATH%;%SystemRoot%\system32"

echo Found qmake in: %QMAKE_PATH%
echo Found mingw32-make in: %MAKE_PATH%
echo.

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
cd debug
cls
testLibrary.exe
	
) else (
    echo.
    echo Compilation failed.
)



pause