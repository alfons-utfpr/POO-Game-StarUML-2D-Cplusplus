#pragma once

#include "Menu.h"
#include "CampoTexto.h"
#include "GerenciadorGrafico.h"

namespace Jogo {
    namespace Menu {
        class MenuConfiguracoes : public Menu {
            bool imprimiu;
            CampoTexto campoTexto;
        public:
            MenuConfiguracoes(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
        };
    }
}

