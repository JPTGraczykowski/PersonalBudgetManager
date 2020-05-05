#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "AuxiliaryMethods.h"

#include<iostream>


using namespace std;

class BudgetManager
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;

public:
    BudgetManager(string userFileName) : userManager(userFileName)
    {
        incomeManager = NULL;
    };
    ~BudgetManager()
    {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    };

    void registerUser();
    void logInUser();
    void logOutUser();
    void changeLoggedInUserPassword();
    bool isUserLoggedIn();

    void addIncome();
    void addExpense();

    char chooseFromMainMenu();
    char chooseFromUserMenu();
};

#endif // BUDGETMANAGER_H
