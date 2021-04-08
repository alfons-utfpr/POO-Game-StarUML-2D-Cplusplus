#include "Score.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace Jogo {
	namespace Menu {
        Score::Score(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg },
            campoTexto{ ge, 15, {200.0f, 50.0f}, {200, 40} } {
            gb.adicionarBotao(new Botao({ 200.0f, 100.0f }, { 100, 50 }, "Ranking", [this] {setCodigoRetorno(ranking); }));
            //gb.adicionarBotao(&campoTexto);
            gb.adicionarBotao(&campoTexto);
        }

        /*nome dos jogadores*/
        int Score::executar() {
            int ret = Menu::executar();
            if (umJogador) {
                gb.adicionarBotao(&campoTexto);
            }
            else
            {
                gb.adicionarBotao(&campoTexto);
                gb.adicionarBotao(&campoTexto);

            }
            return ret;
        }
	}
}
