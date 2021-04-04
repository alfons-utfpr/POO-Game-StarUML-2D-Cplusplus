#pragma once
#include "Heroi.h"
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
        carregarJogo,
        configuracoes,
        irMenuPrincipal,
        irMenuPausa,
        sairMenuPausa,
        umJogador,
        doisJogadores,
    };

    namespace Gerenciador {
        class GerenciadorGrafico;
        

        class GerenciadorTelas : public GerenciadorEstados {
        private:
            GerenciadorGrafico& gerenciadorGrafico;
            Desenhaveis::Heroi* jogador1;
            Desenhaveis::Heroi* jogador2;

        public:
            GerenciadorTelas(GerenciadorGrafico& gg, Desenhaveis::Heroi* jogador1 = nullptr, Desenhaveis::Heroi* jogador2 = nullptr);
            //Construtor sem par�metros n�o � necess�rio pois ele n�o existe em classes com atributos que s�o refer�ncias
        protected:
            bool processarCodigo(int codigoRetorno) override;

        };
    }
}