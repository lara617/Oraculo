@echo off
echo Compilando o código C++...
g++ -std=c++17 -Wall -Wextra src/*.cpp -o oraculo.exe

if %errorlevel% neq 0 (
    echo Erro ao compilar o código C++
    pause
    exit /b 1
)

echo Iniciando o servidor Python...
cd api
python app.py

echo Servidor iniciado. Acesse http://localhost:5000 no seu navegador.
pause
