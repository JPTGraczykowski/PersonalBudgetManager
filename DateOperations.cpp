#include "DateOperations.h"

tm DateOperations::getDateFromString(string inputDate)
{
    tm date;
    string simplePartOfDate = "";
    int numberOfDateParts = 1;

    inputDate = inputDate + "-";

    for (int unsigned i = 0; i < inputDate.length(); i++)
    {
        if (inputDate[i] != '-')
        {
            simplePartOfDate += inputDate[i];
        }
        else
        {
            switch(numberOfDateParts)
            {
            case 1:
                date.tm_year = AuxiliaryMethods::convertStringToInt(simplePartOfDate);
                break;
            case 2:
                date.tm_mon = AuxiliaryMethods::convertStringToInt(simplePartOfDate);
                break;
            case 3:
                date.tm_mday = AuxiliaryMethods::convertStringToInt(simplePartOfDate);
                break;
            }
            simplePartOfDate = "";
            numberOfDateParts++;
        }
    }
    return date;
}


string DateOperations::convertDateToString(tm inputDate)
{
    string stringDate = "";
    string year = "";
    string month = "";
    string day = "";

    year = AuxiliaryMethods::convertIntToString(inputDate.tm_year);
    month = AuxiliaryMethods::convertIntToString(inputDate.tm_mon);
    day = AuxiliaryMethods::convertIntToString(inputDate.tm_mday);

    stringDate += year + "-" + month + "-" + day;

    return stringDate;
}


bool DateOperations::isDateCorrect(tm date)
{
    string stringYear = "";
    string stringMonth = "";
    string stringDay = "";

    if (date.tm_year < 2000)
        return false;
    else if (date.tm_mon < 0 || date.tm_mon > 12)
        return false;
    else if (date.tm_mday < 0 || date.tm_mday > getDaysInMonthNumber(date.tm_mon, date.tm_year))
        return false;
    else
        return true;
}


bool DateOperations::isYearLeap(int year)
{
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
        return true;
}


int DateOperations::getDaysInMonthNumber(int month, int year)
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


bool DateOperations::isDateAEarlierThanDateB(tm dateA, tm dateB)
{
    if(dateA.tm_year < dateB.tm_year)
            return true;
        else if(dateA.tm_mon < dateB.tm_mon)
            return true;
        else if(dateA.tm_mday < dateB.tm_mday)
            return true;
        else
            return false;
}


tm DateOperations::enterTheDate()
{

    tm outputDate;
    string inputDate = "";

    while(true)
    {
        cout<<endl<<endl<<"Enter the date (YYYY-MM-DD): "<<endl;
        cin.sync();
        inputDate = AuxiliaryMethods::getLine();
        outputDate = getDateFromString(inputDate);
        if(isDateCorrect(outputDate))
            break;
        else
        {
            cout<<endl<<"Date is incorrect!"<<endl;
            system("pause");
        }
    }
    return outputDate;
}


tm DateOperations::getTodayDate()
{
    time_t now = time(0);

    tm *indicateDate = localtime(&now);
    tm date;
    date.tm_year = 1900 + indicateDate->tm_year;
    date.tm_mon = 1 + indicateDate->tm_mon;
    date.tm_mday = indicateDate->tm_mday;

    return date;
}
