#include "Caixote.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Obstaculo {
        Caixote::Caixote(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Obstaculo(pos, vel, Ids::caixote, "../imagens/caixote.png") {

        }

        Caixote::Caixote(nlohmann::json fonte) : Caixote({ fonte["posicao"] }, { fonte["velocidade"] }) {

        }

        Caixote::~Caixote() {

        }

        void Caixote::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void Caixote::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {

            if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara || idOutro == Ids::kahlo || idOutro == Ids::frida || idOutro == Ids::caixote) {
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
            else if (idOutro == Ids::kahlo || idOutro == Ids::frida || idOutro == Ids::caixote) {
                Vetor::Vetor2F dist = posicao - posicaoOutro;
                float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
                float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;
                if (sobr_x > sobr_y) {
                    posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
                }
                else {
                    posicao.x -= (dist.x > 0 ? -1 : 1) * sobr_x;
                    posicao.y -= (dist.x > 0 ? -1 : 1) * sobr_y;
                }
            }
        }
    }
}