#include "api.hpp"
#include "../include/personalidade.hpp"
#include "../include/historico.hpp"

// Função para processar uma pergunta e retornar a resposta e explicação
PerguntaResposta processarPergunta(const std::string& pergunta, const Historico& historico) {
    // Se a última pergunta foi "porque?", retornamos a explicação
    if (!historico.perguntas.empty() && 
        historico.perguntas.back().pergunta == "porque?") {
        return {
            "porque?",
            "",
            historico.perguntas.back().explicacao
        };
    }

    // Processar a pergunta normalmente
    Tema tema = identificarTema(pergunta);
    Humor humor = static_cast<Humor>(rand() % 7); // Escolhe um humor aleatório
    
    RespostaComExplicacao resposta = respostaPorHumor(humor, tema);
    
    return {
        pergunta,
        resposta.resposta,
        resposta.explicacao
    };
}

// Função para obter o histórico de perguntas
Historico obterHistorico() {
    Historico historico;
    // Aqui você pode implementar a leitura do histórico do arquivo
    // Por enquanto, retornamos um histórico vazio
    return historico;
}
