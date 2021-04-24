#pragma once
#include <SFML/Graphics.hpp>
#include "Desenhavel.h"
#include "Vetor2D.h"
#include "Colidivel.h"
#include "Relogio.h"
#include "ListaDesenhaveis.h"

namespace InvasaoAlienigena {
	namespace Projetil {
		class Projetil : public Colidivel
		{
		private:
			Lista::ListaDesenhaveis proj;
			Relogio relogio;
			bool continuar;

			//Gerenciador::GerenciadorGrafico& gerenciadorGrafico;
			//Gerenciador::GerenciadorEventos gerenciadorEventos;
			//Gerenciador::GerenciadorColisoes gerenciadorColisoes;
			//Gerenciador::GerenciadorTiles* gerenciadorTiles;
			

		public:
			Projetil(Gerenciador::GerenciadorGrafico& gg,Gerenciador::GerenciadorTiles* gt);
			Projetil(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);

			Projetil(nlohmann::json fonte);
			virtual ~Projetil();

			int executar();

			void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
			void atualizar(float t) override;
			void desenhar(Gerenciador::GerenciadorGrafico& g);
			void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) override;
		};
	}
}

