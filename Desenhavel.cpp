#include "Desenhavel.h"

#include "../Json/json.hpp"

namespace InvasaoAlienigena {
   // namespace Desenhaveis {
        Desenhavel::Desenhavel(Ids::Ids ID, Vetor::Vetor2F pos, Vetor::Vetor2F vel, const char* caminhoTextura) :
            posicao{ pos }, v{ vel }, caminho{ caminhoTextura }, id{ ID } {

        }

        Desenhavel::~Desenhavel() {
        }

        void Desenhavel::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);
        }

        void Desenhavel::atualizar(float t) {

            posicao += v * t;

        }

        void Desenhavel::desenhar(Gerenciador::GerenciadorGrafico& g) {
            g.desenhar(caminho, posicao);

        }

        const Vetor::Vetor2F Desenhavel::getPosicao() const {
            return posicao;
        }

        const Vetor::Vetor2F Desenhavel::getDimensoes() const {
            return dimensoes;
        }

        const Vetor::Vetor2F Desenhavel::getIntercessao() const
        {
            return intercessao;
        }

        const Ids::Ids Desenhavel::getId() const {
            return id;
        }

        nlohmann::json Desenhavel::paraJSON() {
            return {
              {"id", id},
              {"posicao", posicao.paraJSON()},
              {"velocidade", v.paraJSON()},
              {"caminho", caminho},
              {"dimensoes", dimensoes.paraJSON()}
            };
        }
   // }
}