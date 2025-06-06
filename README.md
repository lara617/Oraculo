# Oráculo Digital

Um sistema de oráculo digital com múltiplas personalidades e temas, desenvolvido como projeto para a disciplina de Programação de Sistemas.

## Descrição do Projeto

O Oráculo Digital é um sistema web que simula uma bola de cristal mística, capaz de responder perguntas sobre diferentes temas com múltiplas personalidades. O sistema utiliza uma combinação de C++, Python e tecnologias web para fornecer uma experiência interativa e mística aos usuários.

## Funcionalidades Principais

- Interface web moderna com fundo cósmico e efeitos visuais
- Sistema de múltiplas personalidades (alegre, sombrio, brincalhão, sarcástico)
- Respostas personalizadas para diferentes temas (amor, trabalho, saúde, etc.)
- Sistema de explicações para cada resposta
- Interface responsiva e intuitiva
- Efeitos visuais interativos

## Tecnologias Utilizadas

### Backend
- C++ (para processamento de lógica e respostas)
- Python (Flask) para o servidor web

### Frontend
- HTML5
- CSS3
- JavaScript

## Estrutura do Projeto

```
Oraculo/
├── app.py           # Servidor Flask
├── compile.bat      # Script de compilação C++
├── src/             # Código C++
│   ├── personalidade.cpp
│   └── personalidade.hpp
├── web/             # Frontend
│   ├── index.html
│   ├── style.css
│   └── script.js
└── README.md
```

## Como Executar

1. Certifique-se de ter Python 3.8+ instalado
2. Instale as dependências Python:
```bash
pip install flask flask-cors
```

3. Compile o código C++:
```bash
./compile.bat
```

4. Execute o servidor:
```bash
python app.py
```

5. Acesse o oráculo em `http://localhost:5000`

## Temas Disponíveis

- Amor
- Trabalho
- Família
- Saúde
- Dinheiro
- Viagens
- Estudos
- Amizade
- Espiritualidade

## Personalidades

- Alegre: Respostas otimistas e positivas
- Sombrio: Respostas misteriosas e profetas
- Brincalhão: Respostas divertidas e ligeiras
- Sarcástico: Respostas irônicas e bem-humoradas

## Características Especiais

- Sistema de detecção automática de temas
- Respostas aleatórias baseadas em personalidade
- Explicações detalhadas para cada resposta
- Interface visual cósmica com estrelas piscantes
- Efeitos de hover na bola de cristal
- Sistema de cores temático (azul místico)



