@echo off

set CC=g++
set CFLAGS=-Wall -Wextra -ggdb -Iinclude
set OUTPUT=build\plug.dll

if not exist build mkdir build

%CC% %CFLAGS% -shared src/plug.cpp -o %OUTPUT%
%CC% %CFLAGS% -o build\main.exe main.cpp