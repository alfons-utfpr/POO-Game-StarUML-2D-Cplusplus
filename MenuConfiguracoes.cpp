#include "MenuConfiguracoes.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace Jogo {
    namespace Menu {
        MenuConfiguracoes::MenuConfiguracoes(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg }, imprimiu{ false },
            campoTexto{ ge, 15, {200.0f, 50.0f}, {200, 40} } {
            gb.adicionarBotao(new Botao({ 200.0f, 100.0f }, { 100, 50 }, "1 Jogador", [this] {setCodigoRetorno(umJogador); }));
            gb.adicionarBotao(new Botao({ 200.0f, 180.0f }, { 100, 50 }, "2 Jogadores", [this] {setCodigoRetorno(doisJogadores); }));
            gb.adicionarBotao(new Botao({ 200.0f, 250.0f }, { 100, 50 }, "Menu principal", [this] {setCodigoRetorno(irMenuPrincipal); }));
            //gb.adicionarBotao(&campoTexto);
            gb.adicionarBotao(&campoTexto);
        }

        /*nome dos jogadores*/
        int MenuConfiguracoes::executar() {
            int ret = Menu::executar();
            if (umJogador) {
                gb.adicionarBotao(&campoTexto);
                if (!imprimiu && campoTexto.getTextoPronto()) {
                    imprimiu = true;
                    std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
                }
            }
            else
            {
                gb.adicionarBotao(&campoTexto);
                gb.adicionarBotao(&campoTexto);
                if (!imprimiu && campoTexto.getTextoPronto()) {
                    imprimiu = true;
                    std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
                }

            }
            return ret;
        }
    }
}
