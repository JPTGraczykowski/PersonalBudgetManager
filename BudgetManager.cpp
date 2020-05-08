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


void BudgetManager::showTheCurrentMonthBalance()
{
    time_t now = time(0);

    tm *date = localtime(&now);
    int month = 1 + date->tm_mon;

    system("cls");
    cout << "$$$ THE CURRENT MONTH BALANCE $$$" << endl << endl;

    cout << "$$$ INCOMES $$$" << endl << endl;

    incomeManager -> showIncomesFromTheMonth(month);

    cout << endl << "$$$ EXPENSES $$$" << endl << endl;

    expenseManager -> showExpensesFromTheMonth(month);

    showTheBalanceSummary();

    system("pause");
}


void BudgetManager::showThePreviousMonthBalance()
{
    time_t now = time(0);

    tm *date = localtime(&now);
    int previousMonth = date->tm_mon;
    if(previousMonth == 0)
        previousMonth = 12;

    system("cls");
    cout << "$$$ THE PREVIOUS MONTH BALANCE $$$" << endl << endl;

    cout << "$$$ INCOMES $$$" << endl << endl;

    incomeManager -> showIncomesFromTheMonth(previousMonth);

    cout << endl << "$$$ EXPENSES $$$" << endl << endl;

    expenseManager -> showExpensesFromTheMonth(previousMonth);

    showTheBalanceSummary();

    system("pause");
}


void BudgetManager::showTheOtherPeriodOfTimeBalance()
{
    tm startDate, stopDate;
    string inputStartDate = "";
    string inputStopDate = "";
    system("cls");
    cout<<"Set the period of time."<<endl;

    while(true)
    {
        cout<<endl<<endl<<"Enter the start date (YYYY-MM-DD): "<<endl;
        inputStartDate = AuxiliaryMethods::getLine();
        startDate = AuxiliaryMethods::getDateFromString(inputStartDate);

        if(AuxiliaryMethods::isDateCorrect(startDate))
            break;
        else
        {
            cout<<endl<<"Date is incorrect!"<<endl;
            system("pause");
        }
    }

    while(true)
    {
        cout<<endl<<endl<<"Enter the stop date (YYYY-MM-DD): "<<endl;
        inputStopDate = AuxiliaryMethods::getLine();
        stopDate = AuxiliaryMethods::getDateFromString(inputStopDate);

        if(AuxiliaryMethods::isDateCorrect(stopDate))
            break;
        else
        {
            cout<<endl<<"Date is incorrect!"<<endl;
            system("pause");
        }
    }

    system("cls");
    cout << "$$$ " << inputStartDate << " : " << inputStopDate << " BALANCE $$$" << endl << endl;

    cout << "$$$ INCOMES $$$" << endl << endl;

    incomeManager -> showIncomesFromTheOtherPeriodOfTime(startDate, stopDate);

    cout << endl << "$$$ EXPENSES $$$" << endl << endl;

    expenseManager -> showExpensesFromTheOtherPeriodOfTime(startDate, stopDate);

    showTheBalanceSummary();

    system("pause");
}



void BudgetManager::showTheBalanceSummary()
{
    float incomesSum = incomeManager -> getSumOfTheTransaction();
    float expenseSum = expenseManager -> getSumOfTheTransaction();
    float balance = incomesSum - expenseSum;

    cout << endl << endl << "______________________________" << endl << endl;
    cout << "SUM OF INCOMES: " << incomesSum << endl;
    cout << "SUM OF EXPENSES: " << expenseSum << endl;
    cout << "BALANCE: " << balance << endl << endl;
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
    cout << "3. Show the current month balance" << endl;
    cout << "4. Show the previous month balance" << endl;
    cout << "5. Show the other period of time balance" << endl;
    cout << "6. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter the number: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}
