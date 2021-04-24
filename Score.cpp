#include "Score.h"
#include "GerenciadorTelas.h"
#include <iostream>
#include <string.h>

namespace InvasaoAlienigena {
	namespace Menu {
        Score::Score(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg },
            campoTexto{ ge, 15, {200.0f, 50.0f}, {200, 40} } {
            //gb.adicionarBotao(new Botao({ 200.0f, 50.0f }, { 100, 50 }, "Classificação", [this] {setCodigoRetorno(classificacao); }));
            gb.adicionarBotao(new Botao({ 200.0f, 250.0f }, { 100, 50 }, "Menu Principal", [this] {setCodigoRetorno(irMenuPrincipal); }));
        }
        /*nome dos jogadores*/
        int Score::executar() {
            int ret = Menu::executar();
            gg.desenharTexto("CLASSIFICACÃO", { 200.0f, 50.0f }, 15);

            for (int i = 0; i < 10; i++)
            {
                if (campoTexto.getTextoPronto()) {
                    gg.desenharTexto(campoTexto.getTexto(), { 100.0f, 70.0f }, 15);
                    std::cout << std::endl;
                }
            }
            //gb.adicionarBotao(new Botao({ 200.0f, 50.0f }, { 200.0f }, "CLASSIFICAÇÃO "));
            return ret;
        }
        void Score::setNome(const char* n)
        {
            //strcpy(nome, n);
        }
        const char* Score::getNome()
        {
            return nullptr;
        }
        void Score::incluaJogador(Entidades::Desenhaveis::Jogador* pj)
        {
            ObjLJogador.inserir(pj);
        }
        void Score::listeJogador()
        {
            /*ElementoLista<Entidades::Desenhaveis::Jogador*>* elem = ObjLJogador.getPrimeiro();

            while (nullptr != elem)
            {
                Entidades::Desenhaveis::Jogador* obj = (Entidades::Desenhaveis::Jogador*)elem->getInfo();

                std::cout << obj->getNome() << std::endl;
            }
            elem = elem->getProximo();*/
        }
	}
}
