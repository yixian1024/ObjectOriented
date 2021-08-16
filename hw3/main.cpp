#include<iostream>
#include "Account.h"
#include "User.h"
#include "Transaction.h"
using namespace std;

int main(void)
{
    int mark;
    mark=0;
    User u1("John",mark++); // should print: New user john created
    User u2("Mary",mark++); // should print: New user mary created
    Account *a1 = u1.getAccount();
    cout<<endl<<endl;
    a1->deposit(400);
    cout << "Balance of "  << u1.getUsername() << " account is " << a1->getAmount()<< endl;// 400
    a1->withdraw(100);
    cout << "Balance of "  << u1.getUsername() << " account is " << a1->getAmount()<< endl; // 300
	cout<<u1.getUsername()<< " transfer to "<< u2.getUsername()<<endl;
    (u1.getAccount())->transferMoney(u2.getAccount(), 200);
    cout << "Balance of " << u1.getUsername() << " account is " << a1->getAmount()<< endl; // 100
    cout << "Balance of " << u2.getUsername() ;
    cout<< " account is " << (u2.getAccount())->getAmount() << endl; // 200
    cout<<endl<<"Transactions:"<<endl;
    (u1.getAccount())->getTrans().print();
    cout<<endl;
    return 0;

}
