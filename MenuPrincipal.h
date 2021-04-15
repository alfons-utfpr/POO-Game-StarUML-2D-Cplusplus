#pragma once
#include "Menu.h"
#include "CampoTexto.h"

namespace Jogo {
    namespace Menu {
        class MenuPrincipal : public Menu {
        protected:
            bool imprimiu;
            CampoTexto campoTexto;
            bool doisJogadores;

        public:
            MenuPrincipal(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
        };
    }
    
}


