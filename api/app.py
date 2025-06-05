from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
import subprocess
import json
import sys
import os
from fastapi.staticfiles import StaticFiles

app = FastAPI()

class Pergunta(BaseModel):
    pergunta: str

class Resposta(BaseModel):
    resposta: str
    explicacao: str

# Configuração para servir arquivos estáticos
app.mount("/static", StaticFiles(directory="../"), name="static")

@app.get("/")
async def index():
    return FileResponse("../index.html")

@app.post("/api/consulta")
async def fazer_pergunta(pergunta: Pergunta):
    try:
        # Executa o programa C++
        process = subprocess.Popen(
            ["../oraculo.exe"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        
        # Envia a pergunta para o C++
        stdout, stderr = process.communicate(input=pergunta.pergunta)
        
        # Processa a saída
        resposta = stdout.strip()
        explicacao = stderr.strip()
        
        return Resposta(
            resposta=resposta,
            explicacao=explicacao
        )
    except Exception as e:
        print(f"Erro ao executar o programa C++: {str(e)}", file=sys.stderr)
        raise HTTPException(status_code=500, detail="Erro ao processar a pergunta")

@app.get("/api/historico")
async def get_historico():
    try:
        # Executa o programa C++ para obter o histórico
        process = subprocess.Popen(
            ["../oraculo.exe", "--historico"],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate()
        
        return json.loads(stdout)
    except Exception as e:
        print(f"Erro ao obter histórico: {str(e)}", file=sys.stderr)
        raise HTTPException(status_code=500, detail="Erro ao obter histórico")

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=5000)
