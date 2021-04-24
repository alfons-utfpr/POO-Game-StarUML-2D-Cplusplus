#pragma once
#include "Vetor2D.h"
#include "Colidivel.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "../Json/json.hpp"


namespace InvasaoAlienigena {
    namespace Entidades {
        namespace Desenhaveis {
            class Jogador : public Colidivel
            {
            private:
                //Fase::Fase* faseAtual;
            public:
                Jogador(Vetor::Vetor2F pos = { 0.0f , 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);
                ~Jogador();
                void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
                void atualizar(float t);
                void desenhar(Gerenciador::GerenciadorGrafico& g);
                void finalFase();
            };
        }
    }
}

