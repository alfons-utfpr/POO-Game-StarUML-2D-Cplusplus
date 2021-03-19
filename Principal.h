#pragma once

#include "GerenciadorGrafico.h"

#include "Heroi.h"

#include "GerenciadorTelas.h"

//using namespace sf

/*
namespaces: conjuntos de classes, vari�veis, fun��es, etc.
um namespace pode ser declarado dividido entre v�rios arquivos, e todos entender�o que est�o no mesmo namespace
para usar algo de um namespace fora do namespace, se usa o operador de resolu��o de escopo (::)
std::list -> dentro do namespace std, quero a classe list
O operador de resolu��o de escopo tamb�m � usado com classes
Principal::Principal() -> procurando a fun��o Principal() dentro da classe Principal
classes e namespaces s�o escopos
o comando "using namespace std" significa que se o compilador n�o achar algo no escopo local, deve procurar no namespace std
namespace nome_do_namespace {
}
*/

namespace exercicio {

    class Principal {
    private:

        GerenciadorGrafico gerenciadorGrafico;
        Heroi jogador1;
        GerenciadorTelas gerenciadorTelas;
        bool terminar;
    public:
        Principal();
        ~Principal();
        int executar();
        void janelaFechada(const sf::Event& e);

    };

}