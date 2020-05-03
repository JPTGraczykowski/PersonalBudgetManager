#include "UserFile.h"


User UserFile::getUserDetails(CMarkup &file)
{
    User user;

    file.IntoElem();
    file.FindElem("userId");
    user.setId(AuxiliaryMethods::convertStringToInt(file.GetData()));
    file.FindElem("login");
    user.setLogin(file.GetData());
    file.FindElem("password");
    user.setPassword(file.GetData());
    file.FindElem("name");
    user.setName(file.GetData());
    file.FindElem("surname");
    user.setSurname(file.GetData());
    file.OutOfElem();

    return user;
}


vector<User> UserFile::getUsersFromFile()
{
    User user;
    vector<User> users;
    CMarkup file;

    bool fileExists = file.Load(getFileName().c_str());
    file.FindElem();
    file.IntoElem();

    if(fileExists)
    {
        while(file.FindElem("user"))
        {
            user = getUserDetails(file);
            users.push_back(user);
        }
    }

    //delete file;
    return users;
}



