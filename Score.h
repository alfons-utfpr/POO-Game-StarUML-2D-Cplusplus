#pragma once
#include "GerenciadorGrafico.h"
#include "Menu.h"
#include "CampoTexto.h"
#include "Lista.h"
#include "Jogador.h"


namespace InvasaoAlienigena {
	namespace Menu {
		class Score : public Menu{
		protected:
			CampoTexto campoTexto;
			//const char nome;
			Lista::Lista<Entidades::Desenhaveis::Jogador*> ObjLJogador;
			

		public:
			Score(Gerenciador::GerenciadorGrafico& GG);
			int executar() override;

			void setNome(const char* n);
			const char* getNome();

			void incluaJogador(Entidades::Desenhaveis::Jogador* pj);
			void listeJogador();
			//void listeDepartamentos2();
		};
	}
}

