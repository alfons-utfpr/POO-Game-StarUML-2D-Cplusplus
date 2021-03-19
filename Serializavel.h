#pragma once

#include "../Json/json.hpp"

namespace exercicio {
    class Serializavel {
    public:
        virtual ~Serializavel();
        virtual nlohmann::json paraJSON() = 0;
    };
}
