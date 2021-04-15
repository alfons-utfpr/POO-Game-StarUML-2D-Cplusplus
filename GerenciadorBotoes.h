#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Botao.h"
#include <vector>

namespace Jogo {
    namespace Gerenciador {
        class GerenciadorBotoes {

        private:
            std::vector<Menu::Botao*> botoes;
            GerenciadorEventos& ge;
            GerenciadorGrafico& gg;
            unsigned int idOuvinteMouse;

        public:
            //Construtor sem par�metros n�o � necess�rio pois ele n�o existe em classes com atributos que s�o refer�ncias
            GerenciadorBotoes(GerenciadorEventos& GE, GerenciadorGrafico& gg, std::vector<Menu::Botao*> Botoes = {});
            ~GerenciadorBotoes();
            void desenhar() const;
            void ouvinteMouse(const sf::Event& e);
            void adicionarBotao(Menu::Botao* b);
        };
    }
}