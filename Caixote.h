#pragma once
#include "Colidivel.h"
#include "Ids.h"

namespace Jogo {
	namespace Obstaculo {
		class Caixote : public Colidivel{
		private:
			Vetor::Vetor2F ajustes;

		public:
			Caixote(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
			Caixote(nlohmann::json fonte);
			~Caixote();
			void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
			void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
		};
	}
}

