#include "PrimeiraFase.h"
#include "SegundoHeroi.h"
#include "LagartoVerde.h"
#include "Caixote.h"
#include "Tile.h"
#include "Alien.h"
#include <time.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <random>

namespace Jogo {
    namespace Fase {
        PrimeiraFase::PrimeiraFase(Gerenciador::GerenciadorGrafico& gg, Entidades::Desenhaveis::Heroi* jogador1, Entidades::Desenhaveis::Heroi* jogador2) : Fase{ gg,
        new Gerenciador::GerenciadorTiles{
         {
             new Tile::Tile(Ids::armadilha_direita, "armadilha_direita.png"),
             new Tile::Tile(Ids::armadilha_esquerda,"armadilha_esquerda.png"),
             new Tile::Tile(Ids::espinho,"espinho.png"),
             new Tile::Tile(Ids::espinho_direita,"espinho_direita.png"),
             new Tile::Tile(Ids::espinho_esquerda,"espinho_esquerda.png"),
             new Tile::Tile(Ids::teste_fundo2,"teste_fundo2.png"),
             new Tile::Tile(Ids::parede_up, "parede_up.png"),
             new Tile::Tile(Ids::parede, "parede.png"),
             new Tile::Tile(Ids::espinho_fundo,"espinho_fundo2.png"),
             new Tile::Tile(Ids::esquerda2,"esquerda2.png"),
             new Tile::Tile(Ids::fundo,"fundo.png"),
             new Tile::Tile(Ids::fundo1,"fundo1.png"),
             new Tile::Tile(Ids::parede_clara,"parede_clara.png"),
             new Tile::Tile(Ids::parede_up,"parede_clara.png"),
             new Tile::Tile(Ids::porta,"porta.png"),
             new Tile::Tile(Ids::teste_fundo,"teste_fundo.png"),
             new Tile::Tile(Ids::espinho_fundo,"espinho_fundo.png"),
             new Tile::Tile(Ids::teste_chama,"teste_chama.png"),
             new Tile::Tile(Ids::teste_fundo2,"teste_fundo2.png"),
             new Tile::Tile(Ids::espinho_fundo2,"espinho_fundo2.png"),
             new Tile::Tile(Ids::esquerda2,"esquerda2.png"),
            },
            {32.0f, 32.0f}, "../TileMap/TileMap.json"
          }
          , jogador1, jogador2 } {

        }

        nlohmann::json PrimeiraFase::paraJSON() {
            nlohmann::json json;

            json["amigos"] = listaAmigos.paraJSON();

            return json;

        }

        void PrimeiraFase::carregar(const std::string& caminho) {
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
                case Ids::segundoHeroi && Ids::heroi:
                    if (jogador1 && jogador2) {
                        jogador1->inicializarComJSON(amigo);
                        jogador2->inicializarComJSON(amigo);
                        listaAmigos.inserir(jogador1);
                        listaAmigos.inserir(jogador2);
                    }
                case Ids::vilao:
                    
                    listaAmigos.inserir(new Desenhaveis::Alien(amigo));
                    break;
                case Ids::inimigo:
                    listaAmigos.inserir(new Desenhaveis::LagartoVerde(amigo));
                    break;
                default:
                    break;
                }
            }

            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);
        }

        void PrimeiraFase::inicializar() {
            srand(time(NULL));
            
            if (jogador1) listaAmigos.inserir(new Entidades::Desenhaveis::Heroi(Vetor::Vetor2F(70.0f, 100.0f)));
            
            else if (jogador1 && jogador2)
            {
                listaAmigos.inserir(new Entidades::Desenhaveis::Heroi(Vetor::Vetor2F(40.0f, 50.0f)));
                listaAmigos.inserir(new Entidades::Desenhaveis::SegundoHeroi(Vetor::Vetor2F(50.0f, 50.f)));
            }

            for (int i = 0; i < 5; i++) {
                
                listaAmigos.inserir(new Desenhaveis::Alien(Vetor::Vetor2F(rand()% 800 - 100, rand() % 600-120), Vetor::Vetor2F(15, 0)));
            }
            for (int i = 0; i < 5; i++) {
               
                listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(rand() % 700 - 100, rand() % 550 - 105), Vetor::Vetor2F(10, 0)));
               
            }
            for (int i = 0; i < 5; i++)
            {
                listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(rand() % 300, rand() % 500), Vetor::Vetor2F(0, 0)));
            }
            
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(100, 110.0f), Vetor::Vetor2F(0, 0)));
            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);

        }
    }
}