#pragma once
#include "Obstaculo.h"
#include "Ids.h"

namespace InvasaoAlienigena {
	namespace Obstaculo {
		class Caixote : public Obstaculo{
		private:
			int vel_x;

		public:
			Caixote(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
			Caixote(nlohmann::json fonte);
			~Caixote();
			void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
			void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
			void Mover(float dx, float dy);
		};
	}
}

