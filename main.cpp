#include "ComplexNumber.h"
#include "PolarCoord.h"
#include "SubMenus.h"

#include <iostream>

using namespace std;

ComplexNumber cn;
PolarCoord pc;

void IOChangeMenu(MODE &current_mode);

int main()
{
    cout << "====== Welcome to my Complex Number and Polar Coordinates Calculator ======\n";
    MODE my_mode = RAD;

    char user_opt = '0';

    do
    {
        cout << "\n\n====== MAIN MENU ======";
        displayMode(my_mode);
        cout << "\nChoose an operation to perform below (Choose 1 to 3)\n\n";
        cout << "1. Polar Coordinates & Complex Numbers Conversion \n";
        cout << "2. Polar Coordinates Equality Check \n";
        cout << "3. Change In/Output Mode (RADIAN / DEGREE)\n";
        cout << "4. Exit\n";

        cout << "\n> ";
        cin >> user_opt;

        switch(user_opt)
        {
        // conversion
        case '1':
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            conversionMenu(user_opt, cn, pc);
            user_opt = '0';
            break;

        case '2':
        {
            equivalenceMenu(user_opt);
            user_opt = '0';
            break;
        }

        case '3':
        {
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            IOChangeMenu(my_mode);
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            break;
        }

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

void IOChangeMenu(MODE &current_mode)
{

    char user_opt;

    cout << "\n[Your current Input/Output Mode is " << (current_mode == RAD ? "RADIAN" : "DEGREE") << "]";
    cout << "\n\nPick an Input/Output Mode to change below (Select 1 or 2): \n";
    cout << "1. RADIAN \n";
    cout << "2. DEGREE \n";

    cout << "\n> ";
    cin >> user_opt;

    switch (user_opt)
    {
    case '1':
        current_mode = RAD;
        cout << "\nCurrent Input/Output Mode set to RADIAN successfully \n";
        system("pause");
        break;

    case '2':
        current_mode = DEG;
        cout << "\nCurrent Input/Output Mode set to DEGREE successfully \n";
        system("pause");
        break;

    default:
        cout << "\nInvalid input, please input a number\n";
        system("pause");

        break;
    }

}




