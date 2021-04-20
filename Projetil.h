#pragma once
#include <SFML/Graphics.hpp>
#include "Desenhavel.h"
#include "Vetor2D.h"
#include "Colidivel.h"

namespace InvasaoAlienigena {
	namespace Projetil {
		class Projetil : public Colidivel
		{

		public:
			Projetil(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);
			Projetil(nlohmann::json fonte);
			Projetil();
			virtual ~Projetil();

			void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
			void atualizar(float t) override;
			void desenhar(Gerenciador::GerenciadorGrafico& g);
			void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) override;
		};
	}
}

