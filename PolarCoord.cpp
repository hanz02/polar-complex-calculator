#include "PolarCoord.h"
#include "ComplexNumber.h"

#include <iostream>
#include <cmath>

using namespace std;

PolarCoord::PolarCoord()
{
    this->r = 0;
    this->deg = 0;
}

PolarCoord::PolarCoord(double r, double deg)
{
    this->r = r;
    this->deg = deg;
}

ComplexNumber PolarCoord::ToComplexNum() {
    ComplexNumber cn;
    cn.a = this->r * cos(this->deg * M_PI / 180);
    cn.b = this->r * sin(this->deg * M_PI / 180);

    return cn;
}

bool PolarCoord::is_equal();

double PolarCoord::getRadius()
{
    return this->r;
}

double PolarCoord::getDegree()
{
    return this->deg;
}

void PolarCoord::setRadius(double r)
{
    this->r = r;
}

void PolarCoord::setDegree(double deg)
{
    this->deg = deg;
}

string PolarCoord::ToString() {
    return to_string(this->r) + " ∠ " + to_string(this->deg);
}


