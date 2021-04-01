#pragma once

#include "Menu.h"
#include "GerenciadorGrafico.h"

namespace Jogo {
    namespace Menu {
        class MenuPausa : public Menu {
        public:
            MenuPausa(Gerenciador::GerenciadorGrafico& gg);
        };
    }
}

