@echo off

rem -------------------------
rem ENTER LOCATION OF GCC
set gccloc="C:\MinGW\bin\gcc.exe"
rem ------------------------

cls
echo Piko Engine Compiling Toolset (PECT)
echo Selected Compiler: GCC
echo -----------------------------------------
echo.
echo Select A Menu Option
echo --------------------
echo.
echo [1]: Compile All Examples
echo [2]: Update Examples (Requires Git)
echo [3]: Select Example to Compile
echo [4]: Help
echo [0]: Exit
echo.


set /p input=:
if /I "%input%"=="1" goto 1
if /I "%input%"=="2" goto 2
if /I "%input%"=="3" goto 3
if /I "%input%"=="4" goto 4
if /I "%input%"=="0" exit

:1
echo Compiling Window Example
%gccloc% -g ../src/Window/src/*.c -o ../build/window.exe -lopengl32 -lSDL2main -lSDL2
echo All Examples Compiled!
exit

:2
git clone https://github.com/PikoStudios/pikoengine-examples ..\src\
exit

:3
echo Only Example Avaliable: Window
%gccloc% -g ../src/Window/src/*.c -o ../build/window.exe -lopengl32 -lSDL2main -lSDL2 
echo Window Example Compiled!
exit

:4

echo Make sure the needed SDL2 Runtime DLLS are in the build folder and that you have GLFW Compiled
