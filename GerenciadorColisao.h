#pragma once
#include "GerenciadorTile.h"
#include <set>

#include "GerenciadorTile.h"

#include <set>

namespace exercicio {

    class Colidivel;

    class GerenciadorColisoes {
    private:
        std::set<Colidivel*> colidiveis;
        bool estaoColidindo(Colidivel* p1, Colidivel* p2);
        GerenciadorTiles* gt;

    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();
        void adicionarColidivel(Colidivel* p);
        void removerColidivel(Colidivel* p);
        void removerTodos();
        void verificarColisoes();
        void setGerenciadorTiles(GerenciadorTiles* Gt);
    };
}