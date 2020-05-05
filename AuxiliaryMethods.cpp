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


float AuxiliaryMethods::getCurrnecyFloat()
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


