#include "PolarCoord.h"
#include "ComplexNumber.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

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

bool PolarCoord::operator==(PolarCoord const &pc_input)
{

    double bigger = 0;
    double smaller = 0;
    bool result = false;


    //is the two radius is equal? (in terms of magnitude)
    if(abs(round(pc_input.r)) != abs(round(this->r)))
    {
        return false;
    }
    else
    {

        // if the mode is DEGREE
        if(this->mode == DEG)
        {
            bigger = (pc_input.deg >= this->deg) ? pc_input.deg : this->deg;
            smaller = (pc_input.deg <= this->deg) ? pc_input.deg : this->deg;

        // if the mode is RADIAN
        } else
        {

            bigger = (pc_input.rad >= this->rad) ? pc_input.rad : this->rad;
            smaller = (pc_input.rad <= this->rad) ?  pc_input.rad : this->rad;


        }

        // if both radius are positive or negative
        if(round(pc_input.r) == round(this->r))
        {
            // if the mode is DEGREE
            if(this->mode == DEG)
            {
                do
                {
                    // if the degree reduced is equal to the degree of other coord, bingo! they are both the same coord
                    if(round(bigger) == round(smaller)) {
                        return true;
                    }

                    bigger = bigger - 360;

                } while(bigger >= smaller);

            // if the mode is RADIAN
            } else
            {
                do
                {
                    // if the degree reduced is equal to the degree of other coord, bingo! they are both the same coord
                    if(round(bigger) == round(smaller)) {
                        return true;
                    }

                    bigger = bigger - (2 * M_PI);

                } while(bigger >= smaller);
            }
        }
        // one of them is negative
        else
        {

            // if the mode is DEGREE
            if(this->mode == DEG)
            {

                do
                {
                    // if the degree reduced is equal to the degree of other coord, bingo! they are both the same coord
                    if(round(bigger) == round(smaller)) {
                        return true;
                    }

                    bigger = bigger - 180;

                } while(bigger >= smaller);

            // if the mode is RADIAN
            } else
            {
                do
                {
                    // if the degree reduced is equal to the degree of other coord, bingo! they are both the same coord
                    if(round(bigger) == round(smaller)) {
                        return true;
                    }
                    bigger = bigger - M_PI;

                } while(bigger >= smaller);
            }
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

    stringstream stream;
    stream << fixed << setprecision(4) << this->r;
    string out_r = stream.str();
    stream.str("");
    stream.clear();

    stream << fixed << setprecision(4) << (this->mode == RAD ? this->rad : this->deg);
    string out_degRad = stream.str();
    stream.str("");
    stream.clear();

    return "(" + out_r + ", " + out_degRad + ")";
}


// arithmetic operators overloading
PolarCoord PolarCoord::operator+ (PolarCoord pc_input)
{
    PolarCoord pc_output(this->mode);
    ComplexNumber cn_temp = this->ToComplexNum() + pc_input.ToComplexNum();

    pc_output = cn_temp.ToPolarCoord(this->mode);

    return pc_output;

}

PolarCoord PolarCoord::operator- (PolarCoord pc_input)
{
    PolarCoord pc_output(this->mode);
    ComplexNumber cn_temp = this->ToComplexNum() - pc_input.ToComplexNum();

    pc_output = cn_temp.ToPolarCoord(this->mode);

    return pc_output;
}

PolarCoord PolarCoord::operator* (PolarCoord pc_input)
{
    PolarCoord pc_output(this->mode);
    pc_output.setRadius(this->r * pc_input.r);

    (this->mode == RAD) ? pc_output.setRadian(this->r + pc_input.r) : pc_output.setDegree(this->deg + pc_input.deg);


    return pc_output;
}

PolarCoord PolarCoord::operator/ (PolarCoord pc_input)
{
    PolarCoord pc_output(this->mode);
    pc_output.setRadius(this->r / pc_input.r);
    (this->mode == RAD) ? pc_output.setRadian(this->r - pc_input.r) : pc_output.setDegree(this->deg - pc_input.deg);

    return pc_output;
}


