#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "Ids.h"

#include "Serializavel.h"

namespace Jogo {
   // namespace Desenhaveis {
        class Desenhavel : public Serializavel {
        protected:
            Vetor2F intercessao;
            Vetor2F posicao;
            Vetor2F v;
            Vetor2F dimensoes;
            const char* caminho;
            Ids::Ids id;
        public:

            Desenhavel(Ids::Ids ID = Ids::semID, Vetor2F pos = { 0.0f, 0.0f }, Vetor2F vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr);
            virtual ~Desenhavel();
            virtual void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            virtual void atualizar(float t);
            virtual void desenhar(Gerenciador::GerenciadorGrafico& g);
            const Vetor2F getPosicao() const;
            const Vetor2F getDimensoes() const;
            const Vetor2F getIntercessao() const;
            const Ids::Ids getId() const;
            nlohmann::json paraJSON() override;
        };
   // }
}
