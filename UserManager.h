#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"

#include <iostream>
#include <vector>

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector<User> users;

    User provideUserDetails();
    bool loginExists();

public:
    UserManager();
    int getLoggedInUserId();
    vector<User> getUsersVector();
    void logInUser();
    void logOutUser();
    void registerUser();
    void changeLoggedInUserPassword();
    bool isUserLoggedIn();



};
#endif // USERMANAGER_H
