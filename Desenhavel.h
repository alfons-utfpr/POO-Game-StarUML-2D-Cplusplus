#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "Ids.h"
#include "Serializavel.h"

namespace InvasaoAlienigena {
   // namespace Desenhaveis {
        class Desenhavel : public Serializavel {
        protected:
            Vetor::Vetor2F intercessao;
            Vetor::Vetor2F posicao;
            Vetor::Vetor2F v;
            Vetor::Vetor2F dimensoes;
            const char* caminho;
            Ids::Ids id;
        public:

            Desenhavel(Ids::Ids ID = Ids::semID, Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr);
            virtual ~Desenhavel();
            virtual void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            virtual void atualizar(float t);
            virtual void desenhar(Gerenciador::GerenciadorGrafico& g);
            const Vetor::Vetor2F getPosicao() const;
            const Vetor::Vetor2F getDimensoes() const;
            const Vetor::Vetor2F getIntercessao() const;
            const Ids::Ids getId() const;
            nlohmann::json paraJSON() override;
        };
   // }
}
