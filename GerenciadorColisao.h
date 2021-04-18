#pragma once
#include "GerenciadorTile.h"
#include <set>

#include "GerenciadorTile.h"

#include <set>

namespace InvasaoAlienigena {
    class Colidivel;
    namespace Gerenciador {
        class GerenciadorColisoes {
        private:
            std::set<Colidivel*> colidiveis;
            bool estaoColidindo(Colidivel* p1, Colidivel* p2);
            Gerenciador::GerenciadorTiles* gt;

        public:
            GerenciadorColisoes();
            ~GerenciadorColisoes();
            void adicionarColidivel(Colidivel* p);
            void removerColidivel(Colidivel* p);
            void removerTodos();
            void verificarColisoes();
            void setGerenciadorTiles(Gerenciador::GerenciadorTiles* Gt);
        };
    }
}