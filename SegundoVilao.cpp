#include "SegundoVilao.h"

#include <iostream>

namespace Jogo {
    namespace Desenhaveis {
        SegundoVilao::SegundoVilao(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Colidivel(pos, vel, Ids::vilao, "../imagens/inimigo5.png") {

        }

        SegundoVilao::SegundoVilao(nlohmann::json fonte) : SegundoVilao({ fonte["posicao"] }, { fonte["velocidade"] }) {

        }

        SegundoVilao::~SegundoVilao() {

        }

        void SegundoVilao::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void SegundoVilao::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {

            if (idOutro == Ids::heroi) {
                //fazer
            }
            else if (idOutro == Ids::vilao || idOutro == Ids::inimigo) {

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