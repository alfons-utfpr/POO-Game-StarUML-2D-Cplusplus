#pragma once
#include "Estado.h"
#include <stack>

namespace InvasaoAlienigena {
    namespace Gerenciador {
        class GerenciadorEstados {
        private:
            std::stack<Estado*> pilhaEstados;
        public:
            virtual ~GerenciadorEstados();
            bool executar();
        protected:
            void push(Estado* p);
            void pop();
            Estado* top();
            void esvaziarPilha();
            virtual bool processarCodigo(int codigoRetorno) = 0;

        };
    }
}

