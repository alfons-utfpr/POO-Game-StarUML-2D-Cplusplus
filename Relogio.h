#pragma once
#include <time.h>

namespace InvasaoAlienigena {
    class Relogio {
    private:
        clock_t ultimo;
        clock_t atual;
        double dt;
        bool pausado;
    public:
        Relogio();
        ~Relogio();
        double getTempo();
        void reiniciar();
        void pausar();


    };
}

