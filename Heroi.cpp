#include "Heroi.h"
#include "Desenhavel.h"

#include <iostream>


namespace Jogo {
    namespace Desenhaveis {
        Heroi::Heroi(Vetor::Vetor2F pos) : Colidivel(pos, Vetor::Vetor2F(), Ids::heroi, "../imagens/heroi1.png"){
                vel_x = 80;
                vel_y = 330;
            }

        Heroi::~Heroi() {


        }

        void Heroi::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);
            
            dimensoes = gf.getTamanho(caminho);

            chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });

            gc.adicionarColidivel(this);

           

        }
        /*Vetor2F Heroi::getPos() const
        {
            return posicao;
        }
        void Heroi::setPos(Vetor2F pos)
        {
            posicao = pos;
        }*/

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

        void Heroi::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {
            std::string imprimir;

            /*if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara) {
                float dist_x = (static_cast<float>(dimensoes.x) + posicao.x) / 2 - std::abs(posicao.x + static_cast<float>(dimensoes.x) / 2 - posicaoOutro.x - dimensoes.x / 2);
                float dist_y = (static_cast<float>(dimensoes.y) + posicao.y) / 2 - std::abs(posicao.y + static_cast<float>(dimensoes.y) / 2 - posicaoOutro.y - dimensoes.y / 2);


                if (dist_x * dist_y > 0.001 * dimensoes.x * dimensoes.y) {
                    if (dist_x < dist_y){
                        //colisao em X
                        if( dist_x >std::abs()){
                            
                        }
                    }
                }
            }*/
            switch (idOutro) {
            case Ids::vilao:
                
                posicao.x -= 0.3;
                vidas -= 1;
                imprimir = "ai ui ui";
                break;
            case Ids::inimigo:
                posicao.x -= 0.9;
                vidas -= 1;
                imprimir = "ai ui ui";
                break;
            case Ids::parede_up:


                posicao.x += 0.9;
                posicao.y -= 0.9;

                
                /*if (posicao.x >= Ids::parede_up)
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
                }
                */

                imprimir = "fui ludibriado";
                break;
            case Ids::parede_clara:
                
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
        /*void Heroi::ajustar()
        {
           
            posicao += Vetor2F(0,0);

            if (ajustar.y < 0) {
                isJumping = false;

                vel_y = 0;
            }
            else if (ajustar.y > 0) {
                vel_y = 0;
            }
        }*/
       
    }
        
}