#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <functional>

namespace Jogo {
    namespace Gerenciador{
        class GerenciadorEventos {
        private:

            static unsigned int proximoID;
            sf::RenderWindow* janela;
            std::map<unsigned int, std::function<void(const sf::Event&)>> ouvintesMouse;
            std::map<unsigned int, std::function<void(const sf::Event&)>> ouvintesTeclado;
            std::map<unsigned int, std::function<void(const sf::Event&)>> ouvintesOutros;
            sf::Event evento;

        public:

            GerenciadorEventos();
            ~GerenciadorEventos();
            void tratarEventos();
            void setJanela(sf::RenderWindow* j);

            unsigned int adicionarOuvinteMouse(std::function<void(const sf::Event&)> chamada);
            void removerOuvinteMouse(int id);

            unsigned int adicionarOuvinteTeclado(std::function<void(const sf::Event&)> chamada);
            void removerOuvinteTeclado(int id);

            unsigned int adicionarOuvinteOutro(std::function<void(const sf::Event&)> chamada);
            void removerOuvinteOutro(int id);
        };
    }
}