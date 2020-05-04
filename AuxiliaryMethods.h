#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static char getChar();
    static string getLine();
    static int convertStringToInt(string stringToChange);
    static string convertIntToString(int intToChange);

};

#endif // AUXILIARYMETHODS_H
