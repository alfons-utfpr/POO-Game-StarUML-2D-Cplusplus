#include "ListaDesenhaveis.h"
#include <iostream>

namespace Jogo {
    namespace Lista {
        ListaDesenhaveis::ListaDesenhaveis() {

        }

        ListaDesenhaveis::~ListaDesenhaveis() {
            destruirDesenhaveis();
        }

        void ListaDesenhaveis::inserir(Desenhavel* info) {
            lista.inserir(info);
        }

        void ListaDesenhaveis::removerPrimeiro(Desenhavel* p) {
            lista.removerPrimeiro(p);
        }

        void ListaDesenhaveis::inicializarDesenhaveis(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {

            Desenhavel* p = lista.voltarInicio();

            while (p) {

                p->inicializar(gf, ge, gc);

                p = lista.irProximo();

            }
        }

        void ListaDesenhaveis::atualizarDesenhaveis(float t) {
            Desenhavel* p = lista.voltarInicio();

            while (p) {
                p->atualizar(t);
                p = lista.irProximo();
            }
        }

        void ListaDesenhaveis::desenharDesenhaveis(Gerenciador::GerenciadorGrafico& g) {
            Desenhavel* p = lista.voltarInicio();

            while (p) {
                p->desenhar(g);
                p = lista.irProximo();
            }
        }

        void ListaDesenhaveis::destruirDesenhaveis() {
            Desenhavel* p = lista.voltarInicio();
            while (p) {
                delete p;
                p = lista.irProximo();
            }
            lista.esvaziar();
        }

        nlohmann::json ListaDesenhaveis::paraJSON() {
            nlohmann::json resultado = nlohmann::json::array();
            int posicao = 0;
            Desenhavel* p = lista.voltarInicio();

            while (p) {
                resultado[posicao++] = p->paraJSON();
                p = lista.irProximo();
            }
            return resultado;
        }
    }
}