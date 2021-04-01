#include "Heroi.h"
#include "Desenhavel.h"

#include <iostream>


namespace Jogo {
    //namespace Desenhaveis {
        Heroi::Heroi(Vetor2F pos /*= {0.0f , 0.0f}*/) : Colidivel(pos, Vetor2F(), Ids::heroi, "boneco.png") {

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

            if (posicao.y < 700 && isJumping == false)
            {
                v.y += 0.3;
            }

            if (e.type == sf::Event::KeyPressed) {


                switch (e.key.code) {
                case sf::Keyboard::Key::Right:
                    v.x += 30;
                    /* code */
                    break;
                case sf::Keyboard::Key::Left:
                    v.x -= 30;
                    /* code */
                    break;
                case sf::Keyboard::Key::Up:
                    v.y -= 30;
                    isJumping = true;
                    /* code */
                    /*gravidade do personagem*/
                    break;
                case sf::Keyboard::Key::Down:
                    v.y += 30;
                    /* code */
                    break;
                default:
                    break;
                }
            }
            else if (e.type == sf::Event::KeyReleased) {
                switch (e.key.code) {
                case sf::Keyboard::Key::Right:
                    v.x -= 30;
                    break;
                case sf::Keyboard::Key::Left:
                    v.x += 30;
                    break;
                case sf::Keyboard::Key::Up:
                    v.y += 30;
                    break;
                case sf::Keyboard::Key::Down:
                    v.y -= 30;
                    break;
                default:
                    break;
                }
            }
        }

        void Heroi::colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro) {
            std::string imprimir;

            switch (idOutro) {
            case Ids::vilao:

                posicao.x -= 0.3;
                vidas -= 1;
                imprimir = "ai ui ui";
                break;
            case Ids::parede_up:

                posicao.x += 0.9;
                posicao.y -= 0.9;

                /*
                if (posicao.x >= Ids::parede_up)
                {
                    posicao.x += 0.5;
                    if (posicao.y > Ids::parede_up) posicao.y += 0.5;
                    //else if (posicao.y < Ids::parede_up) posicao.y -= 0.5;
                }
                else if (posicao.y < Ids::parede_up)
                {
                    posicao.y -= 0.5;
                }
                else
                {
                    /*posicao.x += 0.5;
                    if (posicao.y > Ids::parede_up) posicao.y += 0.5;
                    else if (posicao.y < Ids::parede_up) posicao.y -= 0.5;
                }*/


                imprimir = "fui ludibriado";
                break;
            case Ids::parede_clara:
                if (posicao.x > Ids::parede_clara)
                {
                    posicao.x += 0.5;
                    posicao.y -= 0.5;
                }
                else if (posicao.x < Ids::parede_clara)
                {
                    posicao.x -= 0.5;
                    posicao.y += 0.5;
                }
                imprimir = "fui ludibriado";
                break;
            case Ids::fundo:
                //posicao.y += 1;
                imprimir = "cai";
                break;
            case Ids::semID:
                imprimir = "mano o que ta acontecendo";
                break;
            case Ids::espinho_fundo:
                posicao.y -= 0.5;
                vidas -= 1;
                imprimir = "pontudo";
                break;
            case Ids::porta:
                //processarCodigo(comecarSegundaFase);
                imprimir = "estou livre";
                break;
            default:
                imprimir = "eita";
            }

            std::cout << imprimir << std::endl;
        }
    //}
        
}