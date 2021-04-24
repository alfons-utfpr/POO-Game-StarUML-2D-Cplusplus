#pragma once
#include "Vetor2D.h"
#include "Estado.h"
#include "Colidivel.h"
#include "Jogador.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "ListaDesenhaveis.h"
#include "Desenhavel.h"
#include "../Json/json.hpp"
//#include "EntidadeFisica.h"


namespace InvasaoAlienigena {
    namespace Entidades {
        namespace Desenhaveis {
            //class Fase;
            
            class Kahlo: public Jogador{
            private:
                float vel_x;
                float vel_y;
                int vidas;
                unsigned int chaveOuvinte;
                //const float gravitySpeed = 0.3;
                bool isJumping = false;
                Vetor::Vetor2F ajustes;
                Lista::ListaDesenhaveis proj;
               // int codigoRetorno;

                //Fase::Fase fase;
                //Estado fase;

            public:
                Kahlo(Vetor::Vetor2F pos = { 0.0f , 0.0f });
                ~Kahlo();
                //nlohmann::json paraJSON() override;
                void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
                void atualizar(float t);
                void desenhar(Gerenciador::GerenciadorGrafico& g);
                void tratarEvento(const sf::Event& f);
                void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
                void inicializarComJSON(nlohmann::json fonte);
                void ajustar();
                //void proximaFase(GerenciadorGrafico& gg, Entidades::Desenhaveis::Heroi* jogador1 = nullptr, Entidades::Desenhaveis::Frida* jogador2 = nullptr);
                const int getVidas() const;
            };
        }
    }
}