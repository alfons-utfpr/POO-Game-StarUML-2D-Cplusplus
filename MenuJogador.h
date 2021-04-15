#pragma once
#include "Menu.h"
#include "CampoTexto.h"

namespace Jogo {
    namespace Menu {
        class MenuJogador : public Menu {
        protected:
            bool imprimiu;
            CampoTexto campoTexto;

        public:
            MenuJogador(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
            const bool usarDoisJogadores(int codigoRetorno) const;
        };
    }

}

