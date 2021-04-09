#pragma once
#include "Vetor2D.h"

namespace Jogo
{
	namespace Entidades
	{
		class Entidade
		{
		private:

		protected:
			Vetor::Vetor2F posicao;

			virtual void inicializacoesEspecificas() = 0;

		public:
			Entidade();
			virtual ~Entidade();
		};
	}
}