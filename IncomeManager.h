#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "AuxiliaryMethods.h"
#include "TransactionManager.h"
#include "Income.h"
//#include "IncomeFile.h"

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class IncomeManager : public TransactionManager
{
    //IncomeFile incomeFile;
    vector<Income> incomes;

    Income provideIncomeDetails();

public:
    IncomeManager(int loggedInUserId) : TransactionManager(loggedInUserId) {};
    void addIncome();

};
#endif // INCOMEMANAGER_H
