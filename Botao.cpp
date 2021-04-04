#include "Botao.h"

namespace Jogo {
    namespace Menu {
        Botao::Botao(Vetor::Vetor2F Posicao/* = {0.0f, 0.0f}*/, Vetor::Vetor2F Tamanho/* = {0.0f, 0.0f}*/, std::string Texto/* = ""*/, std::function<void(void)> QuandoApertado/* = std::function<void(void)>()*/, unsigned int tamTexto/* = 15U*/, Cor c/* = {128, 128, 128}*/) :
            quandoApertado{ QuandoApertado }, posicao{ Posicao }, tamanho{ Tamanho }, cor{ c }, tamanhoTexto{ tamTexto }, texto{ Texto }  {}

        Botao::~Botao() {

        }

        void Botao::desenhar(Gerenciador::GerenciadorGrafico& gg) const {
            gg.desenharRetanguloSolido(posicao, tamanho, cor);
            gg.desenharTexto(texto, posicao, tamanhoTexto);
        }

        Vetor::Vetor2F Botao::getPosicao() const {
            return posicao;
        }

        Vetor::Vetor2F Botao::Botao::getTamanho() const {
            return tamanho;
        }

        void Botao::apertar() const {
            quandoApertado();
        }
    }
}