#include<iostream>
#ifndef Transaction_H
#define Transaction_H
using namespace std;

class Transaction
{
private:
    string type[100],NameOfB,name;
    int value[], n;
public:
    Transaction(string type);
    ~Transaction();
    void setName(string names);
    void record(int x,string tmptype,string tempname);
    void print();
};
#endif
