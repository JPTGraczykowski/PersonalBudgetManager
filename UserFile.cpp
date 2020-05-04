#include "UserFile.h"


User UserFile::getUserDetails(CMarkup &file)
{
    User user;

    file.IntoElem();
    file.FindElem("USER_ID");
    user.setId(AuxiliaryMethods::convertStringToInt(file.GetData()));
    file.FindElem("LOGIN");
    user.setLogin(file.GetData());
    file.FindElem("PASSWORD");
    user.setPassword(file.GetData());
    file.FindElem("NAME");
    user.setName(file.GetData());
    file.FindElem("SURNAME");
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

    if(fileExists)
    {
        file.FindElem(); //go to USERS
        file.IntoElem(); //go to USERS
        while(file.FindElem("USER"))
        {
            user = getUserDetails(file);
            users.push_back(user);
        }
    }

    return users;
}


void UserFile::addUserToFile(User user)
{
    CMarkup file;

    bool fileExists = file.Load(getFileName().c_str());

    if(fileExists)
    {
        file.FindElem(); //go to USERS
        file.IntoElem(); //go to USERS

        file.AddElem("USER");
        file.IntoElem();

        file.AddElem("USER_ID", user.getId());
        file.AddElem("LOGIN", user.getLogin());
        file.AddElem("PASSWORD", user.getPassword());
        file.AddElem("NAME", user.getName());
        file.AddElem("SURNAME", user.getSurname());

        file.Save(getFileName().c_str());
    }
}



