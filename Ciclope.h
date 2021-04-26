#pragma once
#include "Colidivel.h"
#include "Inimigo.h"
#include "Ids.h"

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        class Ciclope : public Inimigo{
        private:
            float vel_max_x;
            float vel_max_y;
            //Vetor::Vetor2F ajustes;

        public:

            Ciclope(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
            Ciclope(nlohmann::json fonte);
            ~Ciclope();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            //void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
            //void atualizar(float t);
        };
    }
}
