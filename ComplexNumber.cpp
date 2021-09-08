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

PolarCoord ComplexNumber::ToPolarCoord() {

    PolarCoord polarCoord;

    //* calculate for r (magnitude)
    polarCoord.r = sqrt(pow(this->a, 2) + pow(this->b, 2));

    //* calculate for deg (degree from x-axis or East)
    polarCoord.deg = atan(this->b / this->a);
    polarCoord.deg = polarCoord.deg * 180 / M_PI; //* turn radian to degree


    if (this-> a < 0)
    {
         polarCoord.deg += 180;

    }

    return polarCoord;

}
bool ComplexNumber::is_equal(PolarCoord &pc_input) {
    ComplexNumber cn_input = pc_input.ToComplexNum();

    cn_input.setA(round(cn_input.getA()));
    cn_input.setB(round(cn_input.getB()));

    return true;

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
