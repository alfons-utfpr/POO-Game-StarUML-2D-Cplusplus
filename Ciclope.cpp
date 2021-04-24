#include "Ciclope.h"

#include <iostream>

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        Ciclope::Ciclope(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Inimigo(pos, vel, Ids::ciclope, "inimigo2.png") {
            
        }

        Ciclope::Ciclope(nlohmann::json fonte) : Ciclope({ fonte["posicao"] }, { fonte["velocidade"] }) {

        }

        Ciclope::~Ciclope() {

        }

        void Ciclope::atualizar(float t) {
            //posicao += v2 * t;
        }

        void Ciclope::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void Ciclope::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {
            if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara || idOutro == Ids::frida || idOutro == Ids::caixote) {
                Vetor::Vetor2F dist = posicao - posicaoOutro;
                float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
                float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;
                if (sobr_x > sobr_y) {
                    posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
                    v1.x *= -1;
                }
                else {
                    posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;
                    v1.x *= -1;
                }
            }
            
        }
    }
}