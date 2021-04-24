#include "GerenciadorTelas.h"
#include "Score.h"
#include "Hospital.h"
#include "Manicomio.h"
#include "MenuPrincipal.h"
#include "MenuPausa.h"
#include "MenuJogador.h"
#include "MenuConfiguracoes.h"
#include "NomeJogadores.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Gerenciador {
        GerenciadorTelas::GerenciadorTelas(GerenciadorGrafico& gg, Entidades::Desenhaveis::Kahlo* jogador1, Entidades::Desenhaveis::Frida* jogador2) :
            gerenciadorGrafico{ gg }, jogador1{ jogador1 }, jogador2{ jogador2 } , multiplosJogadores(false){
            push(new Menu::MenuPrincipal(gerenciadorGrafico));
        }

        bool GerenciadorTelas::processarCodigo(int codigoRetorno) {
            switch (codigoRetorno) {
            case terminarJogo:
                return true;

            case selecionarJogador:
            {
                push(new Menu::MenuJogador(gerenciadorGrafico));
                return false;
            }

            case umJogador:
            {
                multiplosJogadores = false;
                push(new Menu::NomeJogadores(gerenciadorGrafico));
                return false;
            }

            case doisJogadores:
            {
                multiplosJogadores = true;
                push(new Menu::NomeJogadores(gerenciadorGrafico));
               // push(new Menu::MenuConfiguracoes(gerenciadorGrafico));
                return false;
            }

            case comecar: 
            {
                push(new Menu::MenuConfiguracoes(gerenciadorGrafico));
                return false;
            }

            case comecarPrimeiraFase:
                if (!multiplosJogadores)
                {
                    Fase::Manicomio* fase = new Fase::Manicomio(gerenciadorGrafico, jogador1);
                    fase->inicializar();
                    push(fase);
                    //pop();
                    //Fase::Hospital* segunda = new Fase::Hospital(gerenciadorGrafico, jogador1);
                    //push(segunda);
                    return false;
                }
                else
                {
                    Fase::Manicomio* fase = new Fase::Manicomio(gerenciadorGrafico, jogador1, jogador2);
                    fase->inicializar();
                    push(fase);
                    //pop();
                    //Fase::Hospital* segunda = new Fase::Hospital(gerenciadorGrafico, jogador1, jogador2);
                    //push(segunda);
                    return false;
                }

            case comecarSegundaFase:
            {
                if (!multiplosJogadores)
                {
                    Fase::Hospital* fase = new Fase::Hospital(gerenciadorGrafico, jogador1);
                    fase->inicializar();
                    push(fase);
                    return false;
                }
                else
                {
                    Fase::Hospital* fase = new Fase::Hospital(gerenciadorGrafico, jogador1, jogador2);
                    fase->inicializar();
                    push(fase);
                    return false;
                }
            }

            case classificacao:
            {
                push(new Menu::Score(gerenciadorGrafico));
                return false;
            }

            case fimDeJogo:
            {
                push(new Menu::Score(gerenciadorGrafico));
                return false;
            }

            case salvarJogo:
            {
                pop();
                Fase::Fase* fase = dynamic_cast<Fase::Fase*>(top());
                if (!fase)
                    std::cout << "Erro! N�o h� fase a ser salva." << std::endl;
                else if (!fase->salvar("../jogos-salvos/jogo_salvo.json"))
                    std::cout << "Erro! O jogo n�o p�de ser salvo." << std::endl;
                return false;
            }
            case carregarJogo:
            {
                std::cout << "como";
                Fase::Manicomio* fase = new Fase::Manicomio(gerenciadorGrafico, jogador1);
                std::cout << " onde" << std::endl;
                try {
                    fase->carregar("../jogos-salvos/jogo_salvo.json");
                    push(fase);
                }
                catch (char const* s) {
                    std::cout << s << std::endl;
                    delete fase;
                }
                return false;
            }
            case irMenuPausa:
                push(new Menu::MenuPausa(gerenciadorGrafico));
                return false;

            case sairMenuPausa:
                pop();
                return false;

            case irMenuPrincipal:
                esvaziarPilha();
                push(new Menu::MenuPrincipal(gerenciadorGrafico));
                return false;

            case continuar:
                return false;

            default:
                return false;
            }
        }
    }
}