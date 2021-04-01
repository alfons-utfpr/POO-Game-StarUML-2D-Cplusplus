#pragma once
#include "Fase.h"
#include"../Json/json.hpp"

namespace Jogo {
    namespace Fase {
        class FaseExemplo : public Fase {
        public:
            FaseExemplo(Gerenciador::GerenciadorGrafico& gg, Heroi* jogador1 = nullptr, Heroi* jogador2 = nullptr);
            nlohmann::json paraJSON() override;
            void carregar(const std::string& caminho) override;
            void inicializar() override;
        };
    }
}
