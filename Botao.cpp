#include "Botao.h"

namespace InvasaoAlienigena {
    namespace Menu {
        Botao::Botao(Vetor::Vetor2F Posicao, Vetor::Vetor2F Tamanho, std::string Texto, std::function<void(void)> QuandoApertado, unsigned int tamTexto, Cor c) :
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