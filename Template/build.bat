@echo off
set exe=.\output\%~n1.exe
if not exist output mkdir output
g++ %1 -o %exe% -std=c++17 -Wall -Wextra -g3 -O2 -D_GLIBCXX_DEBUG && (
    echo [build done to %exe%]
    %exe%
)