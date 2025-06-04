#ifndef PERSONALIDADE_HPP
#define PERSONALIDADE_HPP

#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

enum class Humor {
    ALEGRE,
    MISTERIOSO,
    IRONICO,
    SOMBRIO,
    FILOSOFICO,
    BRINCALHAO,
    APOCALIPTICO
};

std::string humorParaTexto(Humor humor) {
    switch (humor) {
        case Humor::ALEGRE: return "alegre";
        case Humor::MISTERIOSO: return "misterioso";
        case Humor::IRONICO: return "irónico";
        case Humor::SOMBRIO: return "sombrio";
        case Humor::FILOSOFICO: return "filosófico";
        case Humor::BRINCALHAO: return "brincalhão";
        case Humor::APOCALIPTICO: return "apocalíptico";
        default: return "desconhecido";
    }
}

std::string introducoesAleatorias() {
    std::vector<std::string> intros = {
        " As energias alinham-se...",
        " O cosmos responde com sabedoria...",
        " Os astros murmuram algo enigmático...",
        " Sinos do destino tocam suavemente...",
        " Uma visão surge nas estrelas..."
    };
    return intros[rand() % intros.size()];
}

std::string respostaPorHumor(Humor humorAtual) {
    // Nota: std::srand(std::time(nullptr)) deve ser chamado uma vez no main.cpp

    std::vector<std::string> respostas;

    switch (humorAtual) {
        case Humor::ALEGRE:
            respostas = {
                "Tudo conspira a teu favor! ",
                "Sim, e com estilo! ",
                "Sem dúvida! Prepara-te para boas surpresas. ",
                "É o teu momento de brilhar! ",
                "Estás prestes a viver algo mágico. "
            };
            break;
        case Humor::MISTERIOSO:
            respostas = {
                "Os véus do futuro são turvos, mas algo se revela... ",
                "Shhh... o segredo está guardado nas entrelinhas. ",
                "A resposta está mais perto do que imaginas, porém oculta. ",
                "Nem tudo o que parece, é. Medita sobre isso. ",
                "Há mais coisas entre o céu e a terra do que sonha a tua filosofia. "
            };
            break;
        case Humor::IRONICO:
            respostas = {
                "Claro que sim... se porcos pudessem voar! ",
                "Oh, absolutamente! E eu sou o Coelhinho da Páscoa. ",
                "A probabilidade é tão alta quanto encontrar um político honesto. ",
                "Só se o teu desejo for que tudo corra exatamente ao contrário. ",
                "Sim, sim, continua a acreditar nisso. Faz bem à saúde mental. "
            };
            break;
        case Humor::SOMBRIO:
            respostas = {
                "As sombras adensam-se à tua volta... ",
                "Não vejo luz no fim deste túnel. Prepara-te. ",
                "O corvo grasna um mau presságio. ",
                "Há um frio na espinha que anuncia tempos difíceis. ",
                "A esperança é uma chama fraca perante a escuridão que se aproxima. "
            };
            break;
        case Humor::FILOSOFICO:
            respostas = {
                "Mas o que é realmente 'sim' ou 'não'? Reflete. ",
                "A questão não é a resposta, mas a jornada para a encontrar. ",
                "O universo é um eco das tuas próprias convicções. ",
                "Para cada porta que se fecha, uma janela se abre... ou talvez não. ",
                "A verdadeira sabedoria está em aceitar a incerteza. "
            };
            break;
        case Humor::BRINCALHAO:
            respostas = {
                "Só se disseres 'por favor' com açúcar! ",
                "Talvez sim, talvez não, talvez chova canivetes! ",
                "A minha bola de cristal está de férias, tenta outra vez! ",
                "Se a resposta for 'gelado', então sim, definitivamente! ",
                "E que tal uma piada em vez de uma profecia? "
            };
            break;
        case Humor::APOCALIPTICO:
            respostas = {
                "O FIM ESTÁ PRÓXIMO! Arrepende-te! ",
                "Os sinais são claros: o caos reinará. ",
                "Salva-te quem puder! O presságio é terrível! ",
                "As estrelas caem e o abismo chama... ",
                "Em breve, apenas o silêncio e as cinzas restarão. "
            };
            break;
        default:
            respostas = {"O Oráculo está confuso hoje... tenta mais tarde." };
            break;
    }

    if (respostas.empty()) {
        return "O Oráculo parece estar sem palavras para este humor!";
    }
    return respostas[rand() % respostas.size()];
}

#endif // PERSONALIDADE_HPP
