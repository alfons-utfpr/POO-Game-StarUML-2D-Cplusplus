#include "Colidivel.h"

namespace InvasaoAlienigena {

    Colidivel::Colidivel(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
        Desenhavel{ ID, pos, vel, caminhoTextura } {

    }

}