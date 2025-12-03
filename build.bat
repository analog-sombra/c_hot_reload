@echo off

set CC=gcc
set CFLAGS=-Wall -Wextra -ggdb -Iinclude
set OUTPUT=build\plug.dll

if not exist build mkdir build

%CC% %CFLAGS% -shared src/plug.c src/plug.def -o %OUTPUT%
%CC% %CFLAGS% -o build\main.exe main.c