#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <ctime>

using namespace std;

class AuxiliaryMethods
{
public:
    static char getChar();
    static string getLine();
    static int getInt();
    static float getCurrencyFloat();
    static string changeComaToDot(string number);
    static int convertStringToInt(string stringToChange);
    static float convertStringToFloat(string stringToChange);
    static string convertIntToString(int intToChange);
    static string convertFloatToString(float floatToString);
    static tm getDateFromString(string inputDate);
    static string convertDateToString(tm inputDate);
    static bool isDateCorrect(tm date);
    static int getDaysInMonthNumber(int month, int year);
    static bool isYearLeap(int year);
    static bool isDateAEarlierThanDateB(tm dateA, tm dateB);
    static tm enterTheDate();
    static string changeFirstLetterToUpper(string inputString);


};

#endif // AUXILIARYMETHODS_H
