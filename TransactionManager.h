#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>

#include "AuxiliaryMethods.h"

using namespace std;

class TransactionManager
{
    const int LOGGED_IN_USER_ID;

    tm setTodayDate();
    tm setOtherDate();
    bool isDateCorect(tm date);
    int getDaysInMonthNumber(int month, int year);
    bool isYearLeap(int year);
    vector<string> setPeriodOfTime();
    bool isDateAEarlierThanDateB();
    float countTheBalanceDifference();

public:
    TransactionManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId) {};
    int getLoggedInUserId();
    tm setDateOfTransaction();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showOtherPeriodOfTimeBalance();
};
#endif // TRANSACTIONMANAGER_H
