@echo off
echo Compiling Code
gcc.exe -g Source\*.c -o build\game.exe -IC:\MinGW\include -LC:\MinGW\lib -mwindows -lmingw32 -lSDL2main -lSDL2_image -lSDL2
echo Running game.exe
.\build\game.exe