#include "MenuJogador.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Menu {
        MenuJogador::MenuJogador(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg }, imprimiu{ false },
            campoTexto{ ge, 15, {150.0f, 250.0f}, {200, 40} } {
            gb.adicionarBotao(new Botao({ 200.0f, 100.0f }, { 100, 50 }, "1 jogador", [this] {setCodigoRetorno(umJogador); }));
            gb.adicionarBotao(new Botao({ 200.0f, 180.0f }, { 100, 50 }, "2 jogadores", [this] {setCodigoRetorno(doisJogadores); }));
            gb.adicionarBotao(new Botao({ 200.0f, 260.0f }, { 100, 40 }, "Menu Principal", [this] {setCodigoRetorno(irMenuPrincipal); }));
            //gb.adicionarBotao(new Botao({ 200.0f, 300.0f }, { 50, 50 }, "Enviar", [this] {setCodigoRetorno(nome); }));
        }

        int MenuJogador::executar()
        {
            int ret = Menu::executar();
            gb.adicionarBotao(new Botao({ 200.0f, 40.0f }, { 50 }, "NÚMERO DE JOGADORES: "));

            usarDoisJogadores(doisJogadores);
            return ret;
        }
        int MenuJogador::usarDoisJogadores(int codigoRetorno)
        {
            if (umJogador) {
                //gb.adicionarBotao(new Botao({ 300.0f,100.0f }, {50},"jogo"));
                if (!imprimiu && campoTexto.getTextoPronto()) {
                    imprimiu = true;
                    std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
                }
            }

            if (doisJogadores) {
                //gb.adicionarBotao(&campoTexto);
                if (!imprimiu && campoTexto.getTextoPronto()) {
                    imprimiu = true;
                    std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
                }
                //gb.adicionarBotao(&campoTexto);
                if (!imprimiu && campoTexto.getTextoPronto()) {
                    imprimiu = true;
                    std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
                }
            }

            return 0;
        }
    }
}