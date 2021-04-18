#include "Salvavel.h"
#include "../Json/json.hpp"
#include <fstream>

namespace InvasaoAlienigena {
    Salvavel::~Salvavel() {

    }

    bool Salvavel::salvar(const std::string& caminho) {
        std::ofstream arquivo(caminho);
        if (arquivo.fail()) return false;
        arquivo << paraJSON();
        arquivo.close();
        return true;
    }
}