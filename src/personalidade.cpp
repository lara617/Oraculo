// -*- coding: utf-8 -*-
#include "../include/personalidade.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
#include <iostream>
#include <iomanip>

// Função auxiliar para verificar se string está vazia
bool is_empty(const std::string& str) {
    return str.empty() || str.find_first_not_of(" \t\n\r") == std::string::npos;
}

// Função auxiliar para substituição de strings
void replace_all(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

// Função para remover acentos
std::string removerAcentos(std::string texto) {
    std::string result;
    for (char c : texto) {
        switch (c) {
            // Minúsculas
            case 'á': case 'à': case 'â': case 'ã': case 'ä':
                result += 'a'; break;
            case 'é': case 'è': case 'ê': case 'ë':
                result += 'e'; break;
            case 'í': case 'ì': case 'î': case 'ï':
                result += 'i'; break;
            case 'ó': case 'ò': case 'ô': case 'õ': case 'ö':
                result += 'o'; break;
            case 'ú': case 'ù': case 'û': case 'ü':
                result += 'u'; break;
            case 'ç':
                result += 'c'; break;
            // Maiúsculas
            case 'Á': case 'À': case 'Â': case 'Ã': case 'Ä':
                result += 'A'; break;
            case 'É': case 'È': case 'Ê': case 'Ë':
                result += 'E'; break;
            case 'Í': case 'Ì': case 'Î': case 'Ï':
                result += 'I'; break;
            case 'Ó': case 'Ò': case 'Ô': case 'Õ': case 'Ö':
                result += 'O'; break;
            case 'Ú': case 'Ù': case 'Û': case 'Ü':
                result += 'U'; break;
            case 'Ç':
                result += 'C'; break;
            default:
                result += c;
        }
    }
    return result;
}

// Função para lidar com codificação e remover acentos
std::string processarTexto(const std::string& texto) {
    std::string textoProcessado = removerAcentos(texto);
    std::transform(textoProcessado.begin(), textoProcessado.end(), textoProcessado.begin(), ::tolower);
    return textoProcessado;
}

// Função para converter humor para texto
std::string humorParaTexto(Humor humor) {
    switch (humor) {
        case Humor::ALEGRE:
            return "Alegre";
        case Humor::MISTERIOSO:
            return "Misterioso";
        case Humor::IRONICO:
            return "Ironicamente";
        default:
            return "Normal";
    }
}

// Função para converter tema para texto
std::string temaParaTexto(Tema tema) {
    switch (tema) {
        case Tema::AMOR:
            return "amor";
        case Tema::TRABALHO:
            return "trabalho";
        case Tema::SAUDE:
            return "saúde";
        case Tema::DINHEIRO:
            return "dinheiro";
        case Tema::AMIGOS_FAMILIA:
            return "amigos e família";
        case Tema::VIAGENS:
            return "viagens";
        case Tema::ESTUDOS:
            return "estudos";
        case Tema::ESPIRITUALIDADE:
            return "espiritualidade";
        default:
            return "desconhecido";
    }
}

// Função para gerar introduções aleatórias
std::string introducoesAleatorias() {
    static std::vector<std::string> introducoes = {
        "A bola de cristal mostra...",
        "O Oráculo revela...",
        "As estrelas indicam...",
        "O destino mostra...",
        "A sabedoria antiga revela..."
    };

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, introducoes.size() - 1);

    return introducoes[dis(gen)];
}

