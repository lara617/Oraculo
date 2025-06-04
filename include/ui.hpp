#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

// Limpa o ecrã
void limparEcran() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Mostra o título inicial com UTF-8 e limpa a tela
void iniciarInterface() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    limparEcran();
    std::cout << "🔮 Bem-vindo ao Oráculo Digital! 🔮\n\n";
}

// Animação de introdução mística
void mostrarAnimacaoInicial() {
    std::cout << "\nCarregando as profecias místicas...\n";
    #ifdef _WIN32
    Sleep(1500);
    #else
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    #endif
    std::cout << "\n\n";
}

// Muda a cor do texto
void mudarCorTexto(int cor) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, cor);
#endif
}

// Mensagem de despedida do oráculo
void finalizarInterface() {
    std::cout << "\n🌙 O Oráculo recolhe-se... até à próxima consulta.\n";
}

#endif
