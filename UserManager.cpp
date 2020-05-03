#include "UserManager.h"

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}


vector<User> UserManager::getUsersVector()
{
    return users;
}


void UserManager::registerUser()
{
system("cls");
    cout<<" >>> REGISTRATION <<< "<<endl<<endl;
    User user = provideUserDetails();

    users.push_back(user);
    userFile.addUserToFile(user);

    cout << endl << "User is registered" << endl << endl;
    system("pause");
}


User UserManager::provideUserDetails()
{
    string login, password, name, surname;

    User user;

    user.setId(getNewUserId());

    do
    {
        cout << "Enter login: ";
        cin>>login;
        user.setLogin(login);
    }
    while (loginExists(user.getLogin()));

    cout << "Enter password: ";
    cin>>password;
    user.setPassword(password);

    cout << "Enter your name: ";
    cin>>name;
    user.setName(name);

    cout << "Enter your surname: ";
    cin>>surname;
    user.setSurname(surname);

    return user;
}


int UserManager::getNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}


bool UserManager::loginExists(string login)
{
    for (unsigned int i=0; i<users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout<<endl<<"This login already exists" << endl;
            return true;
        }
    }
    return false;
}


void UserManager::logInUser()
{
    system("cls");
    cout<<" >>> LOG IN <<< "<<endl<<endl;
    User user;
    string login = "", password = "";

    cout << endl << "Enter the login: ";
    login = AuxiliaryMethods::getLine();

    for(unsigned int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int mistake = 3; mistake > 0; mistake--)
            {
                cout << "Enter the password. Mistakes left: "<< mistake << ": ";
                password = AuxiliaryMethods::getLine();
                if (users[i].getPassword() == password)
                {
                    cout << endl << "User is logged in." << endl << endl;
                    system("pause");
                    loggedInUserId = users[i].getId();
                    return;

                }
            }
            cout << "You have made mistake 3 times." << endl;
            system("pause");
            return;
        }
    }
    cout << "There is no such login." << endl << endl;
    system("pause");
    return;
}


void UserManager::logOutUser()
{
    loggedInUserId = 0;
}


void UserManager::changeLoggedInUserPassword()
{
    system("cls");
    cout<<" >>> CHANGE PASSWORD <<<"<<endl<<endl;
    string newPassword = "";
    cout << "Enter a new password: ";
    newPassword = AuxiliaryMethods::getLine();

    for (unsigned int i=0; i<users.size(); i++)
    {
        if (users[i].getId() == loggedInUserId)
        {
            users[i].setPassword(newPassword);
            cout << "Password has benn changed." << endl << endl;
            system("pause");
        }
    }
    //userFile.addAllUsersToFile(users);
}


bool UserManager::isUserLoggedIn()
{
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}


void UserManager::listAllUsers()
{
    for(unsigned int i = 0; i<users.size(); i++)
    {
        cout<<users[i].getLogin()<<endl;
    }
    system("pause");
}
