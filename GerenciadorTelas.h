#pragma once
#include "Heroi.h"
#include "Frida.h"
#include "GerenciadorEstados.h"

namespace Jogo {
    class Heroi;
    enum CodigoRetorno {
        continuar,
        terminarJogo,
        salvarJogo,
        comecarPrimeiraFase,
        comecarSegundaFase,
        comecarFaseFinal,
        classificacao,
        carregarJogo,
        configuracoes,
        irMenuPrincipal,
        irMenuPausa,
        sairMenuPausa,
        umJogador,
        doisJogadores,
        selecionarJogador,
        fimDeJogo,
        
    };

    namespace Gerenciador {
        class GerenciadorGrafico;
        
        class GerenciadorTelas : public GerenciadorEstados {
        private:
            GerenciadorGrafico& gerenciadorGrafico;
            Entidades::Desenhaveis::Heroi* jogador1;
            Entidades::Desenhaveis::Frida* jogador2;

        public:
            GerenciadorTelas(GerenciadorGrafico& gg, Entidades::Desenhaveis::Heroi* jogador1 = nullptr, Entidades::Desenhaveis::Frida* jogador2 = nullptr);
            //Construtor sem parâmetros não é necessário pois ele não existe em classes com atributos que são referências
        protected:
            bool processarCodigo(int codigoRetorno) override;

        };
    }
}