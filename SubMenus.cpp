#include "PolarCoord.h"
#include "ComplexNumber.h"
#include "SubMenus.h"

#include <iostream>
#include <cmath>
#include <limits>


using namespace std;

void clearInputStream(istream &in)
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void checkValidInputStream(istream &in) throw(invalid_argument)
{

    if(in.fail()) // or if(cin.fail()), if user typed wrong input
    {
        clearInputStream(cin);
        throw invalid_argument("Inavlid Input Provided, please input the correct data type");
    }

}

void conversionMenu(char &user_input, ComplexNumber &cn, PolarCoord &pc, MODE my_mode)
{
    do
    {

        cout << "\n\n====== CONVERSION ======";
        displayMode(my_mode);
        cout << "\nChoose a conversion to perform below (Choose 1 to 3)\n\n";
        cout << "1. Complex Numbers to Polar Coordinates\n";
        cout << "2. Polar Coordinates to Complex Numbers\n";
        cout << "3. Return\n";

        cout << "\n> ";
        cin >> user_input;

        switch(user_input)
        {
        // complex number to polar coord
        case '1':

            double a;
            double b;

            opt_to_polarCoord(a, b, my_mode);
            user_input = '0';

            break;

        // polar coord to complex number
        case '2':

            double r;
            double deg;

            opt_to_complexNumber(r, deg, my_mode);
            user_input = '0';

            break;

        case '3':
            cout << "\nReturning to MAIN MENU.." <<endl;
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            break;

        default:
            clearInputStream(cin);
            cout << "\nIncorrect Option Specified (Please choose option 1 to 2) \n";
            system("pause");
            user_input = '0';
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            break;
        }
    }
    while(user_input != '3');
}



void opt_to_polarCoord(double a, double b,MODE my_mode)
{
    try
    {
        ComplexNumber cn;
        PolarCoord pc(my_mode);

        cout << "\nEnter your complex number (a + bi) form for conversion \n";
        cout << "a (real number): ";
        cin >> a;

        checkValidInputStream(cin);

        cout << "b (imaginary number): ";
        cin >> b;

        checkValidInputStream(cin);

        cn.setA(a);
        cn.setB(b);

        pc = cn.ToPolarCoord(my_mode);

        cout << "\nThe polar coordinate of " << a << " + " << b << "i is : " << pc.ToString() << "\n";
        system("pause");
        cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

    }
    catch (invalid_argument e)
    {
        cout << "\nInvalid input, please input a number\n";
        system("pause");
        cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    }
}

void opt_to_complexNumber(double r, double deg,MODE my_mode)
{
    ComplexNumber cn;
    PolarCoord pc(my_mode);

    try
    {
        cout << "\nEnter your polar coordinate (r ¡Ï " << (my_mode == RAD ? "radian" : "degree")  << ") for conversion \n";
        cout << "r (radius): ";
        cin >> r;

        checkValidInputStream(cin);

        cout << (my_mode == RAD ? "radian" : "deg (angle degree)") << ": ";
        cin >> deg;

        checkValidInputStream(cin);

        pc.setRadius(r);
        (my_mode == RAD ? pc.setRadian(deg) : pc.setDegree(deg));

        cn = pc.ToComplexNum();

        cout << "\nThe complex number (rectangular coordinate) of " << r << " , " << deg << " is : " << cn.ToString() <<endl;
        system("pause");
        cout <<endl;
        cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

    }
    catch (invalid_argument e)
    {
        cout << "\nInvalid input, please input a number\n";
        system("pause");
        cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    }


}


void equivalenceMenu(char &user_input, MODE my_mode)
{
    ComplexNumber cn;
    PolarCoord pc(my_mode), pc1(my_mode);

    double r, deg, a, b;

    do
    {
        cout << "\n\n====== EQUIVALENCE CHECK ======";
        displayMode(my_mode);
        cout << "\nChoose an operation to perform below (Choose 1 to 3)\n\n";
        cout << "1. Check two equal Polar Coordinates\n";
        cout << "2. Check equivalence between Polar Coordinate and Complex Number\n";
        cout << "3. Return\n";

        cout << "\n> ";
        cin >> user_input;

        switch(user_input)
        {
        // check polar coord and polar coord equals
        case '1':
            try
            {
                cout << "\nPlease enter two polar coordinate (r, "<< (my_mode == RAD ? "radian" : "degree") <<") to check if they are equal. \n\n";

                cout << "--- 1st Coordinate --- \n";
                cout << "r (radius): ";
                cin >> r;
                checkValidInputStream(cin);

                pc.setRadius(r);

                cout << (my_mode == RAD ? "Radian" : "Angle Degree") << ": ";
                cin >> deg;
                checkValidInputStream(cin);
                (my_mode == RAD ? pc.setRadian(deg) : pc.setDegree(deg));

                cout << "\n--- 2nd Coordinate --- \n";
                cout << "r (radius): ";
                cin >> r;
                checkValidInputStream(cin);
                pc1.setRadius(r);

                cout << (my_mode == RAD ? "Radian" : "Angle Degree") << ": ";
                cin >> deg;
                checkValidInputStream(cin);
                (my_mode == RAD ? pc1.setRadian(deg) : pc1.setDegree(deg));

                (pc1 == pc) ? cout << "\nThe two polar coordinates are equal\n" : cout << "The two polar coordinates are not equal \n";
                system("pause");
                cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

            }
            catch (invalid_argument e)
            {
                cout << "\nInvalid input, please input a number\n";
                system("pause");
                cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            }

            break;

        // check polar coord and complex number equals
        case '2':
            try
            {

                cout << "\nPlease enter a polar coordinate (r, "<< (my_mode == RAD ? "radian" : "degree") <<") and a complex number (a + bi) to check if they are equal. \n\n";

                cout << "--- Your Polar Coordinate --- \n";
                cout << "r (radius): ";
                cin >> r;
                checkValidInputStream(cin);

                pc.setRadius(r);

                cout << (my_mode == RAD ? "Radian" : "Angle Degree") << ": ";
                cin >> deg;
                checkValidInputStream(cin);
                (my_mode == RAD ? pc.setRadian(deg) : pc.setDegree(deg));


                cout << "\n--- Your Complex Number --- \n";
                cout << "a (real number): ";
                cin >> a;
                checkValidInputStream(cin);
                cn.setA(a);

                cout << "b (imaginary number): ";
                cin >> b;
                checkValidInputStream(cin);
                cn.setB(b);

                (cn.is_equal(pc)) ? cout << "\nThe two polar coordinates are equal\n" : cout << "The two polar coordinates are not equal \n";
                system("pause");

            }
            catch (invalid_argument e)
            {
                cout << "\nInvalid input, please input a number\n";
                system("pause");
                cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            }

            break;

        case '3':
            cout << "\nReturning to MAIN MENU.." <<endl;
            system("pause");
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            break;

        default:
            clearInputStream(cin);
            cout << "\nIncorrect Option Specified (Please choose option 1 to 3) \n";
            system("pause");
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            break;
        }
    }
    while(user_input != '3');

}

void displayMode(MODE current_mode)
{
    (current_mode == RAD) ? cout << "\t\t[In/Output Mode: RADIAN] \n" : cout << "\t\t[In/Output Mode: DEGREE] \n";
}


