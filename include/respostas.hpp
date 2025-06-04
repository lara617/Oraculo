#ifndef RESPOSTAS_HPP
#define RESPOSTAS_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "personalidade.hpp"

std::string gerarResposta() {
    // Nota: std::srand(std::time(nullptr)) deve ser chamado uma vez no main.cpp

    std::vector<std::string> templates = {
        "O destino mostra que: ",
        "As estrelas sussurram: ",
        "Sinto nas entrelinhas do universo: ",
        "O Oráculo responde com mistério: ",
        "Interprete como quiser, mas "
    };

    // Lista de todos os humores disponíveis
    std::vector<Humor> todosOsHumores = {
        Humor::ALEGRE,
        Humor::MISTERIOSO,
        Humor::IRONICO,
        Humor::SOMBRIO,
        Humor::FILOSOFICO,
        Humor::BRINCALHAO,
        Humor::APOCALIPTICO
    };

    // Escolhe um humor aleatoriamente
    Humor humorEscolhido = todosOsHumores[rand() % todosOsHumores.size()];

    // Gera a resposta baseada no humor escolhido
    std::string respostaBase = respostaPorHumor(humorEscolhido);

    // Escolhe um template aleatoriamente
    std::string templateSelecionado = templates[rand() % templates.size()];

    return std::string("\n") + introducoesAleatorias() + "\n" + templateSelecionado + respostaBase + "\n";
}

#endif // RESPOSTAS_HPP
