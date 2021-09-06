#include "ComplexNumber.h"
#include "PolarCoord.h"
#include "ConversionMenu.h"

#include <iostream>

using namespace std;

int main()
{

    cout << "====== Welcome to my Complex Number and Polar Coordinates Calculator ======\n";

    char user_opt = '0';

    do {
        cout << "\n\n====== MAIN MENU ======\n";
        cout << "\nChoose an operation to perform below (Choose 1 to 3)\n\n";
        cout << "1. Polar Coordinates & Complex Numbers Conversion \n";
        cout << "2. Polar Coordinates Equality Check \n";
        cout << "4. Exit\n";

        cout << "\n> ";
        cin >> user_opt;

        switch(user_opt)
        {
            // conversion
            case '1':
                cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                conversionMenu(user_opt);
                break;

            case '2':

                break;
            // exit program
            case '4':
                cout << "\n====== Thank You for using the calculator ====== \n";
                break;
            default:
                cout << "\nIncorrect Option Specified (Please choose option 1 to 2) \n";
                system("pause");
                cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                break;
        }

    }
    while (user_opt != '4');

    return 0;
}




