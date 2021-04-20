#pragma once
#include "Estado.h"
#include "GerenciadorEventos.h"
#include "GerenciadorBotoes.h"
#include "GerenciadorGrafico.h"

namespace InvasaoAlienigena {
    namespace Menu {
        class Menu : public Estado {
        private:
            int codigoRetorno;

        protected:
            Gerenciador::GerenciadorEventos ge;
            Gerenciador::GerenciadorBotoes gb;
            Gerenciador::GerenciadorGrafico& gg;

        public:
            Menu(Gerenciador::GerenciadorGrafico& GG);
            virtual ~Menu();
            virtual int executar() override;

        protected:
            void setCodigoRetorno(int codigo);
        };
    }
}
