#include "ExpenseManager.h"


void ExpenseManager::addExpense()
{
    Expense expense;

    system("cls");
    cout<<" $$$ ADD NEW Expense $$$ "<<endl<<endl;

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


void ExpenseManager::showAllExpenses()
{
    system("cls");
    for(int i=0; i<expenses.size(); i++)
    {
        expenses[i].showExpenseDetails();
    }
    system("pause");
}


void ExpenseManager::showExpensesFromTheMonth(int month)
{
    tm dateOfExpense;

    vector<Expense> expensesFromTheMonth;

    for(unsigned int i=0; i<expenses.size(); i++)
    {
        dateOfExpense = expenses[i].getDate();
        if(dateOfExpense.tm_mon == month)
        {
            expensesFromTheMonth.push_back(expenses[i]);
        }
    }

    prepareExpensesToPresent(expensesFromTheMonth);

    for(unsigned int i=0; i<expensesFromTheMonth.size(); i++)
    {
        expensesFromTheMonth[i].showExpenseDetails();
    }
}

void ExpenseManager::prepareExpensesToPresent(vector<Expense> &expensesFromTheMonth)
{
    sort(expensesFromTheMonth.begin(), expensesFromTheMonth.end());
    reverse(expensesFromTheMonth.begin(), expensesFromTheMonth.end());
}