// Função principal para gerar respostas
RespostaComExplicacao respostaPorHumor(Humor humorAtual, Tema temaAtual) {
    RespostaComExplicacao resposta;
    std::string respostaTexto, explicacaoTexto;

    // Mapeamento de respostas por humor e tema
    switch (humorAtual) {
        case Humor::ALEGRE:
            switch (temaAtual) {
                case Tema::AMOR:
                    respostaTexto = "No amor, a felicidade sorri para ti! Prepara o coração!";
                    explicacaoTexto = "O amor é como um sorriso que ilumina o coração.";
                    break;
                case Tema::TRABALHO:
                    respostaTexto = "Sucesso profissional à vista! O teu esforço será recompensado com alegria!";
                    explicacaoTexto = "O trabalho duro é como uma semente que floresce com dedicação.";
                    break;
                case Tema::SAUDE:
                    respostaTexto = "Vitalidade e bem-estar! A tua saúde floresce!";
                    explicacaoTexto = "A saúde é como um jardim que precisa de cuidados diários.";
                    break;
                case Tema::DINHEIRO:
                    respostaTexto = "A prosperidade financeira sorri para ti! Boas notícias a caminho!";
                    explicacaoTexto = "O dinheiro é como uma semente que precisa ser plantada com sabedoria.";
                    break;
                case Tema::AMIGOS_FAMILIA:
                    respostaTexto = "Laços de amizade e família se fortalecem! Momentos felizes virão!";
                    explicacaoTexto = "Relações familiares são como árvores que crescem com o tempo.";
                    break;
                case Tema::VIAGENS:
                    respostaTexto = "Aventura chama! Uma viagem alegre e inesquecível te espera!";
                    explicacaoTexto = "Viagens são como livros que nos mostram novos horizontes.";
                    break;
                case Tema::ESTUDOS:
                    respostaTexto = "Sucesso nos estudos! O conhecimento adquirido trará grandes alegrias!";
                    explicacaoTexto = "O conhecimento é como uma luz que ilumina o caminho.";
                    break;
                case Tema::ESPIRITUALIDADE:
                    respostaTexto = "Paz interior e clareza espiritual te guiarão por caminhos iluminados e alegres!";
                    explicacaoTexto = "A espiritualidade é como uma estrela que guia nossos passos.";
                    break;
                default:
                    respostaTexto = "Tudo conspira a teu favor! ";
                    explicacaoTexto = "A vida é como um teatro onde somos os atores principais.";
                    break;
            }
            break;
        case Humor::MISTERIOSO:
            switch (temaAtual) {
                case Tema::AMOR:
                    respostaTexto = "No amor, segredos profundos e conexões inesperadas se revelam...";
                    explicacaoTexto = "O amor é um mistério que se desvenda aos poucos.";
                    break;
                case Tema::TRABALHO:
                    respostaTexto = "Na carreira, oportunidades ocultas surgirão. Mantém os olhos abertos.";
                    explicacaoTexto = "O sucesso profissional é como um tesouro escondido que precisa ser encontrado.";
                    break;
                case Tema::SAUDE:
                    respostaTexto = "A cura para o que te aflige pode estar onde menos esperas, investiga os mistérios do teu corpo.";
                    explicacaoTexto = "A saúde é um mistério que se revela através do equilíbrio.";
                    break;
                case Tema::DINHEIRO:
                    respostaTexto = "Finanças envoltas em mistério... segredos podem ser revelados.";
                    explicacaoTexto = "As finanças são como um labirinto que precisa ser decifrado.";
                    break;
                case Tema::AMIGOS_FAMILIA:
                    respostaTexto = "Relações com amigos e família guardam mistérios. Observa com atenção.";
                    explicacaoTexto = "As relações familiares são como quebra-cabeças que precisam ser montados.";
                    break;
                case Tema::VIAGENS:
                    respostaTexto = "Destinos misteriosos te aguardam. Uma viagem reveladora está por vir.";
                    explicacaoTexto = "As viagens são como portais para outros mundos.";
                    break;
                case Tema::ESTUDOS:
                    respostaTexto = "O conhecimento profundo está oculto. Procura nas entrelinhas dos teus estudos.";
                    explicacaoTexto = "O aprendizado é como uma jornada através de um labirinto.";
                    break;
                case Tema::ESPIRITUALIDADE:
                    respostaTexto = "Mistérios espirituais se revelam. Uma jornada de autoconhecimento te espera.";
                    explicacaoTexto = "A espiritualidade é um caminho que se desvenda aos poucos.";
                    break;
                default:
                    respostaTexto = "Mistérios do universo te guiam...";
                    explicacaoTexto = "A vida é um enigma que se desvenda aos poucos.";
                    break;
            }
            break;
        case Humor::IRONICO:
            switch (temaAtual) {
                case Tema::AMOR:
                    respostaTexto = "Ah, o amor... claro que vai dar certo. Tão certo quanto o sol nascer no oeste.";
                    explicacaoTexto = "O amor é como um sonho que nunca acaba.";
                    break;
                case Tema::TRABALHO:
                    respostaTexto = "Claro, é só você trabalhar 24 horas por dia que vai dar certo.";
                    explicacaoTexto = "O sucesso profissional é como uma montanha que nunca diminui.";
                    break;
                case Tema::SAUDE:
                    respostaTexto = "Ah, saúde? Claro! Só precisa de 8 horas de sono e uma dieta perfeita.";
                    explicacaoTexto = "A saúde é como um manual de instruções que ninguém lê.";
                    break;
                case Tema::DINHEIRO:
                    respostaTexto = "Ah, claro! Dinheiro? É só você ganhar na loteria.";
                    explicacaoTexto = "As finanças são como um jogo de azar que ninguém ganha.";
                    break;
                case Tema::AMIGOS_FAMILIA:
                    respostaTexto = "Ah, claro! Família feliz? É só você ser perfeito.";
                    explicacaoTexto = "As relações familiares são como um conto de fadas que ninguém vive.";
                    break;
                case Tema::VIAGENS:
                    respostaTexto = "Ah, claro! Viagem? É só você ganhar na loteria e ter tempo livre.";
                    explicacaoTexto = "As viagens são como sonhos que nunca se realizam.";
                    break;
                case Tema::ESTUDOS:
                    respostaTexto = "Ah, claro! Sucesso nos estudos? É só você estudar 24 horas por dia.";
                    explicacaoTexto = "O aprendizado é como um livro que ninguém lê.";
                    break;
                case Tema::ESPIRITUALIDADE:
                    respostaTexto = "Ah, claro! Paz interior? É só você ser um monge budista.";
                    explicacaoTexto = "A espiritualidade é como um caminho que ninguém encontra.";
                    break;
                default:
                    respostaTexto = "Ah, claro! Tudo vai dar certo. Como sempre.";
                    explicacaoTexto = "A vida é como um sonho que nunca acaba.";
                    break;
            }
            break;
        case Humor::SOMBRO:
            switch (temaAtual) {
                case Tema::AMOR:
                    respostaTexto = "Cuidado com o coração... o amor pode ser uma armadilha.";
                    explicacaoTexto = "O amor é como uma tempestade que pode destruir.";
                    break;
                case Tema::TRABALHO:
                    respostaTexto = "Na carreira, prepare-se para tempos sombrios.";
                    explicacaoTexto = "O sucesso profissional é como uma sombra que nos persegue.";
                    break;
                case Tema::SAUDE:
                    respostaTexto = "A saúde pode ser uma ilusão...";
                    explicacaoTexto = "A saúde é como um castelo de cartas que pode desmoronar.";
                    break;
                case Tema::DINHEIRO:
                    respostaTexto = "As finanças podem ser um pesadelo...";
                    explicacaoTexto = "O dinheiro é como um fantasma que nos assombra.";
                    break;
                case Tema::AMIGOS_FAMILIA:
                    respostaTexto = "Relações podem ser sombras que nos perseguem...";
                    explicacaoTexto = "As relações familiares são como fantasmas que nos assombram.";
                    break;
                case Tema::VIAGENS:
                    respostaTexto = "Viagens podem ser caminhos sombrios...";
                    explicacaoTexto = "As viagens são como caminhos que nos levam ao desconhecido.";
                    break;
                case Tema::ESTUDOS:
                    respostaTexto = "O conhecimento pode ser uma armadilha...";
                    explicacaoTexto = "O aprendizado é como um labirinto sem saída.";
                    break;
                case Tema::ESPIRITUALIDADE:
                    respostaTexto = "A espiritualidade pode ser um caminho sombrio...";
                    explicacaoTexto = "A espiritualidade é como uma jornada através da escuridão.";
                    break;
                default:
                    respostaTexto = "Tempos sombrios se aproximam...";
                    explicacaoTexto = "A vida é como uma tempestade que se aproxima.";
                    break;
            }
            break;
        case Humor::FILOSOFICO:
            switch (temaAtual) {
                case Tema::AMOR:
                    respostaTexto = "O amor é a essência da existência... reflete sobre isso.";
                    explicacaoTexto = "O amor é como um espelho que reflete nossa alma.";
                    break;
                case Tema::TRABALHO:
                    respostaTexto = "O trabalho é uma busca pela realização...";
                    explicacaoTexto = "O sucesso profissional é como uma montanha que nunca tem fim.";
                    break;
                case Tema::SAUDE:
                    respostaTexto = "A saúde é um equilíbrio precário...";
                    explicacaoTexto = "A saúde é como um barco em alto mar.";
                    break;
                case Tema::DINHEIRO:
                    respostaTexto = "O dinheiro é uma ilusão...";
                    explicacaoTexto = "As finanças são como um sonho que nunca acaba.";
                    break;
                case Tema::AMIGOS_FAMILIA:
                    respostaTexto = "As relações são como laços invisíveis...";
                    explicacaoTexto = "As relações familiares são como correntes que nos unem.";
                    break;
                case Tema::VIAGENS:
                    respostaTexto = "As viagens são uma jornada interior...";
                    explicacaoTexto = "As viagens são como caminhos que nos levam para dentro de nós.";
                    break;
                case Tema::ESTUDOS:
                    respostaTexto = "O conhecimento é uma busca sem fim...";
                    explicacaoTexto = "O aprendizado é como um rio que nunca para.";
                    break;
                case Tema::ESPIRITUALIDADE:
                    respostaTexto = "A espiritualidade é um caminho sem volta...";
                    explicacaoTexto = "A espiritualidade é como uma jornada sem destino.";
                    break;
                default:
                    respostaTexto = "A vida é uma jornada filosófica...";
                    explicacaoTexto = "A vida é como um livro que nunca termina.";
                    break;
            }
            break;
        case Humor::BRINCALHAO:
            switch (temaAtual) {
                case Tema::AMOR:
                    respostaTexto = "Ah, o amor... é como um jogo de cartas!";
                    explicacaoTexto = "O amor é como um sorvete que derrete rápido.";
                    break;
                case Tema::TRABALHO:
                    respostaTexto = "Trabalho? Ah, é só você fingir que está trabalhando!";
                    explicacaoTexto = "O sucesso profissional é como um jogo de cartas.";
                    break;
                case Tema::SAUDE:
                    respostaTexto = "Ah, saúde? É só você tomar um remédio mágico!";
                    explicacaoTexto = "A saúde é como um truque de mágica.";
                    break;
                case Tema::DINHEIRO:
                    respostaTexto = "Ah, dinheiro? É só você ganhar na loteria!";
                    explicacaoTexto = "As finanças são como um jogo de azar.";
                    break;
                case Tema::AMIGOS_FAMILIA:
                    respostaTexto = "Ah, família feliz? É só você contar uma piada!";
                    explicacaoTexto = "As relações familiares são como um show de comédia.";
                    break;
                case Tema::VIAGENS:
                    respostaTexto = "Ah, viagem? É só você fechar os olhos e abrir em outro lugar!";
                    explicacaoTexto = "As viagens são como um passe de mágica.";
                    break;
                case Tema::ESTUDOS:
                    respostaTexto = "Ah, estudos? É só você decorar tudo!";
                    explicacaoTexto = "O aprendizado é como um truque de memória.";
                    break;
                case Tema::ESPIRITUALIDADE:
                    respostaTexto = "Ah, espiritualidade? É só você meditar!";
                    explicacaoTexto = "A espiritualidade é como uma viagem mágica.";
                    break;
                default:
                    respostaTexto = "Ah, claro! Tudo vai dar certo!";
                    explicacaoTexto = "A vida é como um show de comédia.";
                    break;
            }
            break;
        case Humor::APOCALIPTICO:
            switch (temaAtual) {
                case Tema::AMOR:
                    respostaTexto = "O amor está condenado... prepare-se para o fim.";
                    explicacaoTexto = "O amor é como um vulcão que pode explodir.";
                    break;
                case Tema::TRABALHO:
                    respostaTexto = "A carreira está prestes a explodir...";
                    explicacaoTexto = "O sucesso profissional é como uma bomba-relógio.";
                    break;
                case Tema::SAUDE:
                    respostaTexto = "A saúde está em perigo...";
                    explicacaoTexto = "A saúde é como um edifício prestes a desmoronar.";
                    break;
                case Tema::DINHEIRO:
                    respostaTexto = "As finanças estão em colapso...";
                    explicacaoTexto = "O dinheiro é como uma torre de cartas prestes a cair.";
                    break;
                case Tema::AMIGOS_FAMILIA:
                    respostaTexto = "As relações estão em crise...";
                    explicacaoTexto = "As relações familiares são como um terremoto.";
                    break;
                case Tema::VIAGENS:
                    respostaTexto = "As viagens estão proibidas...";
                    explicacaoTexto = "As viagens são como um portal que se fecha.";
                    break;
                case Tema::ESTUDOS:
                    respostaTexto = "O conhecimento está em perigo...";
                    explicacaoTexto = "O aprendizado é como um vulcão prestes a explodir.";
                    break;
                case Tema::ESPIRITUALIDADE:
                    respostaTexto = "A espiritualidade está em crise...";
                    explicacaoTexto = "A espiritualidade é como um terremoto que abala a alma.";
                    break;
                default:
                    respostaTexto = "O mundo está em colapso...";
                    explicacaoTexto = "A vida é como um apocalipse que se aproxima.";
                    break;
            }
            break;
        default:
            respostaTexto = "Desculpe, não consigo responder a essa pergunta no momento.";
            explicacaoTexto = "Porque o universo às vezes precisa de um momento de silêncio...";
            break;
    }

    resposta.resposta = introducoesAleatorias() + "\n" + processarTexto(respostaTexto);
    resposta.explicacao = processarTexto(explicacaoTexto);

    return resposta;
    resposta.resposta = respostas[rand() % respostas.size()];
}
if (!explicacoes.empty()) {
    resposta.explicacao = explicacoes[rand() % explicacoes.size()];
}

