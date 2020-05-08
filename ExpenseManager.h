#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "AuxiliaryMethods.h"
#include "TransactionManager.h"
#include "Expense.h"
#include "ExpenseFile.h"

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

class ExpenseManager : public TransactionManager
{
    ExpenseFile expenseFile;
    vector<Expense> expenses;

    Expense provideExpenseDetails();
    void prepareExpensesToPresent(vector<Expense> &expensesFromTheMonth);

public:
    ExpenseManager(int loggedInUserId, string expenseFileName)
    : TransactionManager(loggedInUserId), expenseFile(expenseFileName)
     {
         expenses = expenseFile.getExpensesOfLoggedInUserFromFile(getLoggedInUserId());
         showAllExpenses();
     };
    void addExpense();
    void showAllExpenses();
    void showExpensesFromTheMonth(int month);
};

#endif // EXPENSEMANAGER_H
