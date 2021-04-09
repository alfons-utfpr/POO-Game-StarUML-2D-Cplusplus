#pragma once

#include "GerenciadorGrafico.h"

#include "Heroi.h"

#include "GerenciadorTelas.h"


namespace Jogo {

    class Principal {
    private:

        Gerenciador::GerenciadorGrafico gerenciadorGrafico;
        Entidades::Desenhaveis::Heroi jogador1;
        Gerenciador::GerenciadorTelas gerenciadorTelas;
        bool terminar;
    public:
        Principal();
        ~Principal();
        int executar();
        void janelaFechada(const sf::Event& e);

    };

}