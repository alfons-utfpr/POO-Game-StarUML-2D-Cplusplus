#pragma once
#include <ostream>
#include "Serializavel.h"

namespace InvasaoAlienigena {
    namespace Vetor {
        template <typename T>
        class Vetor2D : public Serializavel {
        public:
            T x, y;

            Vetor2D(T X = 0.0, T Y = 0.0);
            Vetor2D(nlohmann::json j);
            ~Vetor2D();

            void operator =(Vetor2D v);

            Vetor2D operator +(Vetor2D v) const;
            Vetor2D operator -(Vetor2D v) const;
            Vetor2D operator *(int i) const;
            Vetor2D operator *(float f) const;
            Vetor2D operator *(double d) const;

            void operator +=(Vetor2D v);
            void operator -=(Vetor2D v);
            void operator *=(int i);
            void operator *=(float f);
            void operator *=(double d);

            float operator *(Vetor2D v) const;
            T modulo() const;
            Vetor2D versor() const;

            //projeção desse vetor na direção de v
            Vetor2D projOrtogonal(Vetor2D v) const;

            nlohmann::json paraJSON() override;
        };


        typedef Vetor2D<float> Vetor2F;
        typedef Vetor2D<int> VetorI;
        typedef Vetor2D<unsigned int> Vetor2U;

        template <typename T>
        std::ostream& operator <<(std::ostream& out, const Vetor2D<T>& v);

    }
}
#include "Vetor2DImplementacao.h"