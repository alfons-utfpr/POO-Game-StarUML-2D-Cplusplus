#include "Manicomio.h"
#include "Kahlo.h"
#include "Frida.h"
#include "LagartoVerde.h"
#include "BuracoInfinito.h"
#include "Caixote.h"
#include "Tile.h"
#include "Robotao.h"
#include <time.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <random>

namespace InvasaoAlienigena {
    namespace Fase {
        Manicomio::Manicomio(Gerenciador::GerenciadorGrafico& gg, Entidades::Desenhaveis::Kahlo* jogador1, Entidades::Desenhaveis::Frida* jogador2) : Fase{ gg,
        new Gerenciador::GerenciadorTiles{
         {
             new Tile::Tile(Ids::armadilha_direita, "../imagens/armadilha_direita.png"),
             new Tile::Tile(Ids::armadilha_esquerda,"../imagens/armadilha_esquerda.png"),
             new Tile::Tile(Ids::espinho,"../imagens/espinho.png"),
             new Tile::Tile(Ids::espinho_direita,"../imagens/espinho_direita.png"),
             new Tile::Tile(Ids::espinho_esquerda,"../imagens/espinho_esquerda.png"),
             new Tile::Tile(Ids::teste_fundo2,"../imagens/teste_fundo2.png"),
             new Tile::Tile(Ids::parede_up, "../imagens/parede_up.png"),
             new Tile::Tile(Ids::parede, "../imagens/parede.png"),
             new Tile::Tile(Ids::espinho_fundo,"../imagens/espinho_fundo2.png"),
             new Tile::Tile(Ids::esquerda2,"../imagens/esquerda2.png"),
             new Tile::Tile(Ids::fundo,"../imagens/fundo.png"),
             new Tile::Tile(Ids::fundo1,"../imagens/fundo1.png"),
             new Tile::Tile(Ids::parede_clara,"../imagens/parede_clara.png"),
             new Tile::Tile(Ids::parede_up,"../imagens/parede_clara.png"),
             new Tile::Tile(Ids::porta,"../imagens/porta.png"),
             new Tile::Tile(Ids::teste_fundo,"../imagens/teste_fundo.png"),
             new Tile::Tile(Ids::espinho_fundo,"../imagens/espinho_fundo.png"),
             new Tile::Tile(Ids::teste_fundo2,"../imagens/teste_fundo2.png"),
             new Tile::Tile(Ids::espinho_fundo2,"../imagens/espinho_fundo2.png"),
             new Tile::Tile(Ids::esquerda2,"../imagens/esquerda2.png"),
            },
            {32.0f, 32.0f}, "../TileMap/TileMap.json"
          }
          , jogador1, jogador2 } {

        }

        nlohmann::json Manicomio::paraJSON() {
            nlohmann::json json;

            json["amigos"] = listaAmigos.paraJSON();

            return json;

        }

        void Manicomio::carregar(const std::string& caminho) {
            std::ifstream arquivo(caminho);

            if (arquivo.fail()) throw "arquivo nao encontrado!";
            nlohmann::json j;
            arquivo >> j;

            for (nlohmann::json amigo : j["amigos"]) {
                switch (static_cast<int> (amigo["id"]))
                {
                case Ids::kahlo:
                        jogador1->inicializarComJSON(amigo);
                        listaAmigos.inserir(jogador1);
                    break;
                case Ids::frida:
                        jogador2->inicializarComJSON(amigo);
                        listaAmigos.inserir(jogador2);
                case Ids::robotao:
                    listaAmigos.inserir(new Desenhaveis::Robotao(amigo));
                    break;
                case Ids::lagartoVerde:
                    listaAmigos.inserir(new Desenhaveis::LagartoVerde(amigo));
                    break;
                case Ids::projetil:
                    listaAmigos.inserir(new Projetil::Projetil(amigo));
                default:
                    break;
                }
            }

            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);
        }

        void Manicomio::inicializar() {
            srand(time(NULL));
            
            listaAmigos.inserir(new Entidades::Desenhaveis::Kahlo(Vetor::Vetor2F(70.0f, 120.0f)));
            
            if (jogador2) 
                listaAmigos.inserir(new Entidades::Desenhaveis::Frida(Vetor::Vetor2F(110.0f, 120.0f)));
           
            //if ()
            //listaAmigos.inserir(new Projetil::Projetil(Vetor::Vetor2F(80.0f, 120.0f), Vetor::Vetor2F(15, 0)));

           /* for (int i = 0; i < 10; i++) {
                
                listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(100 + rand() % 800, 50 + rand() % 600), Vetor::Vetor2F(15, 0)));
            }
            for (int i = 0; i < 10; i++) {
               
                listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(100 + rand() % 800, 50 + rand() % 600), Vetor::Vetor2F(20, 10)));
            }*/

            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(240.0f,50.0f), Vetor::Vetor2F(20, 10)));
            
            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(240.0f,207.0f), Vetor::Vetor2F(15, 0)));

            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(180.0f, 130.0f), Vetor::Vetor2F(0, 0)));
      
            //listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(100 + rand() % 800, 50 + rand() % 600), Vetor::Vetor2F(0, 0)));
            //listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(100 + rand() % 800, 50 + rand() % 600), Vetor::Vetor2F(0, 0)));

            //listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(300 + rand()% 500, 100.0f), Vetor::Vetor2F(10, 0)));
            //listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(100 + rand()% 800 , 50 + rand()%600), Vetor::Vetor2F(10, 0)));
            
            //listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(100, 110.0f), Vetor::Vetor2F(0, 0)));
            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);

        }
    }
}