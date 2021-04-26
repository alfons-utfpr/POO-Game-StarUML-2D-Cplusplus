#include "Inimigo.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        Inimigo::Inimigo(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
            Colidivel(pos, vel, ID, caminhoTextura) {

        }

        Inimigo::~Inimigo() {

        }

        void Inimigo::atualizar(float t){
            
            posicao += v * t;
        }

        void Inimigo::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void Inimigo::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {
                       
            if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara || idOutro == Ids::frida || idOutro == Ids::kahlo ) {
                Vetor::Vetor2F dist = posicao - posicaoOutro;

                float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
                float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;

                if (sobr_x > sobr_y) {
                    posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
                    v.x *= -1;
                }
                else {
                    posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;
                    v.x *= -1;
                }
            }

            else {
                v.y = sqrtf(2 * 985 * 50);
            }
            
        }
    }
}
