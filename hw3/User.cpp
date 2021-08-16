#include <iostream>
#include "User.h"

using namespace std;

//constructor
User::User(const string tempname,int mark)
    :ID(mark), name(tempname), usr_account(ID)
{
    cout<<"User constructed"<<endl;
}
User::~User()
{
    cout<<"User destructed"<<endl;
}

string User::getUsername(void)
{
    return name;
}
Account *User::getAccount(void)
{
    usr_account.setName(name);
    return &usr_account;
}
int User::getID(void)
{
    return ID;
}

