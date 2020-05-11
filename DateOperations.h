#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>

#include "AuxiliaryMethods.h"

using namespace std;

class DateOperations
{
public:
    static tm getDateFromString(string inputDate);
    static string convertDateToString(tm inputDate);
    static bool isDateCorrect(tm date);
    static int getDaysInMonthNumber(int month, int year);
    static bool isYearLeap(int year);
    static bool isDateAEarlierThanDateB(tm dateA, tm dateB);
    static tm enterTheDate();
    static tm getTodayDate();
};
#endif // DATEOPERATIONS_H
