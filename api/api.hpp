#pragma once

#include <string>
#include <optional>
#include <vector>
#include "../include/personalidade.hpp"

// Estrutura para representar uma pergunta e sua resposta
struct PerguntaResposta {
    std::string pergunta;
    std::string resposta;
    std::string explicacao; // Usando std::string em vez de std::optional
};

// Estrutura para representar o histórico de perguntas
struct Historico {
    std::vector<PerguntaResposta> perguntas;
};

// Função para processar uma pergunta e retornar a resposta e explicação
PerguntaResposta processarPergunta(const std::string& pergunta, const Historico& historico);

// Função para obter o histórico de perguntas
Historico obterHistorico();
