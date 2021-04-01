#pragma once

namespace Jogo {
    class Cor {
    public:

        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;

        Cor(unsigned char R = 0, unsigned char G = 0, unsigned char B = 0, unsigned char A = 255);
    };
}

