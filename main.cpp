#include <iostream>
#include "UserManager.h"

using namespace std;


int main()
{
    UserManager userManager("users.xml");
    userManager.listAllUsers();

    return 0;
}
