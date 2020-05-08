#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "AuxiliaryMethods.h"
#include "TransactionManager.h"
#include "Expense.h"
#include "ExpenseFile.h"

#include <iostream>Expense
#include <vector>
#include <windows.h>

class ExpenseManager : public TransactionManager
{
    ExpenseFile expenseFile;
    vector<Expense> expenses;

    Expense provideExpenseDetails();

public:
    ExpenseManager(int loggedInUserId, string expenseFileName)
    : TransactionManager(loggedInUserId), expenseFile(expenseFileName)
     {
         expenses = expenseFile.getExpensesOfLoggedInUserFromFile(getLoggedInUserId());
         showAllExpenses();
     };
    void addExpense();
    void showAllExpenses();
};

#endif // EXPENSEMANAGER_H