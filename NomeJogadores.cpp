#include "NomeJogadores.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Menu {
        NomeJogadores::NomeJogadores(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg }, imprimiu{ false },
            campoTexto{ ge, 15, {150.0f, 90.0f}, {200, 40} } {
            gb.adicionarBotao(new Botao({ 300.0f, 230.0f }, { 150, 40 }, "Selecionar Fase", [this] {setCodigoRetorno(comecar); }));
            gb.adicionarBotao(new Botao({ 100.0f, 230.0f }, { 100, 40 }, "Voltar", [this] {setCodigoRetorno(selecionarJogador); }));

            
            //gb.adicionarBotao(&campoTexto);
        }

        int NomeJogadores::executar()
        {
            int ret = Menu::executar();
            if (doisJogadores)
            {
                gb.adicionarBotao(&campoTexto);
            }
            gg.desenharTexto("NOME", { 100.0f, 50.0f }, 15);
            
            
            return ret;
        }
    }
}