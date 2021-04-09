#pragma once
#include "Botao.h"
#include "PromessaTexto.h"
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
#include "Vetor2D.h"
#include "Cor.h"

#include <string>

namespace Jogo {
    namespace Menu {
        class CampoTexto : public Botao {

        private:
            PromessaTexto promessa;

        public:
            CampoTexto(Gerenciador::GerenciadorEventos& ge, unsigned short comprimentoMaximo, Vetor::Vetor2F Posicao = { 0.0f, 0.0f }, Vetor::Vetor2F Tamanho = { 0.0f, 0.0f }, unsigned int tamTexto = 15U, Cor c = { 128, 128, 128 });
            ~CampoTexto();
            const std::string& getTexto() const;
            bool getTextoPronto() const;
            void desenhar(Gerenciador::GerenciadorGrafico& gg) const override;
            void iniciarCaptura();
            void Score(const int score, const std::string nome);

        };
    }
}