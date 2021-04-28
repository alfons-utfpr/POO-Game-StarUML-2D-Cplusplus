#include "Projetil.h"
namespace InvasaoAlienigena {

		/*Projetil::Projetil(Gerenciador::GerenciadorGrafico& gg, Gerenciador::GerenciadorTiles* gt) :
			gerenciadorGrafico{ gg },
			gerenciadorTiles{ gt },
			continuar{ continuar }
		{

		}*/
		
		Projetil::Projetil(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
			Colidivel(pos, vel, Ids::projetil, "../imagens/projetil.png")
		{

		}


		Projetil::Projetil(nlohmann::json fonte) : Projetil({ fonte["posicao"] }, { fonte["velocidade"] }) {

		}


		Projetil::~Projetil()
		{
			
		}

		/*int Projetil::executar()
		{
			double t = relogio.getTempo();

			gerenciadorEventos.tratarEventos();
			proj.atualizarDesenhaveis(t);
			gerenciadorColisoes.verificarColisoes();

			gerenciadorTiles->desenhar(gerenciadorGrafico);
			proj.desenharDesenhaveis(gerenciadorGrafico);

			//this->atualizarProjetil();

			return continuar;
		}*/

		void Projetil::atualizar(float t)
		{
			posicao += v * t;
		}

		void Projetil::desenhar(Gerenciador::GerenciadorGrafico& g)
		{
			g.desenhar(caminho, posicao);
			//g.centralizar(posicao);
		}

		void Projetil::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
			gf.carregarTextura(caminho);

			dimensoes = gf.getTamanho(caminho);

			gc.adicionarColidivel(this);
		}

		void Projetil::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {
			if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara) {
				Vetor::Vetor2F dist = posicao - posicaoOutro;
				float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
				float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;
				if (sobr_x > sobr_y) {
					posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
				}
				else {
					posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;
				}
			}

		}
}