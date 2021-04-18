#include "Inimigo.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        Inimigo::Inimigo(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
            Colidivel(pos, vel, ID, caminhoTextura) {

        }

        Inimigo::~Inimigo() {

        }

        void Inimigo::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }
    }
}
