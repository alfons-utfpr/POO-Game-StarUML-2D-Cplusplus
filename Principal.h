#pragma once

#include "GerenciadorGrafico.h"
#include "Kahlo.h"
#include "GerenciadorTelas.h"

namespace InvasaoAlienigena {
    class Principal {
    private:
        Gerenciador::GerenciadorGrafico gerenciadorGrafico;
        Entidades::Desenhaveis::Kahlo jogador1;
        Entidades::Desenhaveis::Frida jogador2;
        Gerenciador::GerenciadorTelas gerenciadorTelas;
        bool terminar;

    public:
        Principal();
        ~Principal();
        int executar();
        void janelaFechada(const sf::Event& e);

    };

}