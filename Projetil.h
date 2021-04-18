#pragma once
#include <SFML/Graphics.hpp>

namespace InvasaoAlienigena {
	class Projetil
	{
	private:
		sf::RectangleShape projetil;
	public:
		Projetil(sf::Vector2f size);
		Projetil();
		~Projetil();

		void fire(int speed);
		void desenhar(sf::RenderWindow &window);
		
		int getDireita();
		int getEsquerda();
		int getCima();
		int getBaixo();
	};
}

