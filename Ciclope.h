#pragma once
#include "Colidivel.h"
#include "Ids.h"

namespace Jogo {
    namespace Desenhaveis {
        class Ciclope : public Colidivel {
        private:

        public:

            Ciclope(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
            Ciclope(nlohmann::json fonte);
            ~Ciclope();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);

        };
    }
}
