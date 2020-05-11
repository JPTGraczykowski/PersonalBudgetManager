#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "TransactionManager.h"
#include "Income.h"
#include "IncomeFile.h"

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>


using namespace std;

class IncomeManager : public TransactionManager
{
    IncomeFile incomeFile;
    vector<Income> incomes;

    Income provideIncomeDetails();

public:
    IncomeManager(int loggedInUserId, string incomeFileName)
     : TransactionManager(loggedInUserId), incomeFile(incomeFileName)
     {
         incomes = incomeFile.getIncomesOfLoggedInUserFromFile(getLoggedInUserId());
     };
    void addIncome();
    void showIncomesFromTheMonth(int month);
    void showIncomesFromOtherPeriodOfTime(tm startDate, tm stopDate);

};
#endif // INCOMEMANAGER_H
