#pragma once
#include "Inimigo.h"
#include "Colidivel.h"
#include "Ids.h"
#include "ListaDesenhaveis.h"
#include "Projetil.h"

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        class Robotao : public Inimigo {
        private:
            //Vetor::Vetor2F ajustes;
            Lista::ListaDesenhaveis listaProjeteis;
            sf::Clock clock;
            sf::Time elapsed;
        public:

            Robotao(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
            Robotao(nlohmann::json fonte);
            ~Robotao();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            //void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
            void atualizar(float t) override;
            void desenhar(Gerenciador::GerenciadorGrafico& g) override;

        };
    }
}

