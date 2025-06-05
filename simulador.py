# Este é um simulador do oraculo.exe
import sys
import random

# Ler a pergunta do stdin
pergunta = sys.stdin.read().strip()

# Escolher uma resposta aleatória
resposta = random.choice(respostas)

# Imprimir a resposta no stdout
print(resposta)
