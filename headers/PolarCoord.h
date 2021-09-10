#ifndef POLARCOORD_H
#define POLARCOORD_H

#include <string>

enum MODE {RAD, DEG};
class ComplexNumber;

class PolarCoord
{
    public:
        PolarCoord(MODE mode);
        PolarCoord(double r, double deg_rad, MODE mode);

        ComplexNumber ToComplexNum();

        // it is legal to overload a operator twice IF AND ONLY IF they they have different parameters
        bool operator==(PolarCoord const &pc_input);

        double getRadius();
        double getDegree();
        double getRadian();
        MODE getMode();

        void setRadius(double r);
        void setDegree(double deg);
        void setRadian(double rad);
        void setMode(MODE mode);

        std::string ToString();

    private:
        double r;
        double deg;
        double rad;
        MODE mode;

    friend class ComplexNumber;

};

#endif // POLARCOORD_H
