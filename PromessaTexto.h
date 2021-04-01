#ifndef _PROMESSA_TEXTO_HPP_
#define _PROMESSA_TEXTO_HPP_

#include <string>
#include "GerenciadorEventos.h"

namespace Jogo {
    class PromessaTexto {
    private:
        std::string texto;
        unsigned int idOuvinteTeclado;
        bool capturaIniciada;
        bool textoPronto;
        Gerenciador::GerenciadorEventos& ge;
        unsigned short comprimentoMaximo;

    public:
        PromessaTexto(Gerenciador::GerenciadorEventos& GE, unsigned short comprimentoMax);
        ~PromessaTexto();
        void comecar();
        bool getTextoPronto() const;
        const std::string& getTexto() const;
        void adquirir(const sf::Event& e);
    };
}

#endif