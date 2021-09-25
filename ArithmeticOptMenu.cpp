#include "ComplexNumber.h"
#include "PolarCoord.h"
#include "SubMenus.h"
#include "ArithmeticOptMenu.h"

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;


void ComplexNumberArithmeticMenu()
{
    ComplexNumber cn1, cn2, cn_product;
    double number_input = 0;
    char user_opt = '0';

    try
    {
        cout << "\n\n====== COMPLEX NUMBERS ARITHMERTIC ======\n";

        cout << "\nFirst enter 2 complex number and specify the arithmetic operation to perform\n\n";

        // user input two complex numbers
        cout << "--- First Complex Number (a + bi) form ---\n";
        cout << "a (real number): ";
        cin >> number_input;
        checkValidInputStream(cin);
        cn1.setA(number_input);

        cout << "b (imaginary number): ";
        cin >> number_input;
        checkValidInputStream(cin);
        cn1.setB(number_input);

        cout << "\n--- Second Complex Number (a + bi) form ---\n";
        cout << "a (real number): ";
        cin >> number_input;
        checkValidInputStream(cin);
        cn2.setA(number_input);

        cout << "b (imaginary number): ";
        cin >> number_input;
        checkValidInputStream(cin);
        cn2.setB(number_input);

        do
        {
            cout << "\nPlease specify the operation SYMBOL to perform on the 2 complex numbers\n";
            cout << "1. Add: " << cn1.ToString() << " + "<< cn2.ToString() << "\n";
            cout << "2. Subtract: " << cn1.ToString() << " - "<< cn2.ToString() << "\n";
            cout << "3. Multiply: " << cn1.ToString() << " * "<< cn2.ToString() << "\n";
            cout << "4. Divide: " << cn1.ToString() << " / "<< cn2.ToString() << "\n";
            cout << "\n> ";
            cin >> user_opt;

            switch(user_opt)
            {
            case '1':
                cout << "\n---- RESULT ----\n";
                cout << endl << cn1.ToString() << " + "<< cn2.ToString() << "\n";
                cn_product = cn1 + cn2;
                cout << "= " << cn_product.ToString() <<endl <<endl;

                system("pause");
                cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

                break;

            case '2':
                cout << "\n---- RESULT ----\n";
                cout << endl << cn1.ToString() << " - "<< cn2.ToString() << "\n";
                cn_product = cn1 - cn2;
                cout << "= " << cn_product.ToString() <<endl <<endl;

                system("pause");
                cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

                break;

            case '3':

                cout << "\n---- RESULT ----\n";
                cout << endl << cn1.ToString() << " * "<< cn2.ToString() << "\n";
                cn_product = cn1 * cn2;
                cout << "= " << cn_product.ToString() <<endl <<endl;

                system("pause");
                cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

                break;

            case '4':

                cout << "\n---- RESULT ----\n";
                cout << endl << cn1.ToString() << " / "<< cn2.ToString() << "\n";
                cn_product = cn1 / cn2;
                cout << "= " << cn_product.ToString() <<endl <<endl;

                system("pause");
                cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

                break;

            default:

                user_opt = 'n';
                clearInputStream(cin);
                cout << "\nInvalid input, please input a number\n";
                system("pause");
                cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

                break;
            }

        }
        while (user_opt == 'n');

    }
    catch (invalid_argument e)
    {
        cout << "\nInvalid input, please input a number\n";
        clearInputStream(cin);
        system("pause");
        cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    }
}

void PolarCoordArithmeticMenu(MODE my_mode)
{

    PolarCoord pc1(my_mode), pc2(my_mode),pc_product(my_mode);
    double number_input = 0;
    char user_opt = '0';

    try
    {
        cout << "\n\n====== POLAR COORDINATES ARITHMERTIC ======";
        displayMode(my_mode);
        cout << "\nFirst enter 2 polar coordinates and specify the arithmetic operation to perform\n\n";

        // user input two complex numbers
        cout << "--- First Polar Coordinate (radius , "<< (my_mode == RAD ? "radian" : "degree") << ") form ---\n";

        cout << "r (radius): ";
        cin >> number_input;
        checkValidInputStream(cin);
        pc1.setRadius(number_input);

        cout << (my_mode == RAD ? "r (Radian)" : "deg (Degree)") << ": ";
        cin >> number_input;
        checkValidInputStream(cin);
        (my_mode == RAD ? pc1.setRadian(number_input) : pc1.setDegree(number_input));

        cout << "\n--- Second Polar Coordinate (radius , "<< (my_mode == RAD ? "radian" : "degree") << ") form ---\n";
        cout << "r (radius): ";
        cin >> number_input;
        checkValidInputStream(cin);
        pc2.setRadius(number_input);

        cout << (my_mode == RAD ? "r (Radian)" : "deg (Degree)") << ": ";
        cin >> number_input;
        checkValidInputStream(cin);
        (my_mode == RAD ? pc2.setRadian(number_input) : pc2.setDegree(number_input));

        //user specify arithmetic operation to be performed
        do
        {
            cout << "\nPlease specify the operation SYMBOL to perform on the 2 polar coordinates\n";
            cout << "1. Add: " << pc1.ToString() << " + "<< pc2.ToString() << "\n";
            cout << "2. Subtract: " << pc1.ToString() << " - "<< pc2.ToString() << "\n";
            cout << "3. Multiply: " << pc1.ToString() << " * "<< pc2.ToString() << "\n";
            cout << "4. Divide: " << pc1.ToString() << " / "<< pc2.ToString() << "\n";
            cout << "\n> ";
            cin >> user_opt;

            cout << "\n---- RESULT ----\n";
            switch(user_opt)
            {
            case '1':

                cout << endl << pc1.ToString() << " + "<< pc2.ToString() << "\n";
                pc_product = pc1 + pc2;
                cout << "= " << pc_product.ToString() <<endl <<endl;
                break;

            case '2':
                cout << endl << pc1.ToString() << " - "<< pc2.ToString() << "\n";
                pc_product = pc1 - pc2;
                cout << "= " << pc_product.ToString() <<endl <<endl;

                break;

            case '3':

                cout << endl << pc1.ToString() << " * "<< pc2.ToString() << "\n";
                pc_product = pc1 * pc2;
                cout << "= " << pc_product.ToString() <<endl <<endl;
                break;

            case '4':

                cout << endl << pc1.ToString() << " / "<< pc2.ToString() << "\n";
                pc_product = pc1 / pc2;
                cout << "= " << pc_product.ToString() <<endl <<endl;
                break;

            default:
                user_opt = 'n';
                clearInputStream(cin);
                cout << "\nInvalid input, please input a number\n";
                break;
            }

            system("pause");
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

        }
        while (user_opt == 'n');

    }
    catch (invalid_argument e)
    {
        cout << "\nInvalid input, please input a number\n";
        clearInputStream(cin);
        system("pause");
        cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

    }
}
