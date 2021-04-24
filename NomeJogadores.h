#pragma once
#include "Menu.h"
#include "CampoTexto.h"

namespace InvasaoAlienigena {
	namespace Menu {
		class NomeJogadores: public Menu
		{
        protected:
            bool imprimiu;
            CampoTexto campoTexto;

        public:
            NomeJogadores(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
            //int usarDoisJogadores(int codigoRetorno);
        };
	};
}

