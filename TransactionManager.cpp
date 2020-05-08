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
            date = setTodayDate();
            isDateSet = true;
            break;
        case('2'):
            date = AuxiliaryMethods::enterTheDate();
            isDateSet = true;
            break;
        default:
            cout<<endl<<"Wrong number.";
            system("pause");
        }
    }

    return date;
}


tm TransactionManager::setTodayDate()
{
    time_t now = time(0);

    tm *indicateDate = localtime(&now);
    tm date;
    date.tm_year = 1900 + indicateDate->tm_year;
    date.tm_mon = 1 + indicateDate->tm_mon;
    date.tm_mday = indicateDate->tm_mday;

    return date;
}



float TransactionManager::getSumOfTransactions()
{
    return sumOfTheTransactions;
}



