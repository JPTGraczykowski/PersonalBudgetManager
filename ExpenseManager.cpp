#include "ExpenseManager.h"


void ExpenseManager::addExpense()
{
    Expense expense;

    system("cls");
    cout<<" $$$ ADD NEW Expense $$$ "<<endl<<endl;

    expense = provideExpenseDetails();
    expenses.push_back(expense);

    system("pause");
}


Expense ExpenseManager::provideExpenseDetails()
{
    Expense expense;

    expense.setExpenseId(1);
    expense.setUserId(getLoggedInUserId());

    expense.setDate(setDateOfTransaction());

    cout<<endl<<"Set an item of the expense: ";
    expense.setItem(AuxiliaryMethods::getLine());

    cout<<endl<<"Set amount of the expense: ";
    expense.setAmount(AuxiliaryMethods::getCurrnecyFloat());

    return expense;
}




