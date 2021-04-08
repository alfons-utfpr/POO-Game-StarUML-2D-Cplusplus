#include "Vilao.h"

#include <iostream>

namespace Jogo {
    namespace Desenhaveis {
        Vilao::Vilao(Vetor::Vetor2F pos /*= {0.0f, 0.0f}*/, Vetor::Vetor2F vel /*= {0.0f, 0.0f}*/) :
            Colidivel(pos, vel, Ids::vilao, "../imagens/inimigo6.png") {

        }

        Vilao::Vilao(nlohmann::json fonte) : Vilao({ fonte["posicao"] }, { fonte["velocidade"] }) {

        }

        Vilao::~Vilao() {

        }

        void Vilao::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void Vilao::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {

            if (idOutro == Ids::heroi) {
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

            }
        }
    }
}