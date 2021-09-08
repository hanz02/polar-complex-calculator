#ifndef POLARCOORD_H
#define POLARCOORD_H

#include "ComplexNumber.h"
#include <string>

enum MODE {RAD, DEG};
class ComplexNumber;

class PolarCoord
{
    public:
        PolarCoord();
        PolarCoord(double r, double deg);

        ComplexNumber ToComplexNum();

        // it is legal to overload a operator twice IF AND ONLY IF they they have different parameters
        bool operator==(PolarCoord const &pc_input);

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
