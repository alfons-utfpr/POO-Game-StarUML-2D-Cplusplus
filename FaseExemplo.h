#pragma once
#include "Fase.h"
#include"../Json/json.hpp"

namespace exercicio {
    class FaseExemplo : public Fase {
    public:
        FaseExemplo(GerenciadorGrafico& gg, Heroi* jogador1 = nullptr);
        nlohmann::json paraJSON() override;
        void carregar(const std::string& caminho) override;
        void inicializar() override;
    };
}
