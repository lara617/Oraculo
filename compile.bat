@echo off
setlocal

g++ -std=c++17 -Wall -Wextra src/main.cpp -o oraculo.exe

if errorlevel 1 (
    echo Erro ao compilar!
    pause
    exit /b 1
)

echo Compilação concluída com sucesso!
start oraculo.exe
