#ifndef PERSONALIDADE_HPP
#define PERSONALIDADE_HPP

#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <random>
#include <chrono>

struct RespostaComExplicacao {
    std::string resposta;
    std::string explicacao;
};

bool is_empty(const std::string& str);
void replace_all(std::string& str, const std::string& from, const std::string& to);
std::string removerAcentos(std::string texto);

enum class Humor {
    ALEGRE,
    MISTERIOSO,
    IRONICO,
    SARCASTICO,
    SOMBRO,
    FILOSOFICO,
    BRINCALHAO,
    APOCALIPTICO
};

enum class Tema {
    AMOR,
    TRABALHO,
    SAUDE,
    DINHEIRO,
    AMIGOS_FAMILIA,
    VIAGENS,
    ESTUDOS,
    ESPIRITUALIDADE,
    GERAL
};

std::string humorParaTexto(Humor humor);
std::string introducoesAleatorias();
RespostaComExplicacao respostaPorHumor(Humor humorAtual, Tema temaAtual);

#endif // PERSONALIDADE_HPP
