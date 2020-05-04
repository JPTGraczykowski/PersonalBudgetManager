#include <iostream>
#include "UserManager.h"

using namespace std;


int main()
{
    UserManager userManager("users.xml");
    userManager.listAllUsers();
    userManager.logInUser();
    userManager.changeLoggedInUserPassword();


    return 0;
}
