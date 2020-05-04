#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include "UserManager.h"
#include "AuxiliaryMethods.h"

#include<iostream>


using namespace std;

class BudgetManager
{
    UserManager userManager;

public:
    BudgetManager(string userFileName) : userManager(userFileName) {};
    //~BudgetManager();

    void registerUser();
    void logInUser();
    void logOutUser();
    void changeLoggedInUserPassword();
    bool isUserLoggedIn();

    char chooseFromMainMenu();
    char chooseFromUserMenu();
};

#endif // BUDGETMANAGER_H
