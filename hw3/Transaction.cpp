#include<iostream>
#include "Transaction.h"

using namespace std;

//constructor
Transaction::Transaction(string type)
{
    type="";
    n=0;
    cout<<"Transaction constructed"<<endl;
}
Transaction::~Transaction(){
    cout<<"Transaction destructed" << endl;
}
void Transaction::print(void)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(type[i]=="Create ")
            cout<<type[i]<<name<<endl;
        if(type[i]=="Deposit ")
            cout<<type[i]<<value[i]<<endl;
        if(type[i]=="Withdraw ")
            cout<<type[i]<<value[i]<<endl;
        if(type[i]=="Transfer ")
            cout<<name<<" transfer "<<value[i]<<" to "<<NameOfB<<endl;
    }

}

void Transaction::record(int x,string tmptype,string tempname)
{
    type[n]=tmptype;
    value[n]=x;
    n++;
    NameOfB=tempname;
}

void Transaction::setName(string names){
    name = names;
}
