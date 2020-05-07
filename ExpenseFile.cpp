#include "ExpenseFile.h"


Expense ExpenseFile::getExpenseDetails(CMarkup &file)
{
    Expense expense;

    file.IntoElem();
    file.FindElem("EXPENSE_ID");
    expense.setExpenseId(AuxiliaryMethods::convertStringToInt(file.GetData()));
    file.FindElem("USER_ID");
    expense.setUserId(AuxiliaryMethods::convertStringToInt(file.GetData()));
    file.FindElem("DATE");
    expense.setDate(AuxiliaryMethods::getDateFromString(file.GetData() + "-"));
    file.FindElem("ITEM");
    expense.setItem(file.GetData());
    file.FindElem("AMOUNT");
    expense.setAmount(AuxiliaryMethods::convertStringToFloat(file.GetData()));
    file.OutOfElem();


    return expense;
}


vector<Expense> ExpenseFile::getExpensesOfLoggedInUserFromFile(int loggedInUserId)
{
    Expense expense;
    vector<Expense> expenses;
    CMarkup file;

    bool fileExists = file.Load(getFileName().c_str());
    bool isFileEmpty = true;

    if(fileExists)
    {
        file.FindElem(); //go to EXPENSES
        file.IntoElem(); //go to EXPENSES
        while(file.FindElem("EXPENSE"))
        {
            isFileEmpty = false;
            expense = getExpenseDetails(file);
            if(expense.getUserId() == loggedInUserId)
                expenses.push_back(expense);
        }
        if (!isFileEmpty)
            lastExpenseId = expense.getExpenseId();
        else
            lastExpenseId = 0;
    }
    else
    {
        system("cls");
        cout<<"XML file error!";
        system("pause");
    }

    return expenses;
}


int ExpenseFile::getLastExpenseId()
{
    return lastExpenseId;
}


void ExpenseFile::setLastExpenseId(int newLastExpenseId)
{
    lastExpenseId = newLastExpenseId;
}


void ExpenseFile::addExpenseToFile(Expense expense)
{
    CMarkup file;

    bool fileExists = file.Load(getFileName().c_str());

    if(fileExists)
    {
        file.FindElem(); //go to EXPENSES
        file.IntoElem(); //go to EXPENSES

        file.AddElem("EXPENSE");
        file.IntoElem();

        file.AddElem("EXPENSE_ID", expense.getExpenseId());
        file.AddElem("USER_ID", expense.getUserId());
        file.AddElem("DATE", AuxiliaryMethods::convertDateToString(expense.getDate()));
        file.AddElem("ITEM", expense.getItem());
        file.AddElem("AMOUNT", expense.getAmount());

        file.Save(getFileName().c_str());
    }
    else
    {
        system("cls");
        cout<<"XML file error!";
        system("pause");
    }

}
