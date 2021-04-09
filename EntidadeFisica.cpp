#include "EntidadeFisica.h"
#include "Vetor2D.h"

namespace Jogo
{
	namespace Entidades
	{
		EntidadeFisica::EntidadeFisica(): Entidade(), altura(0), largura(0), ajustes (0,0)
		{

		}

		EntidadeFisica::~EntidadeFisica()
		{

		}

		void EntidadeFisica::colidiu(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro)
		{
		}

		void EntidadeFisica::ajustar()
		{
			posicao += ajustes;
			ajustes = Vetor::Vetor2F(0, 0);
		}
		
		void EntidadeFisica::setPos(Vetor::Vetor2F pos)
		{
			posicao = pos;
		}
		
		Vetor::Vetor2F EntidadeFisica::getPos() const
		{
			return posicao;
		}
		
		Vetor::Vetor2F EntidadeFisica::getTamanho() const
		{
			return (altura, largura);
		}
		
		std::string EntidadeFisica::getID() const 
		{
			return id;
		}
		int EntidadeFisica::getLevel() const
		{
			return 0;
		}
	}
}