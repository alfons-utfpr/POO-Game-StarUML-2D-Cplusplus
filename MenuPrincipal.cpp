#include "MenuPrincipal.h"

#include "GerenciadorTelas.h"

#include <iostream>

namespace Jogo {
    namespace Menu {
        MenuPrincipal::MenuPrincipal(Gerenciador::GerenciadorGrafico& GG) : Menu(GG), imprimiu{ false },
            campoTexto{ ge, 15, {200.0f, 50.0f}, {200, 40} } {
            gb.adicionarBotao(new Botao({ 100.0f, 100.0f }, { 100, 40 }, "Nova Primeira", [this] {setCodigoRetorno(comecarPrimeiraFase); }));
            gb.adicionarBotao(new Botao({ 100.0f, 150.0f }, { 100, 40 }, "Fase final", [this] {setCodigoRetorno(comecarSegundaFase); }));
            gb.adicionarBotao(new Botao({ 100.0f, 200.0f }, { 100, 40 }, "Ranking", [this] {setCodigoRetorno(comecarFaseFinal); }));
            gb.adicionarBotao(new Botao({ 300.0f, 100.0f }, { 100, 40 }, "Carregar jogo", [this] {setCodigoRetorno(carregarJogo); }));
            gb.adicionarBotao(new Botao({ 300.0f, 150.0f }, { 100, 40 }, "Configurações", [this] {setCodigoRetorno(configuracoes); }));
            gb.adicionarBotao(new Botao({ 300.0f, 200.0f }, { 100, 40 }, "Sair do jogo", [this] {setCodigoRetorno(terminarJogo); }));
            gb.adicionarBotao(&campoTexto);
        }

        int MenuPrincipal::executar() {
            int ret = Menu::executar();
            if (!imprimiu && campoTexto.getTextoPronto()) {
                imprimiu = true;
                std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
            }
            return ret;
        }
    }
}