#include "MenuPrincipal.h"

#include "GerenciadorTelas.h"

#include <iostream>

namespace exercicio {
    MenuPrincipal::MenuPrincipal(GerenciadorGrafico& GG) : Menu(GG), imprimiu{ false },
        campoTexto{ ge, 15, {200.0f, 50.0f}, {200, 40} } {
        gb.adicionarBotao(new Botao({ 100.0f, 100.0f }, { 100, 40 }, "Primeira fase", [this] {setCodigoRetorno(comecarPrimeiraFase); }));
        gb.adicionarBotao(new Botao({ 100.0f, 150.0f }, { 100, 40 }, "Segunda fase", [this] {setCodigoRetorno(comecarSegundaFase); }));
        gb.adicionarBotao(new Botao({ 100.0f, 200.0f }, { 100, 40 }, "Fase final", [this] {setCodigoRetorno(comecarFaseFinal); }));
        gb.adicionarBotao(new Botao({ 300.0f, 100.0f }, { 100, 40 }, "Carregar jogo", [this] {setCodigoRetorno(carregarJogo); }));
        gb.adicionarBotao(new Botao({ 300.0f, 150.0f }, { 100, 40 }, "Configurações", [this] {setCodigoRetorno(configuracoes); }));
        gb.adicionarBotao(new Botao({ 300.0f, 200.0f }, { 100, 40 }, "Sair do jogo", [this] {setCodigoRetorno(terminarJogo); }));
        gb.adicionarBotao(&campoTexto);
    }

    int MenuPrincipal::executar() {
        int ret = Menu::executar();
        if (!imprimiu && campoTexto.getTextoPronto()) {
            imprimiu = true;
            std::cout << "o nome do seu amiguinho e " << campoTexto.getTexto() << std::endl;
        }
        return ret;
    }
}