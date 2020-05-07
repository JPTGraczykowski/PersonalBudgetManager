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
        cout<<"EXPENSE_ID: "<<expenses[i].getExpenseId()<<endl;
        cout<<"USER_ID: "<<expenses[i].getUserId()<<endl;
        tm date = expenses[i].getDate();
        cout<<"DATE: "<<date.tm_year<<"-"<<date.tm_mon<<"-"<<date.tm_mday<<endl;
        cout<<"ITEM: "<<expenses[i].getItem()<<endl;
        cout<<"AMOUNT: "<<expenses[i].getAmount()<<endl;
        cout<<"_______________"<<endl;
    }
    system("pause");
}




