#include "MenuPausa.h"
#include "GerenciadorTelas.h"

namespace InvasaoAlienigena {
    namespace Menu {
        MenuPausa::MenuPausa(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg } {
            gg.desenharTexto("JOGO PAUSADO", { 100.0f, 20.0f }, {15});
            gb.adicionarBotao(new Botao({ 200.0f, 90.0f }, { 100, 50 }, "Continuar jogo", [this] {setCodigoRetorno(sairMenuPausa); }));
            gb.adicionarBotao(new Botao({ 200.0f, 155.0f }, { 100, 50 }, "Salvar jogo", [this] {setCodigoRetorno(salvarJogo); }));
            gb.adicionarBotao(new Botao({ 200.0f, 220.0f }, { 100, 50 }, "Menu principal", [this] {setCodigoRetorno(irMenuPrincipal); }));
        }
    }
}