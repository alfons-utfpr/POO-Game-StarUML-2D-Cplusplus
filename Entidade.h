#pragma once
#include "Fase.h"
#include "Vetor2D.h"

namespace InvasaoAlienigena
{
	namespace Entidades
	{
		class Entidade
		{
		protected:
			Vetor::Vetor2F posicao;
			//Fases::Fase* faseAtual;
			virtual void inicializacoesEspecificas() = 0;

		public:
			Entidade();
			virtual ~Entidade();

			//void setFase(Fases::Fase* fase);
			//void inicializacaoGenerica(Fases::Fase* fase);
		};
	}
}