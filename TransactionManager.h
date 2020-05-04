#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class TransactionManager
{
    const int LOGGED_IN_USER_ID;

    string setTodayDate();
    string setOtherDate();
    bool isDateCorect();
    int getDaysInMonthNumber();
    bool isYearLeap();
    vector<string> setPeriodOfTime();
    bool isDateAEarlierThanDateB();
    float countTheBalanceDifference();

public:
    TransactionManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId) {};
    int getLoggedInUserId();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showOtherPeriodOfTimeBalance();
};
#endif // TRANSACTIONMANAGER_H
