// Arquivo: include/historico.hpp
#ifndef HISTORICO_HPP
#define HISTORICO_HPP

#include <fstream>
#include <string>
#include <map>
#include <sstream>

void salvarPergunta(const std::string& pergunta) {
    std::ofstream arquivo("historico.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << pergunta << std::endl;
        arquivo.close();
    }
}

std::map<std::string, int> analisarTemas() {
    std::ifstream arquivo("historico.txt");
    std::map<std::string, int> frequencia;
    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string palavra;
        while (iss >> palavra) {
            if (palavra.length() > 3) { // Ignorar palavras muito curtas
                ++frequencia[palavra];
            }
        }
    }

    return frequencia;
}

#endif
