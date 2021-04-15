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