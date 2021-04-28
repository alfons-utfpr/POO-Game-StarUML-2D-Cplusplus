#pragma once
//#include <SFML/Graphics.hpp>
#include "Desenhavel.h"
#include "Lista.h"
#include "Serializavel.h"

#include "../Json/json.hpp"

namespace InvasaoAlienigena {

    class GerenciadorGrafico;
    class GerenciadorEventos;
    class GerenciadorColisoes;

    namespace Lista {
        class ListaDesenhaveis : public Serializavel {
        private:
            Lista<Desenhavel*>  lista;

        public:

            ListaDesenhaveis();
            ~ListaDesenhaveis();

            void inserir(Desenhavel* info);
            void removerPrimeiro(Desenhavel* p);

            Desenhavel* voltarInicio(); //retorna para o in�cio e retorna o primeiro elemento da lista
            Desenhavel* irProximo(); //vai para o pr�ximo elemento da lista e retorna o pr�ximo
            Desenhavel* getInicio();
            bool estaVazia();

            void inicializarDesenhaveis(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void atualizarDesenhaveis(float t);
            void desenharDesenhaveis(Gerenciador::GerenciadorGrafico& g);
            void destruirDesenhaveis();
            nlohmann::json paraJSON() override;

        };
    }
}


