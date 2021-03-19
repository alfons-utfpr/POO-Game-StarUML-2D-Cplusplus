#pragma once
//#include <SFML/Graphics.hpp>
#include "Desenhavel.h"
#include "Lista.h"
#include "Serializavel.h"

#include "../Json/json.hpp"

namespace exercicio {

    class GerenciadorGrafico;
    class GerenciadorEventos;
    class GerenciadorColisoes;

    class ListaDesenhaveis : public Serializavel {
    private:
        Lista<Desenhavel*>  lista;

    public:

        ListaDesenhaveis();
        ~ListaDesenhaveis();

        void inserir(Desenhavel* info);
        void removerPrimeiro(Desenhavel* p);

        Desenhavel* voltarInicio(); //retorna para o início e retorna o primeiro elemento da lista
        Desenhavel* irProximo(); //vai para o próximo elemento da lista e retorna o próximo

        void inicializarDesenhaveis(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
        void atualizarDesenhaveis(float t);
        void desenharDesenhaveis(GerenciadorGrafico& g);
        void destruirDesenhaveis();
        nlohmann::json paraJSON() override;

    };

}


