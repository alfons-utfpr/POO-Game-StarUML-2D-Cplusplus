#include "Caixote.h"
#include <iostream>

namespace Jogo {
    namespace Obstaculo {
        Caixote::Caixote(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Colidivel(pos, vel, Ids::caixote, "../imagens/caixote.png") {

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

            if (idOutro == Ids::heroi)
            {
                float dist_x = (static_cast<float>(dimensoes.x) + posicao.x) / 2 - std::abs(posicao.x + static_cast<float>(dimensoes.x) / 2 - posicaoOutro.x - dimensoes.x / 2);
                float dist_y = (static_cast<float>(dimensoes.y) + posicao.y) / 2 - std::abs(posicao.y + static_cast<float>(dimensoes.y) / 2 - posicaoOutro.y - dimensoes.y / 2);


                if (dist_x * dist_y > .001 * dimensoes.x * dimensoes.y) {
                    if (dist_x < dist_y) {
                        //colisao em X
                        if (dist_x > std::abs(ajustes.x)) {
                            posicao.x += dist_x * (posicao.x + static_cast<float>(dimensoes.x) / 2 > posicaoOutro.x + posicao.x / 2 ? 1 : -1);
                        }
                    }
                }

                else if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara) {
                    //
                }
            }
        }
    }
}