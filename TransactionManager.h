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


protected:
    float sumOfTheTransactions;

public:
    TransactionManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId) {};
    int getLoggedInUserId();
    tm setDateOfTransaction();
    float getSumOfTheTransaction();
};
#endif // TRANSACTIONMANAGER_H
