#include "ComplexNumber.h"
#include "PolarCoord.h"

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

ComplexNumber::ComplexNumber()
{
    this->a = 0;
    this->b = 0;
}

ComplexNumber::ComplexNumber(double a, double b)
{
    this->a = a;
    this->b = b;
}

PolarCoord ComplexNumber::ToPolarCoord(MODE my_mode) {

    PolarCoord polarCoord(my_mode);

    //* calculate for r (magnitude)
    polarCoord.r = sqrt(pow(this->a, 2) + pow(this->b, 2));

    //* calculate for deg (degree from x-axis or East)
    if(my_mode == DEG)
    {
        polarCoord.deg = atan(this->b / this->a);
        polarCoord.deg = polarCoord.deg * 180 / M_PI; //* turn radian to degree

        if(this-> a < 0)
        {
             polarCoord.deg += 180;

        }

    } else
    {
        polarCoord.rad = atan(this->b / this->a);
    }

    return polarCoord;

}
bool ComplexNumber::is_equal(PolarCoord &pc_input)
{
    PolarCoord pc = this->ToPolarCoord(pc_input.mode);

    return (pc == pc_input);

}

double ComplexNumber::getA() {
    return this->a;
}

double ComplexNumber::getB() {
    return this->b;
}

void ComplexNumber::setA(double a) {
    this->a = a;
}

void ComplexNumber::setB(double b) {
    this->b = b;
}

string ComplexNumber::ToString() {
    return to_string(this->a) + " + " + to_string(this->b) + "i";
}
