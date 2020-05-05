#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include "UserManager.h"
#include "IncomeManager.h"
#include "AuxiliaryMethods.h"

#include<iostream>


using namespace std;

class BudgetManager
{
    UserManager userManager;
    IncomeManager *incomeManager;

public:
    BudgetManager(string userFileName) : userManager(userFileName)
    {
        incomeManager = NULL;
    };
    ~BudgetManager()
    {
        delete incomeManager;
        incomeManager = NULL;
    };

    void registerUser();
    void logInUser();
    void logOutUser();
    void changeLoggedInUserPassword();
    bool isUserLoggedIn();

    void addIncome();

    char chooseFromMainMenu();
    char chooseFromUserMenu();
};

#endif // BUDGETMANAGER_H
