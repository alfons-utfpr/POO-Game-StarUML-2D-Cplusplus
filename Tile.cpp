#include "Tile.h"

#include <iostream>

namespace Jogo {
    namespace Tile {
        Tile::Tile(const Ids::Ids ID /*= Ids::semID*/, const char* caminhoArquivo /*= nullptr*/, Vetor2F Tamanho /*= {32.0f, 32.0f}*/) :
            id{ ID }, caminho{ caminhoArquivo }, tamanho{ Tamanho } {
        }

        Tile::~Tile() {

        }

        void Tile::inicializar(Gerenciador::GerenciadorGrafico& gg, Gerenciador::GerenciadorEventos& ge) {
            gg.carregarTextura(caminho);
        }

        void Tile::desenhar(Gerenciador::GerenciadorGrafico& gg, const Vetor2F posicao) const {
            // std::cout << '\t' << '\t' << caminho << std::endl;
            gg.desenhar(caminho, posicao);
        }

        const Ids::Ids Tile::getId() const {
            return id;
        }

        void Tile::colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2U posicao) {

        }
    }
}