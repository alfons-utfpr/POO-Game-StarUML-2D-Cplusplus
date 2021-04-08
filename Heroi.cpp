#include "Heroi.h"
#include "Desenhavel.h"
#include "GerenciadorTelas.h"
#include "SegundaFase.h"
#include <iostream>


namespace Jogo {
    namespace Entidades {
        namespace Desenhaveis {
            Heroi::Heroi(Vetor::Vetor2F pos) : Colidivel(pos, Vetor::Vetor2F(), Ids::heroi, "../imagens/heroi1.png") {
                vel_x = 80;
                vel_y = 80;
                vidas = 3;
            }

            Heroi::~Heroi() {


            }

            void Heroi::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
                gf.carregarTextura(caminho);

                dimensoes = gf.getTamanho(caminho);

                chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });

                gc.adicionarColidivel(this);



            }

            void Heroi::atualizar(float t) {
                if (std::abs(v.y) <= 5)
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
                }

                posicao += v * t;
            }

            void Heroi::desenhar(Gerenciador::GerenciadorGrafico& g) {

                g.desenhar(caminho, posicao);
                g.centralizar(posicao);
            }

            void Heroi::inicializarComJSON(nlohmann::json fonte) {
                posicao = { fonte["posicao"] };
            }

            void Heroi::tratarEvento(const sf::Event& e) {
                if (e.type == sf::Event::KeyPressed) {


                    switch (e.key.code) {
                    case sf::Keyboard::Key::Right:
                        v.x += vel_x;
                        break;
                    case sf::Keyboard::Key::Left:
                        v.x -= vel_x;
                        break;
                    case sf::Keyboard::Key::Up:
                        v.y -= vel_y;
                        break;
                    case sf::Keyboard::Key::Down:
                        v.y += vel_y;
                        break;
                    default:
                        break;
                    }
                }
                else if (e.type == sf::Event::KeyReleased) {
                    switch (e.key.code) {
                    case sf::Keyboard::Key::Right:
                        v.x -= vel_x;
                        break;
                    case sf::Keyboard::Key::Left:
                        v.x += vel_x;
                        break;
                    case sf::Keyboard::Key::Up:
                        if (!isJumping) {
                            isJumping = true;
                            vel_y -= 2 * vel_y;
                        }
                        break;
                    case sf::Keyboard::Key::Down:
                        v.y -= vel_x;
                        break;
                    default:
                        break;
                    }
                }
            }

            void Heroi::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {
                std::string imprimir;
                
                if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara) {
                    float dist_x = (static_cast<float>(dimensoes.x) + posicao.x) / 2 - std::abs(posicao.x + static_cast<float>(dimensoes.x) / 2 - posicaoOutro.x - dimensoes.x / 2);
                    float dist_y = (static_cast<float>(dimensoes.y) + posicao.y) / 2 - std::abs(posicao.y + static_cast<float>(dimensoes.y) / 2 - posicaoOutro.y - dimensoes.y / 2);


                    if (dist_x * dist_y > .001 * dimensoes.x * dimensoes.y) {
                        if (dist_x < dist_y) {
                            imprimir = "funcao1";
                            //colisao em X
                            if (dist_x > std::abs(ajustes.x)) {
                                posicao.x += dist_x * (posicao.x + static_cast<float>(dimensoes.x) / 2 > posicaoOutro.x + posicao.x / 2 ? 1 : -1);
                            }
                        }
                        else {
                            //colisao em Y
                            imprimir = "funcao2";
                            if (dist_y > std::abs(ajustes.y)) {
                                posicao.y += dist_y * (posicao.y + static_cast<float>(dimensoes.y) / 2 > posicaoOutro.y + posicao.y / 2 ? 1 : -1);
                            }
                        }
                    }
                }

                else if (idOutro == Ids::vilao || idOutro == Ids::inimigo) {
                    vidas--;

                    if (vidas == 0) {
                        imprimir = "perdeu";
                    }
                }

                else if (idOutro == Ids::porta)
                {
                    //proximo nivel
                }
                switch (idOutro) {
                case Ids::vilao:

                    posicao.x -= 0.3;
                    vidas -= 1;
                    imprimir = "ai ui ui";
                    break;
                case Ids::inimigo:
                    posicao.x -= 0.9;
                    vidas -= 1;
                    break;
                case Ids::parede_up:
                    break;
                case Ids::parede_clara:

                    break;
                case Ids::fundo:

                    break;
                case Ids::semID:

                    break;
                case Ids::espinho_fundo:
                    posicao.y -= 0.5;
                    vidas -= 1;

                    break;
                case Ids::porta:

                    break;
                case Ids::caixote:

                    break;
                default:
                    imprimir = "eita";
                }

                std::cout << imprimir << std::endl;

            }
            void Heroi::ajustar()
            {
                ajustes = Vetor::Vetor2F(0, 0);
                posicao += ajustes;
                

                if (ajustes.y < 0) {
                    isJumping = false;

                    v.y = 0;
                }
                else if (ajustes.y > 0) {
                    v.y = 0;
                }
            }
            const int Heroi::getVidas() const
            {
                return vidas;
            }
        }
    }
}