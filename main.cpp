// Oráculo Digital em C++ - Versão Avançada
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;

string toLower(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

bool containsKeyword(const string& input, const vector<string>& keywords) {
    for (const string& kw : keywords) {
        if (input.find(kw) != string::npos) return true;
    }
    return false;
}

void loadingEffect(const string& msg, int dots = 3, int delay = 500) {
    cout << msg;
    for (int i = 0; i < dots; ++i) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << "\n";
}

int main() {
    srand(time(0));

    map<string, vector<string>> respostas = {
        {"amor", {
            "O coração sabe, mas a cabeça desconfia.",
            "Nem todas as mensagens deixadas no visto são o fim.",
            "O amor é como código mal escrito… às vezes compila.",
            "Talvez sim, talvez só gostes de sofrer.",
            "Quem ama também depura.",
            "O teu bug do amor ainda não foi corrigido."
        }},
        {"futuro", {
            "Estuda ou será o destino a estudar-te.",
            "O amanhã será escrito pelas decisões de hoje.",
            "O futuro sorri… mas é um sorriso suspeito.",
            "Nem todos os caminhos levam a Roma. Alguns levam ao café.",
            "A resposta está nos teus hábitos.",
            "Nem o Oráculo consegue compilar o teu futuro sem warnings."
        }},
        {"escola", {
            "Faz o teu melhor. Depois, copia do colega.",
            "A professora sabe. E está a observar.",
            "O teste é só um número, mas o 0 também é.",
            "Estuda, mas não te esqueças de dormir.",
            "A matéria está no caderno que nunca leste.",
            "Se o teste fosse fácil, chamava-se feriado."
        }},
        {"amizade", {
            "Amigos verdadeiros são como comentários úteis.",
            "Não deixes que a stack dos problemas sobrecarregue a tua amizade.",
            "Às vezes, um amigo é melhor que um bug resolvido.",
            "Amizade não se compila, cultiva-se."
        }},
        {"existencial", {
            "A resposta está dentro de ti. Mas escondida atrás do fígado.",
            "Somos apenas instruções numa stack cósmica.",
            "A tua existência não é um erro de sintaxe.",
            "Nem o Oráculo entende o sentido da vida às segundas."
        }},
        {"neutro", {
            "O universo ainda está a calcular.",
            "Nem o destino tem a resposta para isso... ainda.",
            "A pergunta certa traz a resposta certa.",
            "Confia no processo.",
            "Tudo acontece por uma razão. Às vezes, a razão é parva.",
            "Tenta desligar e ligar outra vez."
        }}
    };

    map<string, vector<string>> categorias = {
        {"amor", {"amor", "namorado", "gostar", "relacionamento", "crush"}},
        {"futuro", {"futuro", "amanha", "depois", "vida", "destino", "trabalho"}},
        {"escola", {"escola", "teste", "prova", "nota", "trabalho", "exame", "estudo"}},
        {"amizade", {"amigo", "amizade", "colega"}},
        {"existencial", {"vida", "existencia", "morrer", "sentido", "realidade"}}
    };

    cout << "\n~~~ 🧿 ORÁCULO DIGITAL 🧿 ~~~\n";
    cout << "Escreve a tua pergunta (ou 'sair' para terminar):\n\n";

    string pergunta;
    while (true) {
        cout << "> ";
        getline(cin, pergunta);

        string perguntaMin = toLower(pergunta);
        if (perguntaMin == "sair") break;

        string categoria = "neutro";
        for (const auto& par : categorias) {
            if (containsKeyword(perguntaMin, par.second)) {
                categoria = par.first;
                break;
            }
        }

        loadingEffect("Consultando os astros", 4, 400);

        vector<string> frases = respostas[categoria];
        string resposta = frases[rand() % frases.size()];

        cout << "\n🧿 O Oráculo diz: " << resposta << "\n";
        cout << "(categoria: " << categoria << ")\n\n";
    }

    cout << "\nAté breve... ou não. 🕯️\n";
    return 0;
}
