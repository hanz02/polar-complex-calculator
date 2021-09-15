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
        system("pause");
        cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    }
}
