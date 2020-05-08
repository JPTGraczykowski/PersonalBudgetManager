#include "Expense.h"

Expense::Expense()
{

}


int Expense::getExpenseId()
{
    return expenseId;
}


void Expense::setExpenseId(int newId)
{
    expenseId = newId;
}


void Expense::showExpenseDetails()
{
    cout<<"EXPENSE_ID: "<<expenseId<<endl;
    cout<<"USER_ID: "<<userId<<endl;
    cout<<"DATE: "<<date.tm_year<<"-"<<date.tm_mon<<"-"<<date.tm_mday<<endl;
    cout<<"ITEM: "<<item<<endl;
    cout<<"AMOUNT: "<<amount<<endl;
    cout<<"---------------------------"<<endl;
}
