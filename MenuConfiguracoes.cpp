#include "MenuConfiguracoes.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace Jogo {
    namespace Menu {
        MenuConfiguracoes::MenuConfiguracoes(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg }, imprimiu{ false },
            campoTexto{ ge, 15, {200.0f, 50.0f}, {200, 40} } {
            gb.adicionarBotao(new Botao({ 200.0f, 110.0f }, { 100, 50 }, "1 Jogador", [this] {setCodigoRetorno(umJogador); }));
            gb.adicionarBotao(new Botao({ 200.0f, 170.0f }, { 100, 50 }, "2 Jogadores", [this] {setCodigoRetorno(doisJogadores); }));
            gb.adicionarBotao(new Botao({ 200.0f, 230.0f }, { 100, 50 }, "Menu principal", [this] {setCodigoRetorno(irMenuPrincipal); }));
            //gb.adicionarBotao(&campoTexto);
        }

        /*nome dos jogadores*/
        int MenuConfiguracoes::executar() {
            gb.adicionarBotao(new Botao({ 200.0f, 50.0f }, { 200.0f }, "CONFIGURAÇÕES "));
            int ret = Menu::executar();
            if (umJogador) {
                //gb.adicionarBotao(new Botao({ 200.0f }, { 100.0f }, "Nome do jogador: "));
                //gb.adicionarBotao(&campoTexto);
                if (!imprimiu && campoTexto.getTextoPronto()) {
                    imprimiu = true;
                    std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
                }
            }
            else if (doisJogadores) {
                gb.adicionarBotao(&campoTexto);
                if (!imprimiu && campoTexto.getTextoPronto()) {
                    imprimiu = true;
                    std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
                }
                gb.adicionarBotao(&campoTexto);
                if (!imprimiu && campoTexto.getTextoPronto()) {
                    imprimiu = true;
                    std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
                }
            }
            else
                exit(2);
            return ret;
        }
    }
}
