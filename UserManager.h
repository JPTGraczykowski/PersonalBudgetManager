#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "AuxiliaryMethods.h"
#include "UserFile.h"

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector<User> users;
    UserFile userFile;

    User provideUserDetails();
    bool loginExists(string login);
    int getNewUserId();

public:
    UserManager(string userFileName) : userFile(userFileName)
    {
        loggedInUserId = 0;
        users = userFile.getUsersFromFile();
    };
    int getLoggedInUserId();
    vector<User> getUsersVector();
    void logInUser();
    void logOutUser();
    void registerUser();
    void changeLoggedInUserPassword();
    bool isUserLoggedIn();

};
#endif // USERMANAGER_H
