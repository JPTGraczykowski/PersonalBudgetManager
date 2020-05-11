#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

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

public:
    ExpenseManager(int loggedInUserId, string expenseFileName)
    : TransactionManager(loggedInUserId), expenseFile(expenseFileName)
     {
         expenses = expenseFile.getExpensesOfLoggedInUserFromFile(getLoggedInUserId());
     };
    void addExpense();
    void showAllExpenses();
    void showExpensesFromTheMonth(int month);
    void showExpensesFromOtherPeriodOfTime(tm startDate,tm stopDate);
};

#endif // EXPENSEMANAGER_H
