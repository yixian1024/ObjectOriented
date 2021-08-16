#include<iostream>
#include "Transaction.h"
#ifndef Account_H
#define Account_H
using namespace std;

class Account
{
private:
    int ID,amount,deductAmount;
    string name;
    int amountToTransfer,AccountOfB;
    Transaction trans;
public:
    Account(int);
    ~Account();
    Transaction &getTrans();
    bool withdraw(int x);
    bool deposit(int x);
    bool transferMoney(Account *AccountOfB,int amountToTransfer);
    int getAmount();
    void setName(string);
    string getName();
};
#endif
