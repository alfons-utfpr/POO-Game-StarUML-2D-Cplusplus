#include "GerenciadorTelas.h"
#include "Score.h"
#include "FaseFinal.h"
#include "Hospital.h"
#include "Manicomio.h"
#include "MenuPrincipal.h"
#include "MenuPausa.h"
#include "MenuJogador.h"
#include "MenuConfiguracoes.h"
#include <iostream>

namespace Jogo {
    namespace Gerenciador {
        GerenciadorTelas::GerenciadorTelas(GerenciadorGrafico& gg, Entidades::Desenhaveis::Heroi* jogador1, Entidades::Desenhaveis::Frida* jogador2) :
            gerenciadorGrafico{ gg }, jogador1{ jogador1 }, jogador2{ jogador2 } {
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
                push(new Menu::MenuConfiguracoes(gerenciadorGrafico));
                return false;
            }

            case doisJogadores:
            {
                push(new Menu::MenuConfiguracoes(gerenciadorGrafico));
                return false;
            }

            case comecarSegundaFase:
            {
                if (umJogador)
                {
                    Fase::Hospital* fase = new Fase::Hospital(gerenciadorGrafico, jogador1, 0);
                    fase->inicializar();
                    push(fase);
                    return false;
                }
                else if (umJogador && doisJogadores)
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
                    std::cout << "Erro! Não há fase a ser salva." << std::endl;
                else if (fase->salvar("../jogos-salvos/jogo_salvo.json"))
                    std::cout << "Erro! O jogo não pôde ser salvo." << std::endl;
                return false;
            }
            case carregarJogo:
            {
                std::cout << "como";
                Fase::Manicomio* fase = new Fase::Manicomio(gerenciadorGrafico, jogador1, jogador2);
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

            case comecarPrimeiraFase:
                if (umJogador)
                {
                    Fase::Manicomio* fase = new Fase::Manicomio(gerenciadorGrafico, jogador1, 0);
                    fase->inicializar();
                    push(fase);
                    return false;
                }
                else if (umJogador && doisJogadores)
                {
                    Fase::Manicomio* fase = new Fase::Manicomio(gerenciadorGrafico, jogador1, jogador2);
                    fase->inicializar();
                    push(fase);
                    return false;
                }

            case continuar:
                return false;

            default:
                return false;
            }
        }
    }
}