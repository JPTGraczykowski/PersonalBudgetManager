#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include "DataFile.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "Expense.h"


#include <iostream>
#include <vector>


using namespace std;

class ExpenseFile : public DataFile
{
    Expense getExpenseDetails;
    int loggedInUserId;
public:
    ExpenseFile(string expenseFileName) : DataFile(expenseFileName);
    vector<Expense> getExpensesOfLoggedInUserFromFile;
    void addExpenseToFile(Expense expense);

};
#endif // EXPENSEFILE_H
