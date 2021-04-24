#pragma once
#include "Kahlo.h"
#include "Frida.h"
#include "GerenciadorEstados.h"
#include "CampoTexto.h"

namespace InvasaoAlienigena {
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
        nome,
        comecar,
        
    };

    namespace Gerenciador {
        class GerenciadorGrafico;
        
        class GerenciadorTelas : public GerenciadorEstados {
        private:
            GerenciadorGrafico& gerenciadorGrafico;
            Entidades::Desenhaveis::Kahlo* jogador1;
            Entidades::Desenhaveis::Frida* jogador2;
            bool multiplosJogadores;
            //Projetil::Projetil proj;

        public:
            GerenciadorTelas(GerenciadorGrafico& gg, Entidades::Desenhaveis::Kahlo* jogador1 = nullptr, Entidades::Desenhaveis::Frida* jogador2 = nullptr);
            //Construtor sem par�metros n�o � necess�rio pois ele n�o existe em classes com atributos que s�o refer�ncias
        //protected:
            bool processarCodigo(int codigoRetorno) override;

        };
    }
}