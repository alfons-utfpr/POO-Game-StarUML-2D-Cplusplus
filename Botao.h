#pragma once
#include "Vetor2D.h"
#include "Cor.h"
#include "GerenciadorGrafico.h"
#include <string>
#include <functional>


namespace InvasaoAlienigena {
    namespace Menu {
        class Botao {
        private:
            std::function<void(void)> quandoApertado;

        protected:
            Vetor::Vetor2F posicao;
            Vetor::Vetor2F tamanho;
            Cor cor;
            unsigned int tamanhoTexto;
            std::string texto;

        public:
            Botao(Vetor::Vetor2F Posicao = { 0.0f, 0.0f }, Vetor::Vetor2F Tamanho = { 0.0f, 0.0f }, std::string Texto = "", std::function<void(void)> QuandoApertado = std::function<void(void)>(), unsigned int tamTexto = 15U, Cor c = { 128, 128, 128 });
            virtual ~Botao();
            virtual void desenhar(Gerenciador::GerenciadorGrafico& gg) const;
            Vetor::Vetor2F getPosicao() const;
            Vetor::Vetor2F getTamanho() const;
            void apertar() const;

        };
    }
}