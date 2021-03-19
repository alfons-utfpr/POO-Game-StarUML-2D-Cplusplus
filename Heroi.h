#pragma once
#include "Vetor2D.h"
#include "Colidivel.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "../Json/json.hpp"


namespace exercicio {

    class Heroi : public Colidivel {
    private:
        unsigned int chaveOuvinte;
        const float gravitySpeed = 0.3;
        bool isJumping = false;
    public:

        Heroi(Vetor2F pos = { 0.0f , 0.0f });
        ~Heroi();
        void inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
        void atualizar(float t);
        void desenhar(GerenciadorGrafico& g);
        void tratarEvento(const sf::Event& e);
        void colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro);
        void inicializarComJSON(nlohmann::json fonte);
    };

}