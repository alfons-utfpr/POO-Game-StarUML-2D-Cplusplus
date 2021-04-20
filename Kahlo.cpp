#include "Kahlo.h"
#include "Desenhavel.h"
//#include "GerenciadorTelas.h"
#include "Hospital.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Entidades {
        namespace Desenhaveis {
            Kahlo::Kahlo(Vetor::Vetor2F pos) : 
                Jogador(pos, Vetor::Vetor2F(), Ids::kahlo, "../imagens/heroi1.png") {
                vel_x = 80;
                vel_y = 80;
                vidas = 3;
  
            }

            Kahlo::~Kahlo() {

            }

            void Kahlo::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
                gf.carregarTextura(caminho);

                dimensoes = gf.getTamanho(caminho);

                chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });

                gc.adicionarColidivel(this);

            }

            void Kahlo::atualizar(float t) {
                /*if (std::abs(v.y) <= 5)
                {
                    isJumping = false;
                    v.y = 0;
                } 
                
                else 
                {
                    isJumping = true;
                    v.y += 50 * t;
                }

                if (std::abs(v.x) > vel_x) 
                {
                    v.x = vel_x * (v.x > 0 ? 1 : -1);
                }

                if (std::abs(v.y) > vel_y) 
                {
                    v.y = vel_y * (v.y > 0 ? 1 : -1);
                }*/

                posicao += v1 * t;
            }

            void Kahlo::desenhar(Gerenciador::GerenciadorGrafico& g) {

                g.desenhar(caminho, posicao);
                g.centralizar(posicao);
            }

            void Kahlo::inicializarComJSON(nlohmann::json fonte) {
                posicao = { fonte["posicao"] };
            }

            void Kahlo::tratarEvento(const sf::Event& f) {
                if (f.type == sf::Event::KeyPressed) {


                    switch (f.key.code) {
                    case sf::Keyboard::Key::Right:
                        v1.x += vel_x;
                        break;
                    case sf::Keyboard::Key::Left:
                        v1.x -= vel_x;
                        break;
                    case sf::Keyboard::Key::Up:
                        v1.y -= vel_y;
                        break;
                    case sf::Keyboard::Key::Down:
                        v1.y += vel_y;
                        break;
                    default:
                        break;
                    }
                }
                else if (f.type == sf::Event::KeyReleased) {
                    switch (f.key.code) {
                    case sf::Keyboard::Key::Right:
                        v1.x -= vel_x;
                        break;
                    case sf::Keyboard::Key::Left:
                        v1.x += vel_x;
                        break;
                    case sf::Keyboard::Key::Up:
                        v1.y += vel_y;
                        /*if (!isJumping) {
                            isJumping = true;
                            vel_y -= 0.2 * vel_y;
                        }*/
                        break;
                    case sf::Keyboard::Key::Down:
                        v1.y -= vel_x;
                        break;
                    default:
                        break;
                    }
                }
            }

            void Kahlo::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {
                //std::string imprimir;
                
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

                else if (idOutro == Ids::alien || idOutro == Ids::lagartoVerde || idOutro == Ids::ciclope) {
                    vidas--;
                    if (vidas == 0)
                    {   
                        std::cout << "game over" << std::endl;
                    }

                    //std::cout << "perdeu" << vidas << std::endl;

                }

                else if (idOutro == Ids::espinho_fundo) {
                    vidas--;
                    Vetor::Vetor2F dist = posicao - posicaoOutro;
                    float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;

                    posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;
                }

                else if (idOutro == Ids::buracoInfinito) {
                    //bool Gerenciador::GerenciadorTelas::processarCodigo(int codigoRetorno);
                    //bool Gerenciador::GerenciadorEstados::executar();
                    
                }

                else if (idOutro == Ids::porta)
                {
                    //finalFase();
                    //Estado::Fase(false);
                   // Gerenciador::GerenciadorTelas::processarCodigo(comecarSegundaFase);
                }
            }
            void Kahlo::ajustar()
            {
                ajustes = Vetor::Vetor2F(0, 0);
                posicao += ajustes;

                if (ajustes.y < 0) {
                    isJumping = false;
                    //v.x = 0;
                    v1.y = 0;
                }
                else if (ajustes.y > 0) {
                    v1.y = 0;
                }
                //Entidades::EntidadeFisica::ajustar();
            }
            const int Kahlo::getVidas() const
            {
                return vidas;
            }

           
        }
    }
}