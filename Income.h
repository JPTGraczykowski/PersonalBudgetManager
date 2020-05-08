#ifndef INCOME_H
#define INCOME_H

#include "Transaction.h"
#include <iostream>

using namespace std;

class Income : public Transaction
{
    int incomeId;

public:
    Income();
    int getIncomeId();
    void setIncomeId(int newId);
    void showIncomeDetails();
};

#endif // INCOME_H
