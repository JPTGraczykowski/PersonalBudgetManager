#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "AuxiliaryMethods.h"
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
         showAllIncomes();
     };
    void addIncome();
    void showAllIncomes();
    void showIncomesFromTheMonth(int month);

};
#endif // INCOMEMANAGER_H
