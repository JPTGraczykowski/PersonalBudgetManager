#include "AuxiliaryMethods.h"


string AuxiliaryMethods::getLine()
{
    string inString = "";
    cin.sync();
    getline(cin, inString);
    return inString;
}


char AuxiliaryMethods::getChar()
{
    string input = "";
    char character  = {0};

    cin.sync();
    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "Enter a single character!" << endl;
    }
    return character;
}


int AuxiliaryMethods::getInt()
{
    string input = "";
    int number = 0;

    while(true)
    {
        cin.sync();
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout<<"It's not a number."<<endl;
    }
    return number;
}


float AuxiliaryMethods::getCurrencyFloat()
{
    string input = "";
    float number = 0;

    while(true)
    {
        cin.sync();
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout<<"It's not a number."<<endl;
    }

    return round(number*100)/100;
}


int  AuxiliaryMethods::convertStringToInt(string stringToChange)
{
    int intToReturn;
    istringstream iss(stringToChange);
    iss >> intToReturn;

    return intToReturn;
}


string AuxiliaryMethods::convertIntToString(int intToChange)
{
    ostringstream ss;
    ss << intToChange;
    string str = ss.str();
    return str;
}


float AuxiliaryMethods::convertStringToFloat(string stringToChange)
{
    float floatToReturn = 0;

    stringstream myStream(stringToChange);
    myStream >> floatToReturn;

    return floatToReturn;
}


string AuxiliaryMethods::convertFloatToString(float floatToChange)
{
    string stringToReturn = "";
    ostringstream ss;
    ss << floatToChange;
    string str = ss.str();
    return str;
}


tm AuxiliaryMethods::getDateFromString(string inputDate)
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
                date.tm_year = convertStringToInt(simplePartOfDate);
                break;
            case 2:
                date.tm_mon = convertStringToInt(simplePartOfDate);
                break;
            case 3:
                date.tm_mday = convertStringToInt(simplePartOfDate);
                break;
            }
            simplePartOfDate = "";
            numberOfDateParts++;
        }
    }
    return date;
}


string AuxiliaryMethods::convertDateToString(tm inputDate)
{
    string stringDate = "";
    string year = "";
    string month = "";
    string day = "";

    year = convertIntToString(inputDate.tm_year);
    month = convertIntToString(inputDate.tm_mon);
    day = convertIntToString(inputDate.tm_mday);

    stringDate += year + "-" + month + "-" + day;

    return stringDate;
}



