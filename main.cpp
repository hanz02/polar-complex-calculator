#include "ComplexNumber.h"
#include "PolarCoord.h"
#include "SubMenus.h"
#include "ArithmeticOptMenu.h"

#include <iostream>
#include <limits>

using namespace std;

MODE my_mode = DEG;

ComplexNumber cn;
PolarCoord pc(my_mode);

void IOChangeMenu(MODE &current_mode);

int main()
{
    cout << "====== Welcome to my Complex Number and Polar Coordinates Calculator ======\n";

    char user_opt = '0';

    do
    {
        cout << "\n\n====== MAIN MENU ======";
        displayMode(my_mode);
        cout << "\nChoose an operation to perform below (Choose 1 to 3)\n\n";
        cout << "1. Polar Coordinates & Complex Numbers Conversion \n";
        cout << "2. Polar Coordinates Equality Check \n";
        cout << "3. Complex Numbers Arithmetic Operations \n";
        cout << "4. Polar Coordinates Arithmetic Operations \n\n";
        cout << "5. Change In/Output Mode (RADIAN / DEGREE)\n";
        cout << "6. Exit\n";

        cout << "\n> ";
        cin >> user_opt;

        switch(user_opt)
        {
        // conversion
        case '1':
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            conversionMenu(user_opt, cn, pc, my_mode);
            user_opt = '0';
            break;

        case '2':
        {
            equivalenceMenu(user_opt,my_mode);
            user_opt = '0';
            break;
        }

        case '3':
        {
            ComplexNumberArithmeticMenu();
            break;
        }

        case '4':
        {

            PolarCoordArithmeticMenu(my_mode);

            break;
        }

        case '5':
        {
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            IOChangeMenu(my_mode);
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            break;
        }

        // exit program
        case '6':
            cout << "\n====== Thank You for using the calculator ====== \n";
            break;
        default:
            clearInputStream(cin);
            cout << "\nIncorrect Option Specified (Please choose option 1 to 2) \n";
            system("pause");
            cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            break;
        }

    }
    while (user_opt != '6');

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
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nInvalid input, please input a number\n";
        system("pause");

        break;
    }

}




