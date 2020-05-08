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
            date = setOtherDate();
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


tm TransactionManager::setOtherDate()
{
    tm date;
    int year, month, day;
    string inputDate = "";

    while(true)
    {
        system("cls");
        cout<<"Enter the date of the income (YYYY-MM-DD): "<<endl;
        inputDate = AuxiliaryMethods::getLine();
        date = AuxiliaryMethods::getDateFromString(inputDate);

        if(isDateCorect(date))
            break;
        else
        {
            cout<<endl<<"Date is incorect!"<<endl;
            system("pause");
        }
    }

    return date;
}


bool TransactionManager::isDateCorect(tm date)
{
    string stringYear = "";
    string stringMonth = "";
    string stringDay = "";

    if (date.tm_year < 0)
        return false;
    else if (date.tm_mon < 0 || date.tm_mon > 12)
        return false;
    else if (date.tm_mday < 0 || date.tm_mday > getDaysInMonthNumber(date.tm_mon, date.tm_year))
        return false;
    else
        return true;
}


bool TransactionManager::isYearLeap(int year)
{
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
        return true;
}


int TransactionManager::getDaysInMonthNumber(int month, int year)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if(month == 2)
    {
        if(isYearLeap(year))
            return 29;
        else
            return 28;
    }
    else
        return 31;
}



