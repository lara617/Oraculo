#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../include/respostas.hpp"
#include "../include/personalidade.hpp"
#include "../include/historico.hpp"
#include "../include/profecias_ascii.hpp"
#include "../include/ui.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << gerarProfeciaVisual() << "\n";
    std::cout << "Bem-vindo ao Oráculo Digital.\n";

    std::string pergunta;
    while (true) {
        std::cout << "\nFaz a tua pergunta (ou escreve 'sair'): ";
        std::getline(std::cin, pergunta);

        if (pergunta == "sair") break;

        salvarPergunta(pergunta);
        std::string respostaOraculo = gerarResposta(); // gerarResposta() agora lida com humor e formatação

        std::cout << "Resposta do Oráculo: " << respostaOraculo << "\n";
    }

    std::cout << "\nTemas mais comuns nas tuas perguntas:\n";
    auto temas = analisarTemas();
    int count = 0;
    for (auto it = temas.begin(); it != temas.end() && count < 3; ++it, ++count) {
        std::cout << "- " << it->first << " (" << it->second << ")\n";
    }

    std::cout << "\nO Oráculo despede-se. Que os ventos te guiem. 🌬️\n";
    return 0;
}
