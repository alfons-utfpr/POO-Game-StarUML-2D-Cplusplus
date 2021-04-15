#include "Score.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace Jogo {
	namespace Menu {
        Score::Score(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg },
            campoTexto{ ge, 15, {200.0f, 50.0f}, {200, 40} } {
            //gb.adicionarBotao(new Botao({ 200.0f, 50.0f }, { 100, 50 }, "Classificação", [this] {setCodigoRetorno(classificacao); }));
            gb.adicionarBotao(new Botao({ 200.0f, 250.0f }, { 100, 50 }, "Menu Principal", [this] {setCodigoRetorno(irMenuPrincipal); }));
        }
        /*nome dos jogadores*/
        int Score::executar() {
            int ret = Menu::executar();
            gb.adicionarBotao(new Botao({ 200.0f, 50.0f }, { 200.0f }, "CLASSIFICAÇÃO "));
            return ret;
        }
	}
}
