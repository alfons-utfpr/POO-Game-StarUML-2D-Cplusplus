#pragma once
#include "Vetor2D.h"
#include "Colidivel.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "../Json/json.hpp"
#include <math.h>


namespace InvasaoAlienigena {
    namespace Entidades {
        namespace Desenhaveis {
            class Jogador : public Colidivel
            {
            private:
                
                //Fase::Fase* faseAtual;

            protected:
                float gravidade;
                float velmax_y;                
                bool taPulando;

            public:
                Jogador(Vetor::Vetor2F pos = { 0.0f , 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);
                ~Jogador();
                void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
                void atualizar(float t);
                void desenhar(Gerenciador::GerenciadorGrafico& g);
                void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
                void finalFase();
                
            };
        }
    }
}

