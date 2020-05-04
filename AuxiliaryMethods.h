#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class AuxiliaryMethods
{
public:
    static char getChar();
    static string getLine();
    static float getCurrnecyFloat();
    static int convertStringToInt(string stringToChange);
    static string convertIntToString(int intToChange);

};

#endif // AUXILIARYMETHODS_H
