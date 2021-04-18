#include "Obstaculo.h"

namespace InvasaoAlienigena {
	namespace Obstaculo {
		Obstaculo::Obstaculo(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
			Colidivel(pos, vel, ID, caminhoTextura)
		{

		}

		Obstaculo::~Obstaculo()
		{

		}

		void Obstaculo::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc)
		{
			gf.carregarTextura(caminho);

			dimensoes = gf.getTamanho(caminho);

			gc.adicionarColidivel(this);
		}
	}
}
