#pragma once
#include "Estado.h"
#include "Salvavel.h"

#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "GerenciadorTile.h"

#include "ListaDesenhaveis.h"
#include "Desenhavel.h"
#include "Heroi.h"

#include "Relogio.h"

namespace Jogo {
    namespace Fase {
        class Fase : public Estado, public Salvavel {
        protected:
            Gerenciador::GerenciadorGrafico& gerenciadorGrafico;
            Entidades::Desenhaveis::Heroi* jogador1;
            Entidades::Desenhaveis::Heroi* jogador2;
            Gerenciador::GerenciadorEventos gerenciadorEventos;
            Gerenciador::GerenciadorColisoes gerenciadorColisoes;
            Gerenciador::GerenciadorTiles* gerenciadorTiles;
            Relogio relogio; //vide cola
            Lista::ListaDesenhaveis listaAmigos;

        public:
            Fase(Gerenciador::GerenciadorGrafico& gg, Gerenciador::GerenciadorTiles* gt, Entidades::Desenhaveis::Heroi* jogador1 = nullptr, Entidades::Desenhaveis::Heroi* jogador2 = nullptr);
            //Construtor sem parâmetros não é necessário pois ele não existe em classes com atributos que são referências
            ~Fase();
            int executar() override;
            virtual void inicializar() = 0;

        private:
            unsigned int IdOuvinteFecharTela;
            unsigned int IdOuvinteEntrarMenu;
            void botaoFecharTelaApertado(const sf::Event evento);
            void botaoEntrarMenuApertado(const sf::Event evento);

        protected:
            void setCodigoRetorno(int codigo);
            int codigoRetorno;
        };
    }
}
