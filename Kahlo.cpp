#include "Kahlo.h"
#include "Desenhavel.h"
//#include "GerenciadorTelas.h"
#include "Hospital.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Entidades {
        namespace Desenhaveis {
            Kahlo::Kahlo(Vetor::Vetor2F pos) : 
                Jogador(pos, Vetor::Vetor2F(), Ids::kahlo, "../imagens/Kahlo.png") {
                vel_x = 80;
                vel_y = 80;
                alt_pulo = 80;
                vidas = 3;
                //codigoRetorno = CodigoRetorno::comecarSegundaFase;
            }

            Kahlo::~Kahlo() {

            }

           /* nlohmann::json Kahlo::paraJSON() {
                nlohmann::json json;

                json["amigos"] = proj.paraJSON();

                return json;

            }*/

            void Kahlo::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
                gf.carregarTextura(caminho);

                dimensoes = gf.getTamanho(caminho);

                chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });
                gc.adicionarColidivel(this);

                proj.inicializarDesenhaveis(gf, ge, gc);


            }

            void Kahlo::atualizar(float t) {
                //Gravidade
                /*
                vel_y += 1.0 * gravidade;
                
                if (std::abs(v.y) > velmax_y) 
                {
                    v.y = velmax_y * (v.y > 0 ? 1 : -1);
                }
                
                    //v.y = sqrtf(2 * gravidade * alt_pulo);
                */
                posicao += v * t;
            }

            void Kahlo::desenhar(Gerenciador::GerenciadorGrafico& g) {

                g.desenhar(caminho, posicao);
                g.centralizar(posicao);
            }

            void Kahlo::inicializarComJSON(nlohmann::json fonte) {
                posicao = { fonte["posicao"] };
                nlohmann::json json;

                json["amigos"] = proj.paraJSON();

            }

            void Kahlo::tratarEvento(const sf::Event& f) {
                if (f.type == sf::Event::KeyPressed) {
                    switch (f.key.code) {
                    case sf::Keyboard::Key::Right:
                        v.x += vel_x;
                        break;
                    case sf::Keyboard::Key::Left:
                        v.x -= vel_x;
                        break;
                    case sf::Keyboard::Key::Up:
                        
                        this->v.y = -sqrtf(2 * gravidade * alt_pulo);
                        
                        break;
                    case sf::Keyboard::Key::Down:
                        v.y += vel_y;
                        break;

                    case sf::Keyboard::Key::J:
                        std::cout << "J" << std::endl;
                        proj.inserir(new Projetil::Projetil(Vetor::Vetor2F(80.0f, 120.0f), Vetor::Vetor2F(15, 0)));
                        break;
                    default:
                        break;
                    }
                }
                else if (f.type == sf::Event::KeyReleased) {
                    switch (f.key.code) {
                        case sf::Keyboard::Key::Right:
                            v.x -= vel_x;
                            break;
                        case sf::Keyboard::Key::Left:
                            v.x += vel_x;
                            break;
                        case sf::Keyboard::Key::Up:                            
                            this->v.y = sqrtf(2 * gravidade * alt_pulo);
                            break;
                        case sf::Keyboard::Key::Down:
                            v.y -= vel_y;
                            break;
                        case sf::Keyboard::Key::J:
                            proj.inserir(new Projetil::Projetil(Vetor::Vetor2F(80.0f, 120.0f), Vetor::Vetor2F(15, 0)));
                            break;
                        default:
                            break;
                    }
                }
            }
            
            /*void Kahlo::ajustar()
            {
                ajustes = Vetor::Vetor2F(0, 0);
                posicao += ajustes;
                if (ajustes.y < 0) {
                    taPulando = false;
                    v.y = 0;
                }
                else if (ajustes.y > 0) {
                    v.y = 0;
                }
            }*/

            const int Kahlo::getVidas() const
            {
                return vidas;
            }

           
        }
    }
}