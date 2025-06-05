#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../include/personalidade.hpp"

int main() {
    // Inicializar o gerador de números aleatórios
    std::srand(std::time(nullptr));

    // Ler a pergunta do stdin
    std::string pergunta;
    std::getline(std::cin, pergunta);

    // Determinar o humor e tema baseado na pergunta
    Humor humor = Humor::ALEGRE; // Por enquanto, usando humor alegre
    Tema tema = Tema::GERAL;     // Por enquanto, usando tema geral

    // Gerar resposta usando a função do personalidade.hpp
    RespostaComExplicacao resposta = respostaPorHumor(humor, tema);

    // Adicionar uma introdução aleatória
    std::string introducao = introducoesAleatorias();

    // Imprimir a resposta completa no stdout
    std::cout << introducao << std::endl;
    std::cout << resposta.resposta << std::endl;
    std::cout << "Explicação: " << resposta.explicacao << std::endl;

    return 0;
}
