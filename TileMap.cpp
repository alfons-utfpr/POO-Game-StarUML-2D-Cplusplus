#include "TileMap.h"
#include <iostream>
#include <iomanip>
#include <fstream>

#include "../Json/json.hpp"


namespace InvasaoAlienigena {
    namespace Tile {
        using LinhaTileMap = TileMap::LinhaTileMap;

        LinhaTileMap::LinhaTileMap(unsigned short* p, unsigned int c) : linha{ p }, comprimento{ c } {

        }

        LinhaTileMap::~LinhaTileMap() {

        }

        unsigned short LinhaTileMap::operator[](unsigned int i) const {

            // if (i >= comprimento) {
            //   std::cout << "Erro! acesso indevido à memória do mapa de tiles.\n" << std::endl;
            //   exit(526);
            // } 
            return linha[i];
        }


        TileMap::TileMap(const char* caminhoArquivo) : mapa{ nullptr }, caminho{ caminhoArquivo } {
            if (caminho) CarregarMapa();
        }

        TileMap::~TileMap() {
            if (mapa) {
                for (unsigned int i = 0; i < dimensoesMapa.y; ++i)
                    delete mapa[i];
                delete mapa;
            }
        }

        const Vetor::Vetor2U TileMap::getDimensoesMapa() const {
            return dimensoesMapa;
        }

        void TileMap::imprimirMapa() const {
            for (unsigned int i = 0; i < dimensoesMapa.y; ++i) {
                for (unsigned int j = 0; j < dimensoesMapa.x; ++j)
                    std::cout << std::setw(2) << mapa[i][j] << ' ';
                std::cout << '\n';
            }

            std::cout.flush();
        }

        void TileMap::setTile(Vetor::Vetor2U posicao, unsigned short novoIndice) {
            if (posicao.x >= dimensoesMapa.x || posicao.y >= dimensoesMapa.y) {
                std::cout << "Erro! acesso indevido à memória do mapa de tiles.\n" << std::endl;
                exit(526);
            }

            mapa[posicao.y][posicao.x] = novoIndice;
        }

        const LinhaTileMap TileMap::operator[](unsigned int i) const {
            // if (i > dimensoesMapa.y) {
            //   std::cout << "Erro! acesso indevido à memória do mapa de tiles.\n" << std::endl;
            //   exit(526);
            // }

            return { mapa[i], dimensoesMapa.x };
        }

        void TileMap::salvarMapa(const char* caminhoArquivo)
        {
            std::ofstream out_file;

            out_file.open(caminhoArquivo);

            if (out_file.is_open()) {
                out_file << this->getDimensoesMapa() << std::endl;
                imprimirMapa();
            }
            else {
                std::cout << "Erro, TileMap nao foi salvo" << caminhoArquivo << std::endl;
            }

            out_file.close();
        }

        void TileMap::CarregarMapa() {
            std::ifstream arquivo(caminho);

            if (!arquivo.is_open()) {
                std::cout << "Erro! arquivo no caminho \"" << caminho << "\" não pode ser aberto!" << std::endl;
                exit(527);
            }

            nlohmann::json json;

            arquivo >> json;

            json = json["layers"][0];

            dimensoesMapa = { json["width"], json["height"] };

            json = json["data"];

            mapa = new unsigned short* [dimensoesMapa.y];

            for (unsigned int i = 0; i < dimensoesMapa.y; ++i) mapa[i] = new unsigned short[dimensoesMapa.x];

            unsigned int i = 0;
            unsigned int j = 0;

            for (unsigned short s : json) {

                if (j >= dimensoesMapa.x) {
                    j = 0;
                    ++i;
                }

                if (i >= dimensoesMapa.y) break;

                mapa[i][j++] = s;

            }

            // std::cout << dimensoesMapa << std::endl; 

            // imprimirMapa();

        }
    }
}