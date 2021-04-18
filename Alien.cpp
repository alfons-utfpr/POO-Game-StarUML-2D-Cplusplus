#include "Alien.h"

#include <iostream>

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        Alien::Alien(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Inimigo(pos, vel, Ids::alien, "../imagens/inimigo6.png") {

        }

        Alien::Alien(nlohmann::json fonte) : Alien({ fonte["posicao"] }, { fonte["velocidade"] }) {

        }

        Alien::~Alien() {

        }

        void Alien::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void Alien::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {

            if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara || idOutro == Ids::caixote) {
                Vetor::Vetor2F dist = posicao - posicaoOutro;
                float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
                float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;
                if (sobr_x > sobr_y) {
                    posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
                }
                else {
                    posicao.x -= (dist.y > 0 ? -1 : 1) * sobr_y;
                }
            }
        }
    }
}