#pragma once
#include "../Json/json.hpp"

namespace Jogo {
    class Serializavel {
    public:
        virtual ~Serializavel();
        virtual nlohmann::json paraJSON() = 0;
    };
}
