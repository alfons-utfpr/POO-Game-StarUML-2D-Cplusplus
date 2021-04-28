#include "Robotao.h"

#include <iostream>

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        Robotao::Robotao(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Inimigo(pos, vel, Ids::robotao, "../imagens/Robotao.png"), listaProjeteis() {

        }

        Robotao::Robotao(nlohmann::json fonte) : Robotao({ fonte["posicao"] }, { fonte["velocidade"] }) {
        }

        Robotao::~Robotao() {
            listaProjeteis.destruirDesenhaveis();
        }

        void Robotao::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void Robotao::atualizar(float t)
        {
            elapsed = clock.getElapsedTime();
            if (elapsed.asSeconds() > 2)
            {   
                if (!this->listaProjeteis.estaVazia())//checa se está vazio ou não. É bom fazer um método só para isso
                    this->listaProjeteis.removerPrimeiro(this->listaProjeteis.getInicio());

                this->listaProjeteis.inserir(static_cast<Desenhavel*> (new Projetil({posicao.x+10, posicao.y+10}, {5.f, 0.f})));
            }

            if (!this->listaProjeteis.estaVazia())
                this->listaProjeteis.atualizarDesenhaveis(t);

            this->posicao += this->v * t;
        }

        void Robotao::desenhar(Gerenciador::GerenciadorGrafico& g) {
            g.desenhar(caminho, posicao);
            
            if (!this->listaProjeteis.estaVazia())
                this->listaProjeteis.desenharDesenhaveis(g);
        }

        /*void Robotao::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {

            if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara || idOutro == Ids::caixote) {
                Vetor::Vetor2F dist = posicao - posicaoOutro;
                float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
                float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;
                if (sobr_x > sobr_y) {
                    posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
                }
                else {
                    posicao.x -= (dist.y > 0 ? -1 : 1) * sobr_y;
                }
            }
        }*/
    }
}