#include "Projetil.h"
namespace InvasaoAlienigena {
	namespace Projetil {
		Projetil::Projetil(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
			Colidivel(pos, vel, Ids::projetil, "../imagens/projetil.png")
		{

		}

		Projetil::Projetil(nlohmann::json fonte) : Projetil({ fonte["posicao"] }, { fonte["velocidade"] }) {

		}

		Projetil::Projetil()
		{
		}

		Projetil::~Projetil()
		{
		}

		/*const sf::FloatRect Projetil::getLimites() const
		{
			return this->projetil.getGlobalBounds();
		}*/

		void Projetil::atualizar(float t)
		{
			posicao += v1 * t;
		}

		void Projetil::desenhar(Gerenciador::GerenciadorGrafico& g)
		{
			g.desenhar(caminho, posicao);
			g.centralizar(posicao);
		}

		/*void Projetil::render(sf::RenderTarget* alvo)
		{
			alvo->draw(this->projetil);
		}*/

		void Projetil::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
			gf.carregarTextura(caminho);

			dimensoes = gf.getTamanho(caminho);

			gc.adicionarColidivel(this);
		}

		void Projetil::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {


		}
	}
}