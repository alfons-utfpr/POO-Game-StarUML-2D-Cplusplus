#include "Colidivel.h"

namespace Jogo {

    Colidivel::Colidivel( Vetor2F pos /* = {0.0f, 0.0f}*/, Vetor2F vel/* = {0.0f, 0.0f}*/, Ids::Ids ID  /*= Ids::semID*/, const char* caminhoTextura /* = nullptr*/) :
        Desenhavel{ ID, pos, vel, caminhoTextura } {

    }

}