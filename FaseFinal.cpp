#include "FaseFinal.h"
#include "SegundoHeroi.h"
#include "Tile.h"
#include "Vilao.h"
#include "SegundoVilao.h"
#include "Chefao.h"
#include <fstream>

namespace Jogo {
    namespace Fase {
        FaseFinal::FaseFinal(Gerenciador::GerenciadorGrafico& gg, Desenhaveis::Heroi* jogador1/* = nullptr*/, Desenhaveis::Heroi* jogador2) : Fase{ gg,
        new Gerenciador::GerenciadorTiles{
        {
            //new Tile(Ids::heroi, "boneco.png"),
             new Tile::Tile(Ids::armadilha_direita, "armadilha_direita.png"),
            new Tile::Tile(Ids::armadilha_esquerda,"armadilha_esquerda.png"),
            new Tile::Tile(Ids::espinho,"espinho.png"),
            new Tile::Tile(Ids::espinho_direita,"espinho_direita.png"),
            new Tile::Tile(Ids::espinho_esquerda,"espinho_esquerda.png"),
            new Tile::Tile(Ids::espinho_fundo,"espinho_fundo.png"),
            new Tile::Tile(Ids::esquerda2,"esquerda2.png"),
            new Tile::Tile(Ids::fundo,"fundo.png"),
            new Tile::Tile(Ids::fundo1,"fundo1.png"),
            new Tile::Tile(Ids::parede, "parede.png"),
            new Tile::Tile(Ids::parede_clara,"parede_clara.png"),
            new Tile::Tile(Ids::parede_up,"parede_clara.png"),
            new Tile::Tile(Ids::personagem,"personagem.png"),
            new Tile::Tile(Ids::porta,"porta.png"),
            new Tile::Tile(Ids::prisao,"prisao.png"),
            new Tile::Tile(Ids::teste,"teste.png"),
            new Tile::Tile(Ids::teste_fundo,"teste_fundo.png"),
            new Tile::Tile(Ids::teste_fundo2,"teste_fundo2.png"),
            new Tile::Tile(Ids::teste_chama,"teste_chama.png"),
            // new Tile(Ids::tux_from_linux,"tux_from_linux.png"),
            },
            {32.0f, 32.0f}, "../TileMap/TileMap.json"
          }
          , jogador1 } {

        }

        nlohmann::json FaseFinal::paraJSON() {
            nlohmann::json json;

            json["amigos"] = listaAmigos.paraJSON();

            return json;

        }

        void FaseFinal::carregar(const std::string& caminho) {
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
                case Ids::vilao:
                    listaAmigos.inserir(new Desenhaveis::Vilao(amigo));
                    break;
                case Ids::inimigo:
                    listaAmigos.inserir(new Desenhaveis::SegundoVilao(amigo));
                    break;
                case Ids::chefao:
                    listaAmigos.inserir(new Desenhaveis::Chefao(amigo));
                default:
                    break;
                }
            }

            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);
        }

        void FaseFinal::inicializar() {
            if (jogador1) listaAmigos.inserir(jogador1);
            else if (jogador1 && jogador2)
            {
                listaAmigos.inserir(new Desenhaveis::Heroi(Vetor::Vetor2F(40.0f, 50.0f)));
                listaAmigos.inserir(new Desenhaveis::SegundoHeroi(Vetor::Vetor2F(50.0f, 50.f)));
            }

            listaAmigos.inserir(new Desenhaveis::Vilao(Vetor::Vetor2F(40.0f, 50.0f), Vetor::Vetor2F(0, 10)));
            listaAmigos.inserir(new Desenhaveis::Vilao(Vetor::Vetor2F(40.0f, 100.0f), Vetor::Vetor2F(0, -10)));
            listaAmigos.inserir(new Desenhaveis::Vilao(Vetor::Vetor2F(80.0f, 50.0f), Vetor::Vetor2F(0, -10)));
            listaAmigos.inserir(new Desenhaveis::Chefao(Vetor::Vetor2F(80.0f, 100.0f), Vetor::Vetor2F(0, 10)));

            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);

        }
    }
}
