#pragma once
#include "Vetor2D.h"
//#include "Estado.h"
#include "Colidivel.h"
#include "Jogador.h"
#include "GerenciadorEstados.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "../Json/json.hpp"

namespace InvasaoAlienigena {
    namespace Entidades{
        namespace Desenhaveis {
            class Frida : public Jogador {
            private:
                float velx;
                float vely;
                int vidas;
                unsigned int chaveOuvinte;
                Vetor::Vetor2F ajustes;
               
            public:
                Frida(Vetor::Vetor2F pos = { 0.0f , 0.0f });
                ~Frida();
                
                void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
                //void atualizar(float t);
                void desenhar(Gerenciador::GerenciadorGrafico& g);
                void tratarEvento(const sf::Event& e);
                //void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
                void inicializarComJSON(nlohmann::json fonte);
                void ajustar();
                const int getVidas() const;
            };
        }
    }
}

