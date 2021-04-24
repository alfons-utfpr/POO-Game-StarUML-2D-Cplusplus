#pragma once

#include "MenuPrincipal.h"
#include "GerenciadorGrafico.h"

namespace InvasaoAlienigena {
    namespace Menu {
        class MenuPausa : public Menu{
        public:
            MenuPausa(Gerenciador::GerenciadorGrafico& gg);
        };
    }
}

