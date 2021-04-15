#include "MenuPrincipal.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace Jogo {
    namespace Menu {
        MenuPrincipal::MenuPrincipal(Gerenciador::GerenciadorGrafico& GG) : Menu(GG), imprimiu{ false },
            campoTexto{ ge, 15, {200.0f, 50.0f}, {200, 40} }, doisJogadores{ true } {
            //gb.adicionarBotao(new Botao({ 100.0f, 100.0f }, { 100, 40 }, "Primeira Fase", [this] {setCodigoRetorno(selecionarJogador); }));
            //gb.adicionarBotao(new Botao({ 100.0f, 150.0f }, { 100, 40 }, "Fase final", [this] {setCodigoRetorno(comecarSegundaFase); }));
            gb.adicionarBotao(new Botao({ 100.0f, 100.0f }, { 100, 40 }, "Jogar", [this] {setCodigoRetorno(selecionarJogador); }));
            gb.adicionarBotao(new Botao({ 100.0f, 200.0f }, { 100, 40 }, "Classificacao", [this] {setCodigoRetorno(classificacao); }));
            gb.adicionarBotao(new Botao({ 300.0f, 100.0f }, { 100, 40 }, "Carregar jogo", [this] {setCodigoRetorno(carregarJogo); }));
            //gb.adicionarBotao(new Botao({ 300.0f, 150.0f }, { 100, 40 }, "Configura��es", [this] {setCodigoRetorno(configuracoes); }));
            gb.adicionarBotao(new Botao({ 300.0f, 200.0f }, { 100, 40 }, "Sair do jogo", [this] {setCodigoRetorno(terminarJogo); }));
            //gb.adicionarBotao(&campoTexto);
        }
        
        int MenuPrincipal::executar() {
            
            int ret = Menu::executar();
            gb.adicionarBotao(new Botao({ 200.0f, 50.0f }, { 200.0f }, "INVAS�O ALIENIGENA "));

            /*if (!imprimiu && campoTexto.getTextoPronto()) {
                imprimiu = true;
                std::cout << "Nome do jogador " << campoTexto.getTexto() << std::endl;
            }*/
            
            return ret;
        }

        
    }
}