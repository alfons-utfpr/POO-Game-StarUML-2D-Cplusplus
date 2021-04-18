#include "Tile.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Tile {
        Tile::Tile(const Ids::Ids ID, const char* caminhoArquivo, Vetor::Vetor2F Tamanho) :
            id{ ID }, caminho{ caminhoArquivo }, tamanho{ Tamanho } {
        }

        Tile::~Tile() {

        }

        void Tile::inicializar(Gerenciador::GerenciadorGrafico& gg, Gerenciador::GerenciadorEventos& ge) {
            gg.carregarTextura(caminho);
        }

        void Tile::desenhar(Gerenciador::GerenciadorGrafico& gg, const Vetor::Vetor2F posicao) const {
            gg.desenhar(caminho, posicao);
        }

        const Ids::Ids Tile::getId() const {
            return id;
        }

        void Tile::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2U posicao) {

        }
    }
}