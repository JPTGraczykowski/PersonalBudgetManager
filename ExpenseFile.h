#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include "DataFile.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"
#include "Markup.h"
#include "Expense.h"


#include <iostream>
#include <vector>


using namespace std;

class ExpenseFile : public DataFile
{
    int lastExpenseId;

    Expense getExpenseDetails(CMarkup &file);
public:
    ExpenseFile(string expenseFileName) : DataFile(expenseFileName) {};
    vector<Expense> getExpensesOfLoggedInUserFromFile(int loggedInUserId);
    void addExpenseToFile(Expense expense);
    int getLastExpenseId();
    void setLastExpenseId(int newLastExpenseId);

};
#endif // EXPENSEFILE_H
