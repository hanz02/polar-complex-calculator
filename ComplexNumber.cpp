#include "headers/ComplexNumber.h"
#include "headers/PolarCoord.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

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

    stringstream stream;
    stream << setprecision(4) << this->a;
    string out_a = stream.str();
    stream.str("");
    stream.clear();

    stream << setprecision(4) << (this->b < 0 ? abs(this->b) : this->b);
    string out_b = stream.str();
    stream.str("");
    stream.clear();

    string result;

    // if the result (a + bi) where b = 0, we know it's a real number.
    // Then we can just output the 'a' and ignore 'bi'
    if(this->b == 0)
    {
        return out_a;
    }
    // displaying string of form (a - bi) where b is less than 0
    else if(this->b < 0)
    {
        // return string (a - i) where if b = -1
        return (this->b == -1 ? "(" + out_a + " - i)" : "(" + out_a + " - " + out_b + "i)");
    }
    // displaying string of form (a + i) where b is less than 0
    else
    {
        // return string (a + i) where if b = 1
        return (this->b == 1 ? "(" + out_a + " + i)" : "(" + out_a + " + " + out_b + "i)");
    }

}

// arithmetic operators overloading
ComplexNumber ComplexNumber::operator+ (ComplexNumber cn_input)
{
    ComplexNumber cn_output;
    cn_output.setA(cn_input.a + this->a);
    cn_output.setB(cn_input.b + this->b);

    return cn_output;
}

ComplexNumber ComplexNumber::operator- (ComplexNumber cn_input)
{
    ComplexNumber cn_output;
    cn_output.setA(this->a - cn_input.a);
    cn_output.setB(this->b - cn_input.b);

    return cn_output;
}

ComplexNumber ComplexNumber::operator* (ComplexNumber cn_input)
{
    ComplexNumber cn_output;
    cn_output.setA(this->a * cn_input.a - this->b * cn_input.b);
    cn_output.setB(this->a * cn_input.b + this->b * cn_input.a);

    return cn_output;
}

ComplexNumber ComplexNumber::operator/ (ComplexNumber cn_input)
{
    ComplexNumber cn_output;
    cn_output.setA((this->a * cn_input.a + this->b * cn_input.b)/ (pow(cn_input.a, 2) + pow(cn_input.b, 2)));
    cn_output.setB((this->b * cn_input.a - this->a * cn_input.b)/ (pow(cn_input.a, 2) + pow(cn_input.b, 2)));

    return cn_output;
}
