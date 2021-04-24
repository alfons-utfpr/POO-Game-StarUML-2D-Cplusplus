#include "MenuConfiguracoes.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Menu {
        MenuConfiguracoes::MenuConfiguracoes(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg }, imprimiu{ false },
            campoTexto{ ge, 15, {200.0f, 50.0f}, {200, 40} } {
            gb.adicionarBotao(new Botao({ 200.0f, 110.0f }, { 100, 50 }, "Primeira Fase", [this] {setCodigoRetorno(comecarPrimeiraFase); }));
            gb.adicionarBotao(new Botao({ 200.0f, 170.0f }, { 100, 50 }, "Fase Final", [this] {setCodigoRetorno(comecarSegundaFase); }));
            gb.adicionarBotao(new Botao({ 100.0f, 230.0f }, { 100, 50 }, "Menu principal", [this] {setCodigoRetorno(irMenuPrincipal); }));
            gb.adicionarBotao(new Botao({ 300.0f, 230.0f }, { 100, 50 }, "Voltar", [this] {setCodigoRetorno(selecionarJogador); }));
            //gb.adicionarBotao(&campoTexto);
        }

        /*nome dos jogadores*/
        int MenuConfiguracoes::executar() {
            gg.desenharTexto("SELECIONE A FASE:", { 200.0f, 50.0f }, 15);
            //gb.adicionarBotao(new Botao({ 200.0f, 50.0f }, { 200.0f }, "SELECIONE A FASE: "));
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
