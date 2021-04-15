#include "LagartoVerde.h"
#include <iostream>

namespace Jogo {
    namespace Desenhaveis {
        LagartoVerde::LagartoVerde(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Colidivel(pos, vel, Ids::vilao, "../imagens/inimigo5.png") {

        }

        LagartoVerde::LagartoVerde(nlohmann::json fonte) : LagartoVerde({ fonte["posicao"] }, { fonte["velocidade"] }) {

        }

        LagartoVerde::~LagartoVerde() {

        }

        void LagartoVerde::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void LagartoVerde::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {
            ajustes = Vetor::Vetor2F(300, 400);
            

            if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara || idOutro == Ids::vilao || idOutro == Ids::inimigo || idOutro == Ids::caixote) {
                float dist_x = (static_cast<float>(dimensoes.x) + posicao.x) / 2 - std::abs(posicao.x + static_cast<float>(dimensoes.x) / 2 - posicaoOutro.x - dimensoes.x / 2);
                float dist_y = (static_cast<float>(dimensoes.y) + posicao.y) / 2 - std::abs(posicao.y + static_cast<float>(dimensoes.y) / 2 - posicaoOutro.y - dimensoes.y / 2);


                if (dist_x * dist_y > .001 * dimensoes.x * dimensoes.y) {
                    if (dist_x < dist_y) {
                        //colisao em X
                        if (dist_x > std::abs(ajustes.x)) {
                            posicao.x += dist_x * (posicao.x + static_cast<float>(dimensoes.x) / 2 > posicaoOutro.x + posicao.x / 2 ? 1 : -1);
                        }
                    }
                    else {
                        //colisao em Y
                        if (dist_y > std::abs(ajustes.y)) {
                            posicao.y += dist_y * (posicao.y + static_cast<float>(dimensoes.y) / 2 > posicaoOutro.y + posicao.y / 2 ? 1 : -1);
                        }
                    }
                }
                posicao += ajustes;
            }
        }
    }
}