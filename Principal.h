#pragma once

#include "GerenciadorGrafico.h"

#include "Heroi.h"

#include "GerenciadorTelas.h"

//using namespace sf

/*
namespaces: conjuntos de classes, variáveis, funções, etc.
um namespace pode ser declarado dividido entre vários arquivos, e todos entenderão que estão no mesmo namespace
para usar algo de um namespace fora do namespace, se usa o operador de resolução de escopo (::)
std::list -> dentro do namespace std, quero a classe list
O operador de resolução de escopo também é usado com classes
Principal::Principal() -> procurando a função Principal() dentro da classe Principal
classes e namespaces são escopos
o comando "using namespace std" significa que se o compilador não achar algo no escopo local, deve procurar no namespace std
namespace nome_do_namespace {
}
*/

namespace Jogo {

    class Principal {
    private:

        Gerenciador::GerenciadorGrafico gerenciadorGrafico;
        Heroi jogador1;
        Gerenciador::GerenciadorTelas gerenciadorTelas;
        bool terminar;
    public:
        Principal();
        ~Principal();
        int executar();
        void janelaFechada(const sf::Event& e);

    };

}