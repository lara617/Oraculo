#ifndef RESPOSTAS_HPP
#define RESPOSTAS_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Para std::transform
#include "personalidade.hpp"

// Função para identificar o tema da pergunta com base em palavras-chave
Tema identificarTema(const std::string& pergunta);

// Função para gerar uma resposta completa
RespostaComExplicacao gerarResposta(const std::string& pergunta);

#endif // RESPOSTAS_HPP