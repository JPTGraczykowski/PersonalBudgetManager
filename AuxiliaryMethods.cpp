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


string AuxiliaryMethods::changeComaToDot(string number)
{
    for (unsigned int i =0; i<number.size(); i++)
    {
        if(number[i] == ',')
            number[i] = '.';
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

        input = changeComaToDot(input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout<<"It's not a number."<<endl;
    }

    float numberToReturn = round(number*100)/100;

    return numberToReturn;
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





string AuxiliaryMethods::changeFirstLetterToUpper(string inputString)
{
    if (!inputString.empty())
    {
        transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        inputString[0] = toupper(inputString[0]);
    }
    return inputString;
}

