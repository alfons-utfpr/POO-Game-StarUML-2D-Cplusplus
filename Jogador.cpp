#include "Jogador.h"
//#include "Desenhavel.h"
#include <iostream>


namespace InvasaoAlienigena {
    namespace Entidades {
        namespace Desenhaveis {
            Jogador::Jogador(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
                Colidivel(pos, vel, ID, caminhoTextura) {

            }

            Jogador::~Jogador() {

            }

            void Jogador::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
                gf.carregarTextura(caminho);

                dimensoes = gf.getTamanho(caminho);

                //chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });

                gc.adicionarColidivel(this);

            }

            void Jogador::atualizar(float t) {
                posicao += v * t;
            }

            void Jogador::desenhar(Gerenciador::GerenciadorGrafico& g) {

                g.desenhar(caminho, posicao);
                g.centralizar(posicao);
            }

			void Jogador::finalFase()
			{

			}


        }
    }
}