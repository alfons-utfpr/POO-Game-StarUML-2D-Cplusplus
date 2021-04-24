#include "Principal.h"
#include "Kahlo.h"
#include "Robotao.h"
#include "Tile.h"
#include <iostream>

namespace InvasaoAlienigena {

    /*
    listas de inicializa��o
    no construtor de uma classe, depois da lista de par�metros mas antes do abre chaves, escreva um dois pontos.
    depois disso, coloque o nome de cada vari�vel com os par�metros que voc� passaria para inicializ�-la (ou o valor de inicializa��o) entre chaves, separados
    por v�rgulas, na ordem de sua declara��o na classe.
    Tamb�m funcionaria com parenteses
    amigo(0, 0, "TheUndying.png")
    mas as chaves s�o mais estritas, impedindo que voc� fa�a convers�es n�o expl�citas, o que � mais eficiente e te d� um controle mais exato sobre o que est� acontecendo
    */

    Principal::Principal() :
        jogador1{ Entidades::Desenhaveis::Kahlo(Vetor::Vetor2F(20.0f, 20.0f)) },
        jogador2{ Entidades::Desenhaveis::Frida(Vetor::Vetor2F(20.0f, 20.0f)) },
        gerenciadorTelas{ gerenciadorGrafico, &jogador1, &jogador2 },
        terminar{ false }
    {

    }

    Principal::~Principal() {

    }

    int Principal::executar() {
        while (!terminar) {

            gerenciadorGrafico.limpar();
            terminar = gerenciadorTelas.executar();
            gerenciadorGrafico.mostrar();
        }
        return 0;
    }

}