@echo off

:: Compilar o código C++
echo Compilando o código C++...
g++ -std=c++17 -Wall -Wextra src/*.cpp -o oraculo.exe

:: Verificar se a compilação foi bem sucedida
if errorlevel 1 (
    echo Erro ao compilar o código C++
    exit /b 1
)

:: Iniciar o servidor Python do diretório api
echo Iniciando o servidor Python...
cd api
python app.py
