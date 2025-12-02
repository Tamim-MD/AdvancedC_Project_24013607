@echo off

chcp 65001 >nul  & REM switch to UTF-8 for Korean output

cd "C:\Users\tamim\OneDrive\Documents\Advanced C Programming\Hanji - Korean Vocabulary Trainer"  & REM go to project folder

gcc -Wall -g src\main.c src\vocab.c -o hanji.exe  & REM compile the program

if %errorlevel% neq 0 (  REM if compilation failed
    echo.
    echo ❌ Compilation failed! Fix the errors above.
    pause
    exit /b
)

echo.  & REM blank line before running
echo === Running Hanji Korean Vocabulary Trainer ===
echo.

hanji.exe  & REM  run the compiled program

echo.
pause  & REM keep window open at the end
