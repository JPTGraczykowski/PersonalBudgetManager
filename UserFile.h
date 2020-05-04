#ifndef USERFILE_H
#define USERFILE_H

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "DataFile.h"

#include <iostream>
#include <vector>

using namespace std;

class UserFile : public DataFile
{
    User getUserDetails(CMarkup &file);
public:
    UserFile(string userFileName) : DataFile(userFileName){};
    vector<User> getUsersFromFile();
    void addUserToFile(User user);
    void addAllUsersToFile(vector<User> users);
};

#endif // USERFILE_H
