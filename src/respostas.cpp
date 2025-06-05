#include "../include/respostas.hpp"

// Função para converter um humor em texto
std::string humorParaTexto(Humor humor) {
    std::string texto;
    switch (humor) {
        case Humor::ALEGRE:
            texto = "alegre";
            break;
        case Humor::MISTERIOSO:
            texto = "misterioso";
            break;
        case Humor::IRONICO:
            texto = "irônico";
            break;
        case Humor::SOMBRO:
            texto = "sombrio";
            break;
        case Humor::FILOSOFICO:
            texto = "filosófico";
            break;
        case Humor::BRINCALHAO:
            texto = "brincalhão";
            break;
        case Humor::APOCALIPTICO:
            texto = "apocalíptico";
            break;
        default:
            texto = "desconhecido";
            break;
    }
    return texto;
}

std::string introducoesAleatorias() {
    std::vector<std::string> introducoes = {
        "O Oráculo digital te responde com sabedoria...",
        "A bola de cristal se manifesta...",
        "As estrelas te guiam através das palavras...",
        "O destino se revela através do Oráculo..."
    };
    return introducoes[rand() % introducoes.size()];
}

// Função para identificar o tema da pergunta baseado em palavras-chave
Tema identificarTema(const std::string& pergunta) {
    std::string perguntaLower = pergunta;
    std::transform(perguntaLower.begin(), perguntaLower.end(), perguntaLower.begin(), ::tolower);

    // Palavras-chave para cada tema
    std::vector<std::string> palavrasAmor = {"amor", "namoro", "relacionamento", "namorada", "namorado", "esposa", "esposo", "namorar", "casar"};
    std::vector<std::string> palavrasTrabalho = {"trabalho", "emprego", "carreira", "profissão", "cargo", "promover", "demissão", "salário", "chefia"};
    std::vector<std::string> palavrasSaude = {"saúde", "doença", "médico", "hospital", "remédio", "exame", "dieta", "exercício", "fitness"};
    std::vector<std::string> palavrasDinheiro = {"dinheiro", "finanças", "investimento", "economia", "gastos", "dívida", "herança", "sorteio", "loteria"};
    std::vector<std::string> palavrasAmigosFamilia = {"amigo", "família", "irmão", "irmã", "pai", "mãe", "filho", "filha", "namorada", "namorado", "relação"};
    std::vector<std::string> palavrasViagens = {"viagem", "viajar", "turismo", "passagem", "aeroporto", "hotel", "destino", "mochilão", "ferias"};
    std::vector<std::string> palavrasEstudos = {"estudo", "faculdade", "curso", "disciplina", "prova", "exame", "dissertação", "tese", "trabalho"};
    std::vector<std::string> palavrasEspiritualidade = {"espiritualidade", "fé", "religião", "meditação", "prece", "orar", "deus", "espírito", "alma"};

    // Verifica cada tema
    for (const auto& palavra : palavrasAmor) {
        if (perguntaLower.find(palavra) != std::string::npos) return Tema::AMOR;
    }
    for (const auto& palavra : palavrasTrabalho) {
        if (perguntaLower.find(palavra) != std::string::npos) return Tema::TRABALHO;
    }
    for (const auto& palavra : palavrasSaude) {
        if (perguntaLower.find(palavra) != std::string::npos) return Tema::SAUDE;
    }
    for (const auto& palavra : palavrasDinheiro) {
        if (perguntaLower.find(palavra) != std::string::npos) return Tema::DINHEIRO;
    }
    for (const auto& palavra : palavrasAmigosFamilia) {
        if (perguntaLower.find(palavra) != std::string::npos) return Tema::AMIGOS_FAMILIA;
    }
    for (const auto& palavra : palavrasViagens) {
        if (perguntaLower.find(palavra) != std::string::npos) return Tema::VIAGENS;
    }
    for (const auto& palavra : palavrasEstudos) {
        if (perguntaLower.find(palavra) != std::string::npos) return Tema::ESTUDOS;
    }
    for (const auto& palavra : palavrasEspiritualidade) {
        if (perguntaLower.find(palavra) != std::string::npos) return Tema::ESPIRITUALIDADE;
    }

    // Se não encontrou nenhuma palavra-chave específica, retorna GERAL
    return Tema::GERAL;
}

// Função para gerar uma resposta completa
RespostaComExplicacao gerarResposta(const std::string& pergunta) {
    // Identifica o tema da pergunta
    Tema tema = identificarTema(pergunta);
    
    // Gera um humor aleatório
    Humor humor = static_cast<Humor>(rand() % 8); // 8 é o número de humores diferentes
    
    // Gera a resposta usando a função do arquivo personalidade.cpp
    return respostaPorHumor(humor, tema);
}
