#include "ExpenseManager.h"


void ExpenseManager::addExpense()
{
    Expense expense;

    system("cls");
    cout<<" $$$ ADD NEW EXPENSE $$$ "<<endl<<endl;

    expense = provideExpenseDetails();
    expenses.push_back(expense);

    expenseFile.addExpenseToFile(expense);
    expenseFile.setLastExpenseId(expense.getExpenseId());


    system("pause");
}


Expense ExpenseManager::provideExpenseDetails()
{
    Expense expense;

    expense.setExpenseId(expenseFile.getLastExpenseId() + 1);
    expense.setUserId(getLoggedInUserId());

    expense.setDate(setDateOfTransaction());

    cout<<endl<<"Set an item of the expense: ";
    expense.setItem(AuxiliaryMethods::getLine());

    cout<<endl<<"Set amount of the expense: ";
    expense.setAmount(AuxiliaryMethods::getCurrencyFloat());

    return expense;
}


void ExpenseManager::showExpensesFromTheMonth(int month)
{
    tm dateOfExpense;
    vector<Expense> expensesFromTheMonth;
    sumOfTheTransactions = 0;

    for(unsigned int i=0; i<expenses.size(); i++)
    {
        dateOfExpense = expenses[i].getDate();
        if(dateOfExpense.tm_mon == month)
        {
            expensesFromTheMonth.push_back(expenses[i]);
            sumOfTheTransactions += expenses[i].getAmount();
        }
    }

    sort(expensesFromTheMonth.begin(), expensesFromTheMonth.end());

    for(unsigned int i=0; i<expensesFromTheMonth.size(); i++)
    {
        expensesFromTheMonth[i].showExpenseDetails();
    }
}


void ExpenseManager::showExpensesFromOtherPeriodOfTime(tm startDate, tm stopDate)
{
    tm dateOfExpense;
    vector<Expense> expensesFromTheOtherPeriodOfTime;
    sumOfTheTransactions = 0;

    for (unsigned int i = 0; i<expenses.size(); i++)
    {
        dateOfExpense = expenses[i].getDate();
        if(!(AuxiliaryMethods::isDateAEarlierThanDateB(dateOfExpense, startDate))
           && !(AuxiliaryMethods::isDateAEarlierThanDateB(stopDate, dateOfExpense)))
           {
               expensesFromTheOtherPeriodOfTime.push_back(expenses[i]);
               sumOfTheTransactions += expenses[i].getAmount();
           }
    }

    sort(expensesFromTheOtherPeriodOfTime.begin(), expensesFromTheOtherPeriodOfTime.end());

    for(unsigned int i = 0; i<expensesFromTheOtherPeriodOfTime.size(); i++)
    {
        expensesFromTheOtherPeriodOfTime[i].showExpenseDetails();
    }
}
