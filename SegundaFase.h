#pragma once

#include "Fase.h"
#include"../Json/json.hpp"

namespace exercicio {
    class SegundaFase : public Fase {
    public:
        SegundaFase(GerenciadorGrafico& gg, Heroi* jogador1 = nullptr);
        nlohmann::json paraJSON() override;
        void carregar(const std::string& caminho) override;
        void inicializar() override;
    };
}

