#include "BudgetManager.h"


void BudgetManager::registerUser()
{
    userManager.registerUser();
}


void BudgetManager::logInUser()
{
    userManager.logInUser();
    if(isUserLoggedIn())
    {
        incomeManager = new IncomeManager(userManager.getLoggedInUserId(), INCOME_FILE_NAME);
        expenseManager = new ExpenseManager(userManager.getLoggedInUserId(), EXPENSE_FILE_NAME);
    }
}


void BudgetManager::logOutUser()
{
    userManager.logOutUser();
    delete incomeManager;
    incomeManager = NULL;
    delete expenseManager;
    expenseManager = NULL;
}


void BudgetManager::changeLoggedInUserPassword()
{
    userManager.changeLoggedInUserPassword();
}


bool BudgetManager::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}


void BudgetManager::addIncome()
{
    if(isUserLoggedIn())
    {
        incomeManager -> addIncome();
    }
}


void BudgetManager::addExpense()
{
    if(isUserLoggedIn())
    {
        expenseManager -> addExpense();
    }
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
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "6. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter the number: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}
