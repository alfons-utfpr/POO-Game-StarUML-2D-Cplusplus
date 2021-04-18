#include "CampoTexto.h"
#include <fstream>
#include <iostream>
#include <sstream>

namespace InvasaoAlienigena {
    namespace Menu {
        CampoTexto::CampoTexto(Gerenciador::GerenciadorEventos& ge, unsigned short comprimentoMaximo, Vetor::Vetor2F Posicao,
            Vetor::Vetor2F Tamanho, unsigned int tamTexto, Cor c) :
            Botao{ Posicao, Tamanho, "", [this]() {iniciarCaptura(); }, tamTexto, c },
            promessa{ ge, comprimentoMaximo } {}

        CampoTexto::~CampoTexto() {

        }

        const std::string& CampoTexto::getTexto() const {
            if (!getTextoPronto()) throw "Erro! String pedida sem ter sido terminada antes. Cheque getTextoPronto() antes de chamar esse método";
            return promessa.getTexto();
        }

        bool CampoTexto::getTextoPronto() const {
            return promessa.getTextoPronto();
        }

        void CampoTexto::desenhar(Gerenciador::GerenciadorGrafico& gg) const {
            gg.desenharRetanguloSolido(posicao, tamanho, cor);
            gg.desenharTexto(promessa.getTexto(), posicao, tamanhoTexto, false);
        }

        void CampoTexto::iniciarCaptura() {
            promessa.comecar();
        }

        void CampoTexto::terminarCaptura() {
            
            sf::Event::KeyPressed;
            if (sf::Keyboard::Key::KeyCount)
                promessa.getTextoPronto();
            
        }

        void CampoTexto::Score(const int score, const std::string nome)
        {
            
        }
    }
}