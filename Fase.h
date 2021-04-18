#pragma once
#include "Estado.h"
#include "Salvavel.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "GerenciadorTile.h"
#include "ListaDesenhaveis.h"
#include "Desenhavel.h"
#include "Kahlo.h"
#include "Frida.h"
#include "Relogio.h"

namespace InvasaoAlienigena {
    namespace Fase {
        class Fase : public Estado, public Salvavel {
        protected:
            Gerenciador::GerenciadorGrafico& gerenciadorGrafico;
            Entidades::Desenhaveis::Kahlo* jogador1;
            Entidades::Desenhaveis::Frida* jogador2;
            Gerenciador::GerenciadorEventos gerenciadorEventos;
            Gerenciador::GerenciadorColisoes gerenciadorColisoes;
            Gerenciador::GerenciadorTiles* gerenciadorTiles;
            Relogio relogio; 
            Lista::ListaDesenhaveis listaAmigos;


        public:
            Fase(Gerenciador::GerenciadorGrafico& gg, Gerenciador::GerenciadorTiles* gt, Entidades::Desenhaveis::Kahlo* jogador1 = nullptr, Entidades::Desenhaveis::Frida* jogador2 = nullptr);
            //Construtor sem par�metros n�o � necess�rio pois ele n�o existe em classes com atributos que s�o refer�ncias
            ~Fase();
            int executar() override;
            virtual void inicializar() = 0;

        private:
            unsigned int IdOuvinteFecharTela;
            unsigned int IdOuvinteEntrarMenu;
            void botaoFecharTelaApertado(const sf::Event evento);
            void botaoEntrarMenuApertado(const sf::Event evento);
            int pontos;
            sf::Font font;
            sf::Text texto;

            void initFont();

        protected:
            void setCodigoRetorno(int codigo);
            int codigoRetorno;
        };
    }
}
