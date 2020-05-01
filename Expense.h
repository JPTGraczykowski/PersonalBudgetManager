#ifndef EXPENSE_H
#define EXPENSE_H

#include "Transaction.h"
#include <iostream>

using namespace std;

class Expense : public Transaction
{
    int expenseId;

public:
    Expense();
    int getExpenseId();
    void setExpenseId(int newId);
};

#endif // EXPENSE_H
