#pragma once
#include "Menu.h"
#include "CampoTexto.h"
#include "GerenciadorGrafico.h"

namespace InvasaoAlienigena {
    namespace Menu {
        class MenuConfiguracoes : public Menu {
        protected:
            bool imprimiu;
            CampoTexto campoTexto;
        public:
            MenuConfiguracoes(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
        };
    }
}

