#include "TransactionManager.h"

int TransactionManager::getLoggedInUserId()
{
    return LOGGED_IN_USER_ID;
}


tm TransactionManager::setDateOfTransaction()
{
    char choice;
    bool isDateSet = false;
    tm date;

    while(!isDateSet)
    {
        system("cls");
        cout<<"Enter the date of the transaction.";
        cout<<endl<<"1. Today";
        cout<<endl<<"2. Other date";
        cout<<endl<<endl<<"Enter the number: ";

        choice = AuxiliaryMethods::getChar();

        switch(choice)
        {
        case('1'):
            date = DateOperations::getTodayDate();
            isDateSet = true;
            break;
        case('2'):
            date = DateOperations::enterTheDate();
            isDateSet = true;
            break;
        default:
            cout<<endl<<"Wrong number.";
            system("pause");
        }
    }

    return date;
}





float TransactionManager::getSumOfTransactions()
{
    return sumOfTheTransactions;
}



