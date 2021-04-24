#include "BuracoInfinito.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Obstaculo {
        BuracoInfinito::BuracoInfinito(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Obstaculo(pos, vel, Ids::buracoInfinito, "../imagens/buraco_negro.png") {

        }

        BuracoInfinito::BuracoInfinito(nlohmann::json fonte) : BuracoInfinito({ fonte["posicao"] }, { fonte["velocidade"] }) {

        }

        BuracoInfinito::~BuracoInfinito() {

        }

        void BuracoInfinito::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void BuracoInfinito::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {
            
            if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara) {
                Vetor::Vetor2F dist = posicao - posicaoOutro;
                float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
                float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;
                if (sobr_x > sobr_y) {
                    posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
                }
                else {
                    posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;
                }
            }
        }
    }
}