#include "Heroi.h"
#include "Desenhavel.h"
#include <iostream>

namespace exercicio {

    Heroi::Heroi(Vetor2F pos /*= {0.0f , 0.0f}*/) : Colidivel(pos, Vetor2F(), Ids::heroi, "boneco.png") {

    }

    Heroi::~Heroi() {

        
    }

    void Heroi::inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc) {
        gf.carregarTextura(caminho);

        dimensoes = gf.getTamanho(caminho);

        chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });

        gc.adicionarColidivel(this);

    }

    void Heroi::atualizar(float t) {
        posicao += v * t;
    }

    void Heroi::desenhar(GerenciadorGrafico& g) {

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
            
            imprimir = "ai ui ui";
            break;
        case Ids::prisao:
            imprimir = "fui ludibriado";
            break;
        case Ids::fundo:
            imprimir = "cai";
            break;
        case Ids::semID:
            imprimir = "mano o que ta acontecendo";
            break;
        case Ids::espinho:
            imprimir = "pontudo";
            break;
        case Ids::porta:
            imprimir = "estou livre";
            break;
        case Ids::parede_clara:
            posicao -= 10.0f;
            imprimir = "bonk";
            break;
        default:
            imprimir = "eita";
        }

        std::cout << imprimir << std::endl;
    }
    
}