#pragma once
#include "Vetor2D.h"

namespace InvasaoAlienigena {
    namespace Tile {
        class TileMap {
        public:
            class LinhaTileMap {
            private:
                const unsigned short* linha;
                unsigned int comprimento;

            public:
                LinhaTileMap(unsigned short* p = nullptr, unsigned int c = 0);
                ~LinhaTileMap();
                unsigned short operator[](unsigned int i) const;

            };

        private:
            Vetor::Vetor2U dimensoesMapa;
            unsigned short** mapa;
            const char* caminho;

        public:
            TileMap(const char* caminhoArquivo = nullptr);
            ~TileMap();
            const Vetor::Vetor2U getDimensoesMapa() const;
            void imprimirMapa() const;
            void setTile(Vetor::Vetor2U posicao, unsigned short novoIndice);
            const LinhaTileMap operator[](unsigned int i) const;
            void salvarMapa(const char* caminhoArquivo = nullptr);

        private:
            void CarregarMapa();

        };
    }
}

