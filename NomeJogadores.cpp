#include "NomeJogadores.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace Jogo {
    namespace Menu {
        NomeJogadores::NomeJogadores(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg }, imprimiu{ false },
            campoTexto{ ge, 15, {300.0f, 50.0f}, {200, 40} } {
            gb.adicionarBotao(new Botao({ 200.0f,110.0f }, { 100, 50 }, "Jogador 1:"));
            gb.adicionarBotao(&campoTexto);
            //gb.adicionarBotao(new Botao({ 200.0f, 110.0f }, { 100, 50 }, "Primeira Fase", [this] {setCodigoRetorno(); }));
            
        }

        int NomeJogadores::executar()
        {
            int ret = Menu::executar();
            
            return ret;
        }
    }
}