#pragma once
#include "../Json/json.hpp"

namespace InvasaoAlienigena {
    class Serializavel {
    public:
        virtual ~Serializavel();
        virtual nlohmann::json paraJSON() = 0;
    };
}
