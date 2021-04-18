#pragma once
#include "Serializavel.h"

namespace InvasaoAlienigena {
    class Salvavel : public Serializavel {
    public:
        virtual ~Salvavel();
        bool salvar(const std::string& caminho);
        virtual void carregar(const std::string& caminho) = 0;
    };
}
