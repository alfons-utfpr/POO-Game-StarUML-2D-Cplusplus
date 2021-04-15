#include "Alien.h"

#include <iostream>

namespace Jogo {
    namespace Desenhaveis {
        Alien::Alien(Vetor::Vetor2F pos /*= {0.0f, 0.0f}*/, Vetor::Vetor2F vel /*= {0.0f, 0.0f}*/) :
            Colidivel(pos, vel, Ids::vilao, "../imagens/inimigo6.png") {

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
            ajustes = Vetor::Vetor2F(0, 0);
            posicao += ajustes;

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
            }

            /*if (idOutro == Ids::heroi) {
                std::cout << std::endl;

            }
            else if (idOutro == Ids::vilao) {

                Vetor::Vetor2F distancia = posicao - posicaoOutro;

                posicao += distancia * (1 / 2);

                v.x *= -1;
                v.y *= -1;
            }
            else if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara)
            {
                Vetor::Vetor2F distancia = posicao - posicaoOutro;

                posicao += distancia * (1 / 2);

                v.x *= -1;
            }
            else if (idOutro == Ids::parede_up)
            {
                Vetor::Vetor2F distancia = posicao - posicaoOutro;

                posicao -= distancia * (1 / 2);

                v.x *= -1;
            }
            else if (idOutro == Ids::parede_clara)
            {

            }*/
        }
    }
}