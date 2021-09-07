#ifndef POLARCOORD_H
#define POLARCOORD_H

#include "ComplexNumber.h"
#include <string>

class ComplexNumber;

class PolarCoord
{
    public:
        PolarCoord();
        PolarCoord(double r, double deg);

        ComplexNumber ToComplexNum();
        bool operator==(PolarCoord const pc_input);

        double getRadius();
        double getDegree();
        void setRadius(double r);
        void setDegree(double deg);

        std::string ToString();

    private:
        double r;
        double deg;

    friend class ComplexNumber;

};

#endif // POLARCOORD_H
