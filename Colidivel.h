#pragma once

#include "Desenhavel.h"
#include "Ids.h"
#include "Vetor2D.h"

namespace exercicio {

    class Colidivel : public Desenhavel {
    public:
        Colidivel(Vetor2F pos = { 0.0f, 0.0f }, Vetor2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);
        virtual void colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro) = 0;
    };
}