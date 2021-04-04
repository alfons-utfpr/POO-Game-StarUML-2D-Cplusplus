#pragma once

#include "Colidivel.h"
#include "Ids.h"

namespace Jogo {
     namespace Desenhaveis {
        class SegundoVilao : public Colidivel {
        private:

        public:

            SegundoVilao(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
            SegundoVilao(nlohmann::json fonte);
            ~SegundoVilao();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
        };
     }
}
