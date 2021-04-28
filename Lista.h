#pragma once

namespace InvasaoAlienigena {
    namespace Lista {
        template <typename TF>
        class Lista {
        private:

            template <typename TE>
            class ElementoLista {
            private:
                TE info;
                ElementoLista* ant;
                ElementoLista* prox;
                char nome[150];

            public:
                ElementoLista(TE Info = nullptr, ElementoLista* Ant = nullptr, ElementoLista* Prox = nullptr);
                ~ElementoLista();

                TE getInfo() const;
                void setInfo(TE Info);

                ElementoLista* getAnt() const;
                void setAnt(ElementoLista* Ant);

                ElementoLista* getProx() const;
                void setProx(ElementoLista* Prox);

                char* getNome() const;
                void setNome(const char* n);

                void remover();
            };

            ElementoLista<TF>* inicio;
            ElementoLista<TF>* fim;
            ElementoLista<TF>* atual;
            int qntElementos;

        public:

            Lista();
            ~Lista();

            void inserir(TF info);
            void esvaziar();
            //retorna true caso esteja vazia e false caso contrário
            bool estaVazia();

            TF voltarInicio(); //retorna para o in�cio e retorna o primeiro elemento da lista
            TF irProximo(); //vai para o pr�ximo elemento da lista e retorna o pr�ximo
            TF getInicio();//retorna o elemento inicial na forma de ponteiro
            void removerPrimeiro(TF elemento);

            bool gravarEmArquivo(char const* const arquivo);
            bool recuperarDeArquivo(char const* const arquivo);

        };
    }
}

#include "ListaImplementacao.h"
