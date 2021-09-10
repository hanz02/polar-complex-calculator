#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include "PolarCoord.h"
#include <string>

class PolarCoord;

class ComplexNumber
{
    public:
        ComplexNumber();
        ComplexNumber(double a, double b);

        PolarCoord ToPolarCoord(MODE my_mode);
        bool is_equal(PolarCoord &pc_input);

        double getA();
        double getB();
        void setA(double a);
        void setB(double b);

        std::string ToString();

    private:
        double a;
        double b;

    friend class PolarCoord;
};

#endif // COMPLEXNUMBER_H
