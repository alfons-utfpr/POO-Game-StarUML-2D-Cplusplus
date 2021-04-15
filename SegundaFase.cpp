#include "SegundaFase.h"
#include "Chefao.h"
#include "Caixote.h"
#include "BuracoInfinito.h"
#include "LagartoVerde.h"
#include "SegundoHeroi.h"
#include "Tile.h"
#include "Alien.h"
#include <fstream>

namespace Jogo {
    namespace Fase {
        SegundaFase::SegundaFase(Gerenciador::GerenciadorGrafico& gg, Entidades::Desenhaveis::Heroi* jogador1, Entidades::Desenhaveis::Heroi* jogador2) : Fase{ gg,
        new Gerenciador::GerenciadorTiles{
        {
            new Tile::Tile(Ids::armadilha_direita, "armadilha_direita.png"),
            new Tile::Tile(Ids::armadilha_esquerda,"armadilha_esquerda.png"),
            new Tile::Tile(Ids::espinho,"espinho.png"),
            new Tile::Tile(Ids::espinho_direita,"espinho_direita.png"),
            new Tile::Tile(Ids::espinho_esquerda,"espinho_esquerda.png"),
            new Tile::Tile(Ids::teste_fundo2,"teste_fundo2.png"),
            new Tile::Tile(Ids::espinho_fundo,"espinho_fundo2.png"),
            new Tile::Tile(Ids::esquerda2,"esquerda2.png"),
            new Tile::Tile(Ids::fundo,"fundo.png"),
            new Tile::Tile(Ids::fundo1,"fundo1.png"),
            new Tile::Tile(Ids::parede, "parede.png"),
            new Tile::Tile(Ids::parede_clara,"parede_clara.png"),
            new Tile::Tile(Ids::parede_up,"parede_clara.png"),
            new Tile::Tile(Ids::porta,"porta.png"),
            new Tile::Tile(Ids::prisao,"prisao.png"),
            new Tile::Tile(Ids::teste,"teste.png"),
            new Tile::Tile(Ids::teste_fundo,"teste_fundo.png"),
            new Tile::Tile(Ids::espinho_fundo,"espinho_fundo.png"),
            },
             {32.0f, 32.0f}, "../TileMap/tilemapJogo.json"
           }
           , jogador1 } {

        }

        nlohmann::json SegundaFase::paraJSON() {
            nlohmann::json json;

            json["amigos"] = listaAmigos.paraJSON();

            return json;

        }

        void SegundaFase::carregar(const std::string& caminho) {
            std::ifstream arquivo(caminho);
            if (arquivo.fail()) throw "arquivo nao encontrado!";
            nlohmann::json j;
            arquivo >> j;

            for (nlohmann::json amigo : j["amigos"]) {
                switch (static_cast<int> (amigo["id"]))
                {
                case Ids::heroi:
                    if (jogador1) {
                        jogador1->inicializarComJSON(amigo);
                        listaAmigos.inserir(jogador1);
                    }
                    break;
                case Ids::segundoHeroi:
                    if (jogador2) {
                        jogador2->inicializarComJSON(amigo);
                        listaAmigos.inserir(jogador2);
                    }
                    break;
                case Ids::vilao:
                    listaAmigos.inserir(new Desenhaveis::Alien(amigo));
                    break;
                case Ids::inimigo:
                    listaAmigos.inserir(new Desenhaveis::LagartoVerde(amigo));
                    break;
                case Ids::chefao:
                    listaAmigos.inserir(new Desenhaveis::Chefao(amigo));
                default:
                    break;
                }
            }

            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);
        }

        void SegundaFase::inicializar() {
            //listaAmigos.inserir(new Entidades::Desenhaveis::SegundoHeroi(Vetor::Vetor2F(250.0f, 170.0f)));
            if (jogador1) listaAmigos.inserir(new Entidades::Desenhaveis::Heroi(Vetor::Vetor2F(200.0f, 160.0f)));
            
            if (jogador1 && jogador2)
            {
                listaAmigos.inserir(new Entidades::Desenhaveis::Heroi(Vetor::Vetor2F(200.0f, 150.0f)));
                listaAmigos.inserir(new Entidades::Desenhaveis::SegundoHeroi(Vetor::Vetor2F(250.0f, 170.0f)));
            }
            
            for (int i = 0; i < 5; i++) {

                listaAmigos.inserir(new Desenhaveis::Alien(Vetor::Vetor2F(rand() % 800 - 100, rand() % 600 - 120), Vetor::Vetor2F(15, 0)));
            }
            for (int i = 0; i < 5; i++) {

                listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(rand() % 700 - 100, rand() % 550 - 105), Vetor::Vetor2F(10, 0)));

            }
            for (int i = 0; i < 5; i++)
            {
                listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(rand()%300, rand()%500), Vetor::Vetor2F(0, 0)));
            }
            listaAmigos.inserir(new Obstaculo::BuracoInfinito(Vetor::Vetor2F(300.0f, 250.0f), Vetor::Vetor2F(0, 0)));
            
            listaAmigos.inserir(new Desenhaveis::Chefao(Vetor::Vetor2F(90.0f, 200.0f), Vetor::Vetor2F(10, 0)));
            
            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);

        }
    }
}