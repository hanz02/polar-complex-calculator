#ifndef SUBMENU_H
#define SUBMENU_H

#include <stdexcept>

void conversionMenu(char &user_input, ComplexNumber &cn, PolarCoord &pc, MODE my_mode);
void opt_to_polarCoord(double a, double b, MODE my_mode);
void opt_to_complexNumber(double r, double deg, MODE my_mode);

void equivalenceMenu(char &user_input, MODE my_mode);

void displayMode(MODE current_mode);

void clearInputStream(std::istream &in);
void checkValidInputStream(std::istream &in) throw(std::invalid_argument);

#endif //SUBMENU_H

