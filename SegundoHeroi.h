#pragma once
#include "Vetor2D.h"
#include "Colidivel.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "../Json/json.hpp"


namespace Jogo {
    namespace Desenhaveis {
        class SegundoHeroi : public Colidivel {
        private:
            int vidas = 3;
            unsigned int chaveOuvinte;
            const float gravitySpeed = 0.3;
            bool isJumping = false;
            //GerenciadorGrafico& gerenciadorGrafico;
            //Heroi* jogador1;
            //Heroi* jogador2;
        public:
            SegundoHeroi(Vetor::Vetor2F pos = { 0.0f , 0.0f });
            ~SegundoHeroi();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void atualizar(float t);
            void desenhar(Gerenciador::GerenciadorGrafico& g);
            void tratarEvento(const sf::Event& e);
            void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
            void inicializarComJSON(nlohmann::json fonte);
            //bool SegundaFase(Gerenciador::GerenciadorGrafico gf, Heroi j);

        };
    }
}

