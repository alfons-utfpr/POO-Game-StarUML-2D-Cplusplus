#include "MenuJogador.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace Jogo {
    namespace Menu {
        MenuJogador::MenuJogador(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg }, imprimiu{ false },
            campoTexto{ ge, 15, {300.0f, 50.0f}, {200, 40} } {
            gb.adicionarBotao(new Botao({ 200.0f, 100.0f }, { 100, 50 }, "1 jogador", [this] {setCodigoRetorno(umJogador); }));
            gb.adicionarBotao(new Botao({ 200.0f, 180.0f }, { 100, 50 }, "2 jogadores", [this] {setCodigoRetorno(doisJogadores); }));
            gb.adicionarBotao(new Botao({ 200.0f, 260.0f }, { 100, 40 }, "Menu Principal", [this] {setCodigoRetorno(irMenuPrincipal); }));
        }

        int MenuJogador::executar()
        {
            int ret = Menu::executar();
            gb.adicionarBotao(new Botao({ 200.0f, 40.0f }, { 50 }, "NÚMERO DE JOGADORES: "));
            
            if (umJogador) {
                //gb.adicionarBotao(&campoTexto);
                if (!imprimiu && campoTexto.getTextoPronto()) {
                    imprimiu = true;
                    std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
                }
            }
            else if (doisJogadores){
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
        int MenuJogador::usarDoisJogadores(int codigoRetorno) {

            switch (codigoRetorno) {
            case umJogador:
                gb.adicionarBotao(&campoTexto);
                return 0;
            }
            gb.adicionarBotao(&campoTexto);
            return doisJogadores;
        }
    }
}