#include "PolarCoord.h"
#include "ComplexNumber.h"

#include <iostream>
#include <cmath>

using namespace std;

PolarCoord::PolarCoord(MODE mode)
{
    this->r = 0;
    this->deg = 0;
    this->mode = mode;
}

PolarCoord::PolarCoord(double r, double deg_rad, MODE mode)
{
    this->r = r;
    (mode == RAD) ? this->rad = deg_rad : this->deg = deg_rad;
    this->mode = mode;
}

ComplexNumber PolarCoord::ToComplexNum() {

    ComplexNumber cn;

    cn.a = (this->mode == RAD) ? this->r * cos(this->rad) : this->r * cos(this->deg * M_PI / 180);
    cn.b = (this->mode == RAD) ? this->r * sin(this->rad) : this->r * sin(this->deg * M_PI / 180);
    return cn;
}

bool PolarCoord::operator==(PolarCoord const &pc_input) {


    double bigger = 0;
    bool result = false;

    //is the two radius is equal? (in terms of magnitude)
    if(abs(pc_input.r) != abs(this->r))
    {
        return false;
    }
    else
    {

        // if both radius are positive or negative
        if(pc_input.r == this->r)
        {

            bigger = (pc_input.deg > this->deg) ? pc_input.deg : this->deg;



            do
            {
                // if the degree reduced is equal to the degree of other coord, bingo! they are both the same coord
                if(bigger == this->deg || bigger == pc_input.deg) {
                    return true;
                }

                bigger = bigger - 360;

            } while(bigger > 360);

        }
        // one of them is negative
        else
        {
            bigger = (pc_input.deg > this->deg) ? pc_input.deg : this->deg;

            do
            {
                // if the degree reduced is equal to the degree of other coord, bingo! they are both the same coord
                if(bigger == this->deg || bigger == pc_input.deg) {
                    return true;
                }

                bigger = bigger - 180;

            } while(bigger > 180);
        }

        // if the degree of both coord are different even though their radius are the same, we still return false
        return false;
    }
}

double PolarCoord::getRadius()
{
    return this->r;
}

double PolarCoord::getDegree()
{
    return this->deg;
}

double PolarCoord::getRadian()
{
    return this->rad;
}

MODE PolarCoord::getMode()
{
    return this->mode;
}

void PolarCoord::setRadius(double r)
{
    this->r = r;
}

void PolarCoord::setDegree(double deg)
{
    this->deg = deg;
}

void PolarCoord::setRadian(double rad)
{
    this->rad = rad;
}

void PolarCoord::setMode(MODE mode)
{
    this->mode = mode;
}

string PolarCoord::ToString() {
    return to_string(this->r) + " ∠ " + to_string(this->deg);
}


