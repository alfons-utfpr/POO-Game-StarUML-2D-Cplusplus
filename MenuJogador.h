#pragma once
#include "Menu.h"
#include "CampoTexto.h"

namespace InvasaoAlienigena {
    namespace Menu {
        class MenuJogador : public Menu {
        protected:
            bool imprimiu;
            CampoTexto campoTexto;
            //bool doisJogadores;

        public:
            MenuJogador(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
            int usarDoisJogadores(int codigoRetorno);
        };
    }

}

