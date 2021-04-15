#include "Frida.h"
#include "Desenhavel.h"
#include <iostream>


namespace Jogo {
    namespace Entidades {
        namespace Desenhaveis {
            Frida::Frida(Vetor::Vetor2F pos) : Colidivel(pos, Vetor::Vetor2F(), Ids::frida, "../imagens/boneco.png") {
                vel_x = 80;
                vel_y = 80;
                vidas = 3;
            }

            Frida::~Frida() {

            }

            void Frida::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
                gf.carregarTextura(caminho);

                dimensoes = gf.getTamanho(caminho);

                chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });

                gc.adicionarColidivel(this);

            }

            void Frida::atualizar(float t) {
                posicao += v * t;
            }

            void Frida::desenhar(Gerenciador::GerenciadorGrafico& g) {

                g.desenhar(caminho, posicao);
                g.centralizar(posicao);
            }

            void Frida::inicializarComJSON(nlohmann::json fonte) {
                posicao = { fonte["posicao"] };
            }

            void Frida::tratarEvento(const sf::Event& e) {

                if (e.type == sf::Event::KeyPressed) {

                    switch (e.key.code) {
                    case sf::Keyboard::Key::D:
                        v.x += vel_x;
                        break;
                    case sf::Keyboard::Key::A:
                        v.x -= vel_x;
                        break;
                    case sf::Keyboard::Key::W:
                        v.y -= vel_y;
                        isJumping = true;
                        break;
                    case sf::Keyboard::Key::S:
                        v.y += vel_y;
                        break;
                    default:
                        break;
                    }
                }
                else if (e.type == sf::Event::KeyReleased) {
                    switch (e.key.code) {
                    case sf::Keyboard::Key::D:
                        v.x -= vel_x;
                        break;
                    case sf::Keyboard::Key::A:
                        v.x += vel_x;
                        break;
                    case sf::Keyboard::Key::W:
                        v.y += vel_y;
                        break;
                    case sf::Keyboard::Key::S:
                        v.y -= vel_y;
                        break;
                    default:
                        break;
                    }
                }
            }

            void Frida::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {
                std::string imprimir;
                if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara) {
                    float dist_x = (static_cast<float>(dimensoes.x) + posicao.x) / 2 - std::abs(posicao.x + static_cast<float>(dimensoes.x) / 2 - posicaoOutro.x - dimensoes.x / 2);
                    float dist_y = (static_cast<float>(dimensoes.y) + posicao.y) / 2 - std::abs(posicao.y + static_cast<float>(dimensoes.y) / 2 - posicaoOutro.y - dimensoes.y / 2);


                    if (dist_x * dist_y > .001 * dimensoes.x * dimensoes.y) {
                        if (dist_x < dist_y) {
                            //colisao em X
                            if (dist_x > std::abs(ajustes.x)) {
                                posicao.x += dist_x * (posicao.x + static_cast<float>(dimensoes.x) / 2 > posicaoOutro.x + posicao.x / 2 ? 1 : -1);
                            }
                        }
                        else {
                            //colisao em Y
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

                else if (idOutro == Ids::espinho_fundo) {
                    vidas--;
                    float dist_y = (static_cast<float>(dimensoes.y) + posicao.y) / 2 - std::abs(posicao.y + static_cast<float>(dimensoes.y) / 2 - posicaoOutro.y - dimensoes.y / 2);
                    if (dist_y > std::abs(ajustes.y)) {
                        posicao.y += dist_y * (posicao.y + static_cast<float>(dimensoes.y) / 2 > posicaoOutro.y + posicao.y / 2 ? 1 : -1);
                    }
                }

                else if (idOutro == Ids::porta)
                {
                    //proximo nivel
                }
            }
            void Frida::ajustar()
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
            const int Frida::getVidas() const
            {
                return vidas;
            }
        }
    }
}