#include <iostream>
#include "UserManager.h"

using namespace std;


int main()
{
    UserManager userManager("users.xml");
    userManager.listAllUsers();
    userManager.registerUser();
    userManager.registerUser();

    return 0;
}
