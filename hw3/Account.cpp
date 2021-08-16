#include<iostream>
#include "Account.h"

using namespace std;

//constructor
Account::Account(int Id):trans("NULL")
{
    ID = Id;
    cout<<"Account constructed"<<endl;
    trans.record(0,"Create ", "");
    amount=0;
}

Account::~Account(){
    cout << "Account destructed" << endl;
}
Transaction &Account::getTrans()
{
    trans.setName(name);
    return trans;
}

bool Account::withdraw(int x)
{
    if(amount-x<0||x<0)
    {
        cout<<"Illegal withdraw"<<endl;
        return 0;
    }
    cout<<"Withdraw "<<x<<endl;
    trans.record(x,"Withdraw ","");
    amount-=x;
    return 1;
}
bool Account::deposit(int x)
{
    if(x<0)
    {
        cout<<"Illegal deposit"<<endl;
        return 0;
    }
    cout<<"Deposit "<<x<<endl;
    trans.record(x,"Deposit ","");
    amount+=x;
    deductAmount=x;
    return 1;
}
int Account::getAmount()
{
    return amount;
}

bool Account::transferMoney(Account* AccountOfB,int amountToTransfer)
{
    if(0>amount-amountToTransfer){
        cout << "Illegal transfer" << endl;
        return 0;
    }
    cout<<"Transfer succeed"<<endl;
    trans.record(amountToTransfer,"Transfer ",AccountOfB->getName());
    AccountOfB->amount+=amountToTransfer;
    amount-=amountToTransfer;
    return 1;
}

void Account::setName(string s){
    name = s;
}
string Account::getName()
{
    return name;
}
