#include <iostream>
#include "BudgetManager.h"

using namespace std;


int main()
{
    char choice;
    BudgetManager budgetManager("users.xml", "incomes.xml", "expenses.xml");

    while(true)
    {
        if (!budgetManager.isUserLoggedIn())
        {
            choice = budgetManager.chooseFromMainMenu();

            switch (choice)
            {
            case '1':
                budgetManager.registerUser();
                break;
            case '2':
                budgetManager.logInUser();
                break;
            case '9':
                system("cls");
                cout<<endl<<"GOOD BYE"<<endl;
                exit(0);
                break;
            default:
                cout << endl << "Wrong number has been entered." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = budgetManager.chooseFromUserMenu();

            switch (choice)
            {
            case '1':
                budgetManager.addIncome();
                break;
            case '2':
                budgetManager.addExpense();
                break;
            case '3':
                budgetManager.showTheCurrentMonthBalance();
                break;
            case '4':
                budgetManager.showThePreviousMonthBalance();
                break;
            case '5':
                budgetManager.showOtherPeriodOfTimeBalance();
                break;
            case '6':
                budgetManager.changeLoggedInUserPassword();
                break;
            case '9':
                budgetManager.logOutUser();
                break;
            default:
                cout << endl << "Wrong number has been entered." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
