#include "PolarCoord.h"
#include "ComplexNumber.h"
#include "ConversionMenu.h"

#include <iostream>
#include <cmath>

using namespace std;

ComplexNumber cn;
PolarCoord pc;

void conversionMenu(char &user_input)
{
    do
    {

        cout << "\n\n====== CONVERSION ======\n";
        cout << "\nChoose a conversion to perform below (Choose 1 to 2)\n\n";
        cout << "1. Complex Numbers to Polar Coordinates\n";
        cout << "2. Polar Coordinates to Complex Numbers\n";
        cout << "3. Return\n";

        cout << "\n> ";
        cin >> user_input;

        switch(user_input)
        {
        // polar coord to complex number
        case '1':

            double a;
            double b;

            opt_to_polarCoord(a, b);

            break;

        // polar coord to complex number
        case '2':

            double r;
            double deg;

            opt_to_complexNumber(r, deg);

            break;

        case '3':
            cout << "\nReturning to MAIN MENU.." <<endl;
            system("pause");
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            break;

        default:
            cout << "\nIncorrect Option Specified (Please choose option 1 to 2) \n";
            system("pause");
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            break;
        }
    }
    while(user_input != '3');
}

void opt_to_polarCoord(double a, double b)
{
    cout << "\nEnter your complex number (a + bi) form for conversion \n";
    cout << "a: ";
    cin >> a;

    if(!cin) // or if(cin.fail()), if user typed wrong input
    {
        cin.clear();
        cin.ignore();
        cout << "\nInvalid Input, please enter a number" <<endl;
        system("pause");
    }
    else
    {
        cout << "b: ";
        cin >> b;

        if(!cin) // or if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "\nInvalid Input, please enter a number" <<endl;
            system("pause");
        }
        else
        {
            cn.setA(a);
            cn.setB(b);

            pc = cn.ToPolarCoord();

            cout << "\nThe polar coordinate of " << a << " + " << b << "i is : " << pc.ToString() <<endl;
            system("pause");
            cout <<endl;
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

        }
    }
}

void opt_to_complexNumber(double r, double deg)
{
    cout << "\nEnter your polar coordinate (r ¡Ï deg) for conversion \n";
    cout << "r (radius): ";
    cin >> r;

    if(!cin) // or if(cin.fail()), if user typed wrong input
    {
        cin.clear();
        cin.ignore();
        cout << "\nInvalid Input, please enter a number" <<endl;
        system("pause");
    }
    else
    {
        cout << "deg (angular coordinate): ";
        cin >> deg;

        if(!cin) // or if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "\nInvalid Input, please enter a number" <<endl;
            system("pause");
        }
        else
        {
            pc.setRadius(r);
            pc.setDegree(deg);

            cn = pc.ToComplexNum();

            cout << "\nThe complex number (rectangular coordinate) of " << r << " ¡Ï " << deg << " is : " << cn.ToString() <<endl;
            system("pause");
            cout <<endl;
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

        }
    }
}
