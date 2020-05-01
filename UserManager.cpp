#include "UserManager.h"

UserManager::UserManager()
{

}


int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}


vector<User> UserManager::getUsersVector()
{
    return users;
}
