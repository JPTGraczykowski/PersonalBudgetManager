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


float AuxiliaryMethods::getCurrnecyFloat()
{
    float input = 0;
    cin.sync();
    cin>>input;

    return round(input*100)/100;
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


