#include "Entidade.h"

namespace InvasaoAlienigena
{
	namespace Entidades
	{
		Entidade::Entidade(): posicao{0.0f, 0.0f} /*faseAtual{nullptr}*/
		{

		}

		Entidade::~Entidade()
		{

		}
		/*void Entidade::setFase(Fases::Fase* fase)
		{
			faseAtual = fase;
		}
		void Entidade::inicializacaoGenerica(Fases::Fase* fase)
		{
			faseAtual = fase;
			inicializacoesEspecificas();
		}*/
	}
}