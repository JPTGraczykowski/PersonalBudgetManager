#include "AuxiliaryMethods.h"


string AuxiliaryMethods::getLine()
{
    string inString = "";
    cin.sync();
    getline(cin, inString);
    return inString;
}

int  AuxiliaryMethods::convertStringToInt(string stringToChange)
{
    int intToReturn;
    istringstream iss(stringToChange);
    iss >> intToReturn;

    return intToReturn;
}
