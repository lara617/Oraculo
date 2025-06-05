#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "../include/respostas.hpp"
#include "../include/personalidade.hpp"
#include "../include/historico.hpp"
#include "../include/profecias_ascii.hpp"
#include "../include/ui.hpp"

// Variável para armazenar a última resposta do Oráculo
RespostaComExplicacao ultimaResposta;
bool temResposta = false;

int main() {
    std::srand(std::time(nullptr)); // Inicializa o gerador de números aleatórios
    mudarCorTexto(0x0A); // Verde
    iniciarInterface();
    std::cout << gerarProfeciaVisual() << "\n";
    std::cout << "Bem-vindo ao Oráculo Digital.\n";

    std::string pergunta;
    while (true) {
        std::cout << "Pergunta ao Oráculo: ";
        std::getline(std::cin, pergunta);

        // Se o usuário digitar "sair", termina o programa
        if (pergunta == "sair") {
            finalizarInterface();
            return 0;
        }

        // Se o usuário perguntar "porque?", mostra a explicação da última resposta
        if (pergunta == "porque?" && temResposta) {
            mudarCorTexto(0x0E); // Amarelo
            std::cout << "Explicação: " << (ultimaResposta.explicacao.empty() ? "Porque cada resposta tem seu próprio mistério..." : ultimaResposta.explicacao) << std::endl;
            mudarCorTexto(0x0A); // Verde
            std::cout << "\n\n";
        } else {
            // Gera uma resposta baseada no humor atual e na pergunta
            ultimaResposta = gerarResposta(pergunta);
            temResposta = true;
            mudarCorTexto(0x0E); // Amarelo
            std::cout << ultimaResposta.resposta << std::endl;
            mudarCorTexto(0x0A); // Verde
            std::cout << "\n\n";
        }

        salvarPergunta(pergunta);
    }

    std::cout << "\nTemas mais comuns nas tuas perguntas:\n";
    auto temas = analisarTemas();
    int count = 0;
    for (auto it = temas.begin(); it != temas.end() && count < 3; ++it, ++count) {
        std::cout << "- " << it->first << " (" << it->second << ")\n";
    }

    std::cout << "\nO Oráculo despede-se. Que os ventos te guiem. \n";
    std::cout << "\nO Oráculo despede-se. Que os ventos te guiem. 🌬️\n";
    return 0;
}
