#include "Jogador.h"
//#include "Desenhavel.h"
#include <iostream>


namespace InvasaoAlienigena {
    namespace Entidades {
        namespace Desenhaveis {
            Jogador::Jogador(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
                Colidivel(pos, vel, ID, caminhoTextura) {
                    gravidade=981;
            }

            Jogador::~Jogador() {

            }

            void Jogador::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
                gf.carregarTextura(caminho);

                dimensoes = gf.getTamanho(caminho);

                //chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });

                gc.adicionarColidivel(this);

            }

            /*void Jogador::atualizar(float t) {
                posicao += v * t;
            }*/

            void Jogador::desenhar(Gerenciador::GerenciadorGrafico& g) {

                g.desenhar(caminho, posicao);
                g.centralizar(posicao);
            }

			void Jogador::finalFase()
			{

			}

            void Jogador::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro)
            {
                if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara || idOutro == Ids::robotao || idOutro == Ids::lagartoVerde ) {
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
            
                else if(idOutro == Ids::buracoInfinito){
                    posicao.x = 280.0f;
                    posicao.y = 150.0f;
                }

                else if (idOutro == Ids::espinho_fundo) {
                    //vidas--;
                    Vetor::Vetor2F dist = posicao - posicaoOutro;
                    float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;

                    posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;
                }

                else if (idOutro == Ids::porta)
                {
                    //Fase::Fase
                    //faseAtual->finalFase();
                }

                else
                    taPulando=true;

                /*
                else if (idOutro == Ids::robotao || idOutro == Ids::lagartoVerde) {
                    //vidas--;
                    posicao.x -=10.0f ;
                    //posicao.y = 150.0f;
                    
                }
                */

            }
        }
    }
}