#pragma once

#include "Menu.h"
#include "CampoTexto.h"

namespace Jogo {
    namespace Menu {
        class MenuPrincipal : public Menu {
            bool imprimiu;
            CampoTexto campoTexto;
        public:
            MenuPrincipal(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
        };
    }
    
}


