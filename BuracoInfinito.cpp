#include "BuracoInfinito.h"
#include <iostream>

namespace Jogo {
    namespace Obstaculo {
        BuracoInfinito::BuracoInfinito(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Colidivel(pos, vel, Ids::caixote, "../imagens/buraco_negro.png") {

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
            
            
        }
    }
}