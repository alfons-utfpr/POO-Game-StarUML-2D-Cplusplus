#pragma once

#include "Menu.h"
#include "CampoTexto.h"
#include "GerenciadorGrafico.h"

namespace exercicio {
    class MenuConfiguracoes: public Menu{
        bool imprimiu;
        CampoTexto campoTexto;
    public:
        MenuConfiguracoes(GerenciadorGrafico& GG);
        int executar() override;
    };
   
}

