#pragma once
#include "Estado.h"

#include "GerenciadorEventos.h"
#include "GerenciadorBotoes.h"
#include "GerenciadorGrafico.h"


namespace exercicio {
    class Menu : public Estado {

    private:
        int codigoRetorno;

    protected:
        GerenciadorEventos ge;
        GerenciadorBotoes gb;
        GerenciadorGrafico& gg;

    public:
        Menu(GerenciadorGrafico& GG);
        virtual ~Menu();
        virtual int executar() override;

    protected:
        void setCodigoRetorno(int codigo);
    };
}
