#pragma once
#include "Menu.h"
#include "CampoTexto.h"

namespace InvasaoAlienigena {
    namespace Menu {
        class MenuPrincipal : public Menu {
        protected:
            bool imprimiu;
            CampoTexto campoTexto;

        public:
            MenuPrincipal(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
        };
    }
    
}


