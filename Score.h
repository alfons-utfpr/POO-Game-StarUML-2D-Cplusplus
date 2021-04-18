#pragma once
#include "GerenciadorGrafico.h"
#include "Menu.h"
#include "CampoTexto.h"

namespace InvasaoAlienigena {
	namespace Menu {
		class Score : public Menu{
		protected:
			CampoTexto campoTexto;

		public:
			Score(Gerenciador::GerenciadorGrafico& GG);
			int executar() override;
		};
	}
}

