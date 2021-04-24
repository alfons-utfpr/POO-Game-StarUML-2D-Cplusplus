#include "Fase.h"
#include "GerenciadorTelas.h"
#include "Robotao.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Fase {
        Fase::Fase(Gerenciador::GerenciadorGrafico& gg, Gerenciador::GerenciadorTiles* gt, Entidades::Desenhaveis::Kahlo* jogador1, Entidades::Desenhaveis::Frida* jogador2) :
            gerenciadorGrafico{ gg },
            jogador1{ jogador1 },
            jogador2{ jogador2 },
            gerenciadorTiles{ gt },
            IdOuvinteFecharTela{ gerenciadorEventos.adicionarOuvinteOutro([this](const sf::Event& e) {botaoFecharTelaApertado(e); }) },
            IdOuvinteEntrarMenu{ gerenciadorEventos.adicionarOuvinteTeclado([this](const sf::Event& e) {botaoEntrarMenuApertado(e); }) },
            codigoRetorno{ continuar }
            //continuarFase {comecarSegundaFase}
            //continuar{true}
        {

            gerenciadorTiles->inicializar(gerenciadorGrafico, gerenciadorEventos);
            gerenciadorEventos.setJanela(gerenciadorGrafico.getJanela());
            gerenciadorColisoes.setGerenciadorTiles(gerenciadorTiles);
            pontos = 0;
            this->initTexturas();
        }

        Fase::~Fase() {
            listaAmigos.removerPrimeiro(jogador1);
            listaAmigos.removerPrimeiro(jogador2);
            listaAmigos.destruirDesenhaveis();
            //listaAmigos.removerPrimeiro(projeteis);
            delete gerenciadorTiles;
            //delete &projeteis;

            /*for (auto &i : this->textura) {
                delete i.second;
            }

            for (auto *i : this->textura) {
                delete i;
            }*/
        }

        int Fase::executar() {
            codigoRetorno = continuar;
            double t = relogio.getTempo();

            gerenciadorEventos.tratarEventos();
            listaAmigos.atualizarDesenhaveis(t);
            gerenciadorColisoes.verificarColisoes();

            gerenciadorTiles->desenhar(gerenciadorGrafico);
            listaAmigos.desenharDesenhaveis(gerenciadorGrafico);

            //this->atualizarProjetil();

            return codigoRetorno;
        }

        /*int Fase::finalFase()
        {
            //return continuarFase;
        }*/

        void Fase::botaoFecharTelaApertado(const sf::Event evento) {
            if (evento.type == sf::Event::Closed) setCodigoRetorno(terminarJogo);
        }

        void Fase::botaoEntrarMenuApertado(const sf::Event evento) {
            if (evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::Key::Escape) {
                setCodigoRetorno(irMenuPausa);
                relogio.pausar();
            }
        }

        void Fase::initFont()
        {
            if (this->font.loadFromFile("../fonte/CantoraOne-Regular.ttf")) {
                std::cout << "Erro na fonte" << std::endl;
            }
        }

		void Fase::initTexturas()
		{
            //this->textura["BULLET"] new sf::Texture();
            //this->textura["BULLET"].loadFromFile("imagens/projetil.png");
		}

        void Fase::setCodigoRetorno(int codigo) {
            codigoRetorno = codigo;
        }
    }
}