return resposta;
}
                respostas = {"Dinheiro? Claro, vai chover notas... quadradas, talvez."};
                break;
            case Tema::AMIGOS_FAMILIA:
                respostas = {"Harmonia familiar? Tão provável quanto um gato pedir desculpas."};
                break;
            case Tema::VIAGENS:
                respostas = {"Viajar? Sim, para a esquina e voltar. E já é muito."};
                break;
            case Tema::ESTUDOS:
                respostas = {"Aprender algo novo? Claro, se o cérebro não decidir tirar férias permanentes."};
                break;
            case Tema::ESPIRITUALIDADE:
                respostas = {"Iluminação espiritual? Talvez se tropeçares num interruptor divino."};
                break;
        }
        break;
    case Humor::SOMBRIO:
        switch (temaAtual) {
            case Tema::AMOR:
                respostas = {"No amor, apenas vejo corações partidos e lágrimas na escuridão que se avizinha."};
                break;
            case Tema::TRABALHO:
                respostas = {"O teu caminho profissional está envolto em névoa e desespero. Cuidado."};
                break;
            case Tema::SAUDE:
                respostas = {"A doença espreita nas sombras, a vitalidade esvai-se como areia entre os dedos."};
                break;
            default: // Tema::GERAL
                respostas = {
                    "As sombras adensam-se à tua volta... ",
                    "Não vejo luz no fim deste túnel. Prepara-te. "
                };
                break;
            case Tema::DINHEIRO:
                respostas = {"A ruína financeira paira como um abutre faminto. Cuidado."};
                break;
            case Tema::AMIGOS_FAMILIA:
                respostas = {"Conflitos e tristezas obscurecem os laços familiares e de amizade."};
                break;
            case Tema::VIAGENS:
                respostas = {"Viagens trarão apenas perigos e desilusões. O lar é o único refúgio."};
                break;
            case Tema::ESTUDOS:
                respostas = {"O estudo será um fardo pesado, e o conhecimento, uma miragem sombria."};
                break;
            case Tema::ESPIRITUALIDADE:
                respostas = {"Um vazio espiritual te consome, a escuridão da alma parece não ter fim."};
                break;
        }
        break;
    case Humor::FILOSOFICO:
        switch (temaAtual) {
            case Tema::AMOR:
                respostas = {"O que é o amor, senão a busca incessante por um reflexo da nossa própria alma? Pondera."};
                break;
            case Tema::TRABALHO:
                respostas = {"O sucesso no trabalho é uma construção da mente ou uma realidade tangível? A resposta está em ti."};
                break;
            case Tema::SAUDE:
                respostas = {"A saúde do corpo é apenas um fragmento da saúde do espírito. O que procuras curar verdadeiramente?"};
                break;
            default: // Tema::GERAL
                respostas = {
                    "Mas o que é realmente 'sim' ou 'não'? Reflete. ",
                    "A questão não é a resposta, mas a jornada para a encontrar. "
                };
                break;
            case Tema::DINHEIRO:
                respostas = {"O que é o dinheiro, senão uma ilusão de valor? A verdadeira riqueza está noutro lugar."};
                break;
            case Tema::AMIGOS_FAMILIA:
                respostas = {"São os laços que nos definem, ou somos nós que definimos os laços? Pensa nisso."};
                break;
            case Tema::VIAGENS:
                respostas = {"Viajar é mover o corpo ou expandir a mente? Eis a questão filosófica."};
                break;
            case Tema::ESTUDOS:
                respostas = {"Aprender é acumular factos ou desvendar a verdade sobre si mesmo? Medita."};
                break;
            case Tema::ESPIRITUALIDADE:
                respostas = {"A busca espiritual é um caminho ou um estado de ser? A resposta reside no silêncio."};
                break;
        }
        break;
    case Humor::BRINCALHAO:
        switch (temaAtual) {
            case Tema::AMOR:
                respostas = {"Amor? Ui! A minha bola de cristal ficou corada! Tenta perguntar a um biscoito da sorte!"};
                break;
            case Tema::TRABALHO:
                respostas = {"Trabalho, trabalho... que tal uma pausa para um café? Depois vemos isso, talvez!"};
                break;
            case Tema::SAUDE:
                respostas = {"Saúde? Come uma maçã por dia! Ou talvez duas, só para garantir a diversão!"};
                break;
            default: // Tema::GERAL
                respostas = {
                    "Só se disseres 'por favor' com açúcar! ",
                    "Talvez sim, talvez não, talvez chova canivetes! "
                };
                break;
            case Tema::DINHEIRO:
                respostas = {"Dinheirama? Só se encontrares o pote de ouro no fim do arco-íris de um duende contabilista!"};
                break;
            case Tema::AMIGOS_FAMILIA:
                respostas = {"Amigos e família? Claro! Desde que tragam bolo e presentes!"};
                break;
            case Tema::VIAGENS:
                respostas = {"Viajar? Só se for numa vassoura mágica com GPS integrado e Wi-Fi grátis!"};
                break;
            case Tema::ESTUDOS:
                respostas = {"Estudar? Que tal uma sesta mágica que te ensine tudo por osmose?"};
                break;
            case Tema::ESPIRITUALIDADE:
                respostas = {"Iluminação? Acendi uma lanterna aqui, serve? É bem brilhante!"};
                break;
        }
        break;
    case Humor::APOCALIPTICO:
        switch (temaAtual) {
            case Tema::AMOR:
                respostas = {"AMOR? NESTE CAOS IMINENTE? Procura antes um bunker!"};
                break;
            case Tema::TRABALHO:
                respostas = {"TRABALHO? O MUNDO ESTÁ A ACABAR! De que serve o dinheiro agora?"};
                break;
            case Tema::SAUDE:
                respostas = {"SAÚDE? Impossível! A PESTE NEGRA CÓSMICA CONSUME TUDO!"};
                break;
            default: // Tema::GERAL
                respostas = {
                    "O FIM ESTÁ PRÓXIMO! Arrepende-te! ",
                    "Os sinais são claros: o caos reinará. "
                };
                break;
            case Tema::DINHEIRO:
                respostas = {"DINHEIRO? SERÁ PAPEL QUEIMADO NO APOCALIPSE FINANCEIRO!"};
                break;
            case Tema::AMIGOS_FAMILIA:
                respostas = {"LAÇOS FAMILIARES? SERÃO DESFEITOS NO TURBILHÃO DO FIM DOS TEMPOS!"};
                break;
            case Tema::VIAGENS:
                respostas = {"VIAJAR? SÓ SE FOR PARA O CENTRO DO ESQUECIMENTO ETERNO!"};
                break;
            case Tema::ESTUDOS:
                respostas = {"CONHECIMENTO? CINZAS AO VENTO PERANTE A IGNORÂNCIA CÓSMICA FINAL!"};
                break;
            case Tema::ESPIRITUALIDADE:
                respostas = {"ESPÍRITO? DESVANECERÁ NO VAZIO QUANDO AS ESTRELAS NEGRAS SE ALINHAREM!"};
                break;
        }
        break;
    default:
        switch (temaAtual) {
            // Adicionar respostas padrão por tema para o humor default, se necessário
            default:
                respostas = {"O Oráculo está confuso sobre este tema e humor... tenta mais tarde." };

if (respostas.empty()) {
    // Fallback mais genérico se um tema específico não tiver resposta para um humor
    RespostaComExplicacao resposta;
    resposta.resposta = "O Oráculo pondera sobre a tua questão... a resposta ainda não está clara.";
    resposta.explicacao = "";
    return resposta;
}

RespostaComExplicacao resposta;
resposta.resposta = respostas[rand() % respostas.size()];

// ...
    case Humor::ALEGRE:
        switch (temaAtual) {
            case Tema::AMOR:
                std::vector<std::string> expAmor = {
                    "Porque o amor é uma força que move montanhas e traz luz aos corações mais escuros!",
                    "Porque o amor é como um sol que aquece até os cantos mais frios da alma!",
                    "Porque o amor é uma dança que nos faz flutuar acima das dificuldades!",
                    "Porque o amor é como um rio que nos leva por caminhos inesperados!",
                    "Porque o amor é uma pintura que ganha cores com cada novo amanhecer!"
                };
                resposta.explicacao = expAmor[rand() % expAmor.size()];
                break;
            case Tema::TRABALHO:
                std::vector<std::string> expTrabalho = {
                    "Porque o trabalho duro é a chave para abrir as portas do sucesso e da realização pessoal!",
                    "Porque cada esforço no trabalho é um passo em direção aos nossos sonhos!",
                    "Porque o trabalho é como um jardim: quanto mais cultivamos, mais floresce!",
                    "Porque cada tarefa concluída é uma vitória que nos fortalece!",
                    "Porque o trabalho é como uma sinfonia: cada nota tem seu lugar!"
                };
        break;
    case Tema::TRABALHO:
        std::vector<std::string> expTrabalho = {
            "Porque o trabalho é como café: você precisa dele, mas não gosta do sabor...",
            "Porque o trabalho é como aquele filme que você sabe que é ruim, mas assiste mesmo assim...",
            "Porque o trabalho é como aquele tio chato que aparece nas festas...",
            "Porque o trabalho é como aquele relatório que você promete fazer, mas sempre deixa para depois...",
            "Porque o trabalho é como aquele projeto que você jura que vai começar, mas nunca começa..."
        };
        resposta.explicacao = expTrabalho[rand() % expTrabalho.size()];
    case Humor::MISTERIOSO:
        switch (temaAtual) {
            case Tema::AMOR:
                resposta.explicacao = "Porque o amor é um mistério que desafia a razão e nos leva a caminhos inesperados...";
                break;
            case Tema::TRABALHO:
                resposta.explicacao = "Porque o trabalho é um enigma que revela tanto sobre nós quanto sobre o mundo ao nosso redor...";
                break;
            case Tema::SAUDE:
                resposta.explicacao = "Porque a saúde é um mistério que envolve equilíbrio, energia e forças invisíveis...";
                break;
            case Tema::DINHEIRO:
                resposta.explicacao = "Porque o dinheiro é uma força enigmática que pode criar tanto prosperidade quanto desafios...";
                break;
            case Tema::AMIGOS_FAMILIA:
                resposta.explicacao = "Porque os laços de amizade e família são laços invisíveis que nos guiam por caminhos desconhecidos...";
                break;
            case Tema::VIAGENS:
                resposta.explicacao = "Porque viajar é uma jornada que revela mistérios tanto do mundo exterior quanto do nosso interior...";
                break;
            case Tema::ESTUDOS:
                resposta.explicacao = "Porque o conhecimento é um labirinto de descobertas e enigmas que nos desafiam a cada passo...";
                break;
            case Tema::ESPIRITUALIDADE:
                resposta.explicacao = "Porque a espiritualidade é um caminho misterioso que nos leva a profundezas desconhecidas da alma...";
                break;
            default: // Tema::GERAL
                resposta.explicacao = "Porque cada resposta esconde um mistério maior que nos desafia a refletir sobre o verdadeiro sentido das coisas...";
                break;
        }
        break;
    case Humor::SARCASTICO:
        switch (temaAtual) {
            case Tema::AMOR:
                std::vector<std::string> expAmor = {
                    "Porque o amor é como um videogame: você perde, mas sempre quer jogar de novo...",
                    "Porque o amor é como aquele filme que você odeia, mas assiste toda semana...",
                    "Porque o amor é como aquele chocolate que engorda, mas você não consegue resistir...",
                    "Porque o amor é como aquele livro que você jura que vai ler, mas nunca começa...",
                    "Porque o amor é como aquele café da manhã saudável que você promete fazer, mas sempre pede delivery..."
                };
                resposta.explicacao = expAmor[rand() % expAmor.size()];
                break;
            case Tema::TRABALHO:
                std::vector<std::string> expTrabalho = {
                    "Porque o trabalho é como café: você precisa dele, mas não gosta do sabor...",
                    "Porque o trabalho é como aquele filme que você sabe que é ruim, mas assiste mesmo assim...",
                    "Porque o trabalho é como aquele tio chato que aparece nas festas...",
                    "Porque o trabalho é como aquele relatório que você promete fazer, mas sempre deixa para depois...",
                    "Porque o trabalho é como aquele projeto que você jura que vai começar, mas nunca começa..."
                };
                resposta.explicacao = expTrabalho[rand() % expTrabalho.size()];
                break;
            case Tema::SAUDE:
                std::vector<std::string> expSaude = {
                    "Porque a saúde é como aquele amigo que só aparece quando você precisa dele...",
                    "Porque a saúde é como aquele exercício que você sabe que deve fazer, mas não faz...",
                    "Porque a saúde é como aquele almoço saudável que você promete fazer, mas nunca faz...",
                    "Porque a saúde é como aquele check-up que você jura que vai fazer, mas sempre adia...",
                    "Porque a saúde é como aquele regime que você promete começar, mas nunca começa..."
                };
                resposta.explicacao = expSaude[rand() % expSaude.size()];
                break;
            case Tema::DINHEIRO:
                std::vector<std::string> expDinheiro = {
                    "Porque o dinheiro é como um cão: você pensa que o tem, mas ele te tem...",
                    "Porque o dinheiro é como aquele amigo rico que só aparece quando precisa de algo...",
                    "Porque o dinheiro é como aquele salário que sempre acaba antes do mês...",
                    "Porque o dinheiro é como aquele investimento que você jura que vai fazer, mas nunca faz...",
                    "Porque o dinheiro é como aquele orçamento que você promete seguir, mas nunca segue..."
                };
                resposta.explicacao = expDinheiro[rand() % expDinheiro.size()];
                break;
            case Tema::AMIGOS_FAMILIA:
                std::vector<std::string> expAmigos = {
                    "Porque amigos e família são como aqueles filmes que você assiste só porque estão na TV...",
                    "Porque amigos e família são como aqueles compromissos que você não quer, mas precisa cumprir...",
                    "Porque amigos e família são como aqueles planos que você faz, mas nunca realiza...",
                    "Porque amigos e família são como aqueles telefonemas que você jura que vai fazer, mas nunca faz...",
                    "Porque amigos e família são como aquele encontro que você promete, mas sempre adia..."
                };
                resposta.explicacao = expAmigos[rand() % expAmigos.size()];
                break;
            case Tema::VIAGENS:
                std::vector<std::string> expViagens = {
                    "Porque viajar é como comer: você pensa que vai gostar, mas sempre acaba com dor de barriga...",
                    "Porque viajar é como aquele passeio que você planeja, mas nunca acontece...",
                    "Porque viajar é como aquele destino que você sonha, mas nunca alcança...",
                    "Porque viajar é como aquele voo que você jura que vai pegar, mas sempre perde...",
                    "Porque viajar é como aquele mochilão que você promete fazer, mas nunca faz..."
                };
                resposta.explicacao = expViagens[rand() % expViagens.size()];
                break;
            case Tema::ESTUDOS:
                std::vector<std::string> expEstudos = {
                    "Porque estudar é como escalar uma montanha: você pensa que chegou ao topo, mas é só o começo...",
                    "Porque estudar é como aquele livro que você compra, mas nunca lê...",
                    "Porque estudar é como aquele curso que você começa, mas nunca termina...",
                    "Porque estudar é como aquele projeto que você jura que vai fazer, mas nunca faz...",
                    "Porque estudar é como aquele trabalho que você promete entregar, mas sempre entrega atrasado..."
                };
                resposta.explicacao = expEstudos[rand() % expEstudos.size()];
                break;
            case Tema::ESPIRITUALIDADE:
                std::vector<std::string> expEspiritualidade = {
                    "Porque a espiritualidade é como um elevador: você acha que vai para cima, mas acaba no porão...",
                    "Porque a espiritualidade é como aquele livro de autoajuda que você compra, mas nunca lê...",
                    "Porque a espiritualidade é como aquele retiro que você planeja, mas nunca vai...",
                    "Porque a espiritualidade é como aquele mantra que você jura que vai repetir, mas nunca repete...",
                    "Porque a espiritualidade é como aquele curso de meditação que você promete fazer, mas nunca faz..."
                };
                resposta.explicacao = expEspiritualidade[rand() % expEspiritualidade.size()];
                break;
    case Humor::SOMBRIO:
        switch (temaAtual) {
            case Tema::AMOR:
                resposta.explicacao = "Porque o amor é uma sombra que nos persegue, mesmo quando tentamos fugir...";
                break;
            case Tema::TRABALHO:
                resposta.explicacao = "Porque o trabalho é uma prisão de papelada e prazos que nunca termina...";
                break;
            case Tema::SAUDE:
                resposta.explicacao = "Porque a saúde é um castelo de cartas que pode desmoronar a qualquer momento...";
                break;
            case Tema::DINHEIRO:
                resposta.explicacao = "Porque o dinheiro é uma ilusão que nos mantém acorrentados a uma roda sem fim...";
                break;
            case Tema::AMIGOS_FAMILIA:
                resposta.explicacao = "Porque os laços de amizade e família são cadeias invisíveis que nos prendem a um destino comum...";
                break;
            case Tema::VIAGENS:
                resposta.explicacao = "Porque viajar é uma fuga momentânea de uma realidade que sempre nos espera...";
                break;
            case Tema::ESTUDOS:
                resposta.explicacao = "Porque o conhecimento é um caminho sem volta que nos leva cada vez mais fundo...";
                break;
            case Tema::ESPIRITUALIDADE:
                resposta.explicacao = "Porque a espiritualidade é um abismo que nos consome e nos transforma...";
                break;
            default: // Tema::GERAL
                resposta.explicacao = "Porque cada resposta é uma janela para um abismo mais profundo...";
                break;
        }
        break;
    case Humor::FILOSOFICO:
        switch (temaAtual) {
            case Tema::AMOR:
                resposta.explicacao = "Porque o amor é uma projeção do nosso eu mais profundo, refletido no espelho do outro...";
                break;
            case Tema::TRABALHO:
                resposta.explicacao = "Porque o trabalho é uma expressão do nosso propósito, uma manifestação do nosso ser...";
                break;
            case Tema::SAUDE:
                resposta.explicacao = "Porque a saúde é um equilíbrio delicado entre corpo, mente e espírito...";
                break;
            case Tema::DINHEIRO:
                resposta.explicacao = "Porque o dinheiro é uma medida artificial do valor, que muitas vezes confunde o essencial...";
                break;
            case Tema::AMIGOS_FAMILIA:
                resposta.explicacao = "Porque os laços de amizade e família são teias do destino que nos conectam ao universo...";
                break;
            case Tema::VIAGENS:
                resposta.explicacao = "Porque viajar é uma metáfora da jornada interior, uma busca pelo desconhecido...";
                break;
            case Tema::ESTUDOS:
                resposta.explicacao = "Porque o conhecimento é um espelho que reflete a nossa ignorância e nos leva a questionar...";
                break;
            case Tema::ESPIRITUALIDADE:
                resposta.explicacao = "Porque a espiritualidade é uma ponte entre o visível e o invisível, entre o finito e o infinito...";
                break;
            default: // Tema::GERAL
                resposta.explicacao = "Porque cada resposta é uma porta para uma nova questão, um caminho para o desconhecido...";
                break;
        }
        break;
    case Humor::BRINCALHAO:
        switch (temaAtual) {
            case Tema::AMOR:
                resposta.explicacao = "Porque o amor é como aquele jogo de adivinhação que você sempre perde...";
                break;
            case Tema::TRABALHO:
                resposta.explicacao = "Porque o trabalho é como comer brócolis: você sabe que deve, mas não quer...";
                break;
            case Tema::SAUDE:
                resposta.explicacao = "Porque a saúde é como aquele alarme que toca quando você menos espera...";
                break;
            case Tema::DINHEIRO:
                resposta.explicacao = "Porque o dinheiro é como aquele amigo que sempre aparece quando você tem...";
                break;
            case Tema::AMIGOS_FAMILIA:
                resposta.explicacao = "Porque amigos e família são como aqueles filmes que você sempre quer ver de novo...";
                break;
            case Tema::VIAGENS:
                resposta.explicacao = "Porque viajar é como comer sorvete: você pensa que vai ser rápido, mas sempre demora...";
                break;
            case Tema::ESTUDOS:
                resposta.explicacao = "Porque estudar é como escalar uma montanha: você pensa que chegou ao topo, mas é só o começo...";
                break;
            case Tema::ESPIRITUALIDADE:
                resposta.explicacao = "Porque a espiritualidade é como um elevador: você acha que vai para cima, mas acaba no porão...";
                break;
            default: // Tema::GERAL
                resposta.explicacao = "Porque a vida é como um sanduíche: você pensa que sabe o que vai encontrar, mas sempre tem uma surpresa...";
                break;
        }
        break;
    case Humor::APOCALIPTICO:
        switch (temaAtual) {
            case Tema::AMOR:
                resposta.explicacao = "Porque o amor é uma ilusão que desaparecerá quando as estrelas negras se alinharem...";
                break;
            case Tema::TRABALHO:
                resposta.explicacao = "Porque o trabalho é uma prisão que se desmoronará quando o caos reinar...";
                break;
            case Tema::SAUDE:
                resposta.explicacao = "Porque a saúde é uma miragem que se dissipará quando o vazio consumir tudo...";
                break;
            case Tema::DINHEIRO:
                resposta.explicacao = "Porque o dinheiro é papel queimado no apocalipse financeiro...";
                break;
            case Tema::AMIGOS_FAMILIA:
                resposta.explicacao = "Porque os laços de amizade e família serão desfeitos no turbilhão do fim dos tempos...";
                break;
            case Tema::VIAGENS:
                resposta.explicacao = "Porque viajar será impossível quando o mundo desmoronar...";
                break;
            case Tema::ESTUDOS:
                resposta.explicacao = "Porque o conhecimento será cinzas ao vento quando a ignorância cósmica final se abater...";
                break;
            case Tema::ESPIRITUALIDADE:
                resposta.explicacao = "Porque a espiritualidade será um vazio quando as estrelas negras se alinharem...";
                break;
            default: // Tema::GERAL
                resposta.explicacao = "Porque tudo será consumido pelo vazio quando o fim chegar...";
                break;
        }
        break;
    default:
        resposta.explicacao = "Porque cada resposta é uma janela para um abismo mais profundo...";
        break;
}

return resposta;
}


    if (!respostas.empty()) {
        size_t index = rand() % respostas.size();
        RespostaComExplicacao resposta;
        resposta.resposta = removerAcentos(respostas[index]);
        resposta.explicacao = removerAcentos(explicacoes[index]);
        return resposta;
    }

    return {"", ""};
}
