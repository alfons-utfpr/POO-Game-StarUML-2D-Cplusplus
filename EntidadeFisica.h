#pragma once
#include "Entidade.h"
#include "Vetor2D.h"
#include "Ids.h"
#include <string>

namespace Jogo
{
	namespace Entidades
	{
		class EntidadeFisica: public Entidade
		{
		protected:
			int altura;
			int largura;
			
			std::string id;

		public:
			EntidadeFisica();
			virtual ~EntidadeFisica();

			Vetor::Vetor2F ajustes;

			virtual void colidiu(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
			virtual void ajustar();

			void setPos(Vetor::Vetor2F pos);
			Vetor::Vetor2F getPos() const;
			Vetor::Vetor2F getTamanho() const;
			std::string getID() const;
			int getLevel() const;
		};
	}
}