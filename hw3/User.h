#include<iostream>
#include "Account.h"
#ifndef User_H
#define User_H

using namespace std;

class User
{
private:
    const string name;
    const int ID;
    Account usr_account;
public:
    int mark;
    User(const string tempname,int mark);
    ~User();
    string getUsername();
    Account *getAccount();
    int getID();
};
#endif // User_h
