#pragma once
#include "Projetil.h"
#include "Inimigo.h"
#include "Colidivel.h"
#include "Ids.h"
#include "ListaDesenhaveis.h"
#include "Relogio.h"

namespace InvasaoAlienigena {
     namespace Desenhaveis {
        class LagartoVerde : public Inimigo {
        private:

            //float vel_max_x;
            //float vel_max_y;
            //Vetor::Vetor2F ajustes;
            int projeteis;
            Lista::ListaDesenhaveis proj;

        public:
            LagartoVerde(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
            LagartoVerde(nlohmann::json fonte);
            ~LagartoVerde();
            nlohmann::json paraJSON() override;
            void lancarProjetil(float t);
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            //void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
        };
     }
}
