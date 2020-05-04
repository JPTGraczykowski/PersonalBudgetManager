#include "BudgetManager.h"


void BudgetManager::registerUser()
{
    userManager.registerUser();
}


void BudgetManager::logInUser()
{
    userManager.logInUser();
}


void BudgetManager::logOutUser()
{
    userManager.logOutUser();
}


void BudgetManager::changeLoggedInUserPassword()
{
    userManager.changeLoggedInUserPassword();
}


bool BudgetManager::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}


char BudgetManager::chooseFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    $$$ MAIN MENU $$$" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Quit" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter the number: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}


char BudgetManager::chooseFromUserMenu()
{
    char choice;

    system("cls");
    cout << "    $$$ WELCOME $$$" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter the number: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}