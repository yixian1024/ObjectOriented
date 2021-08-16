#include<iostream>
#include<string>
#include<map>
#include "Bag.h"

using namespace std;

template <typename T>
void combine (Bag<T>&, Bag<T>&, Bag<T>&);
template <typename T>
void subtract (Bag<T>&, Bag<T>&, Bag<T>&);
template<typename T>
void deleteAll (Bag<T>& b); 


int main(void)
{
	//Bag a
	cout<<"---------Bag A-----------"<<endl;
	cout<<"Welcome"<<endl;
	Bag<string> a;						
	cout <<"Empty: "<< a.empty() << endl; 		
	cout <<"Ended: "<< a.ended() << endl;			
	a.next();					
	a.start();				
	a.insert("a1");     		
	a.insert("a2");				
	a.start();
	cout<<"Current: "<<a.currentValue()<<endl;
	a.next();
	cout<<"Current: "<<a.currentValue()<<endl;
	cout<<"Current: "<<a.currentCount()<<endl;
	a.next();

	//copy
	cout<<"---------copy-----------"<<endl;
	Bag<string> a_copy=a;
	cout<<a_copy.size()<<endl;
	a.insert("a3");
	cout<<a_copy.size()<<endl;

	//assignment
	/*Bag<string> a_assignment;
	a_assignment.insert("assignment1");
	a_assignment = a;									
	cout << a_assignment.size() << endl;//a3
	a_assignment.start();
	cout << a_assignment.currentValue() << endl;//a1
	a_assignment.next();
	cout << a_assignment.currentValue() << endl;//a2
	a_assignment.next();
	cout << a_assignment.currentValue() << endl;//a3*/

	//Bag b
	cout<<"---------Bag B-----------"<<endl;
	Bag<int> b;
	b.insert(10);
	b.insert(20);
	b.insert(20);
	b.insert(20);
	b.insert(30);
	b.insert(10);
	cout<<b.size()<<endl;
	cout<<b.uniqueSize()<<endl;
	cout<<b.erase(10)<<endl;
	cout<<b.eraseAll(20)<<endl;
	cout<<b.contains(20)<<endl;
	cout<<b.count(10)<<endl;

	//Bag c1,c2,c_result
	cout<<"---------Bag C-----------"<<endl;
	Bag<string> c1,c2,c_result;
	cout<<"c1:"<<endl;
	c1.insert("duck");
	c1.insert("duck");
	c1.insert("goose");
	c1.insert("chicken");
	c1.insert("chicken");
	
	cout<<"c2:"<<endl;
	c2.insert("goose");
	c2.insert("goose");
	c2.insert("chicken");
	c2.insert("chicken");


	cout<<"---------combine-----------"<<endl;
	combine(c1, c2, c_result);
	cerr << c_result.size() << endl;
	deleteAll(c_result);
	cout<<"---------substract-----------"<<endl;
	subtract(c1, c2, c_result);
	cerr << c_result.size() << endl;

	return 0;
}

// ##combine
template <typename T>
void combine (Bag<T>& b1, Bag<T>& b2, Bag<T>& b3) {
	map<T, int> mp;
	for (b1.start(); !b1.ended(); b1.next()) {
		mp[b1.currentValue()] ++;
	}

	for (b2.start(); !b2.ended(); b2.next()) {
		mp[b2.currentValue()] ++;
	}

	deleteAll (b3);

	for (auto it=mp.begin(); it!=mp.end(); ++it) {
		for (int i=0; i<it->second; i++) {
			b3.insert (it -> first);
		}
	}
}

// ##subtract
template <typename T>
void subtract (Bag<T>& b1, Bag<T>& b2, Bag<T>& b3) {
	map<T, int> mp;
	for (b1.start(); !b1.ended(); b1.next()) {
		mp[b1.currentValue()] ++;
	}

	for (b2.start(); !b2.ended(); b2.next()) {
		mp[b2.currentValue()] --;
	}

	deleteAll (b3);

	for (auto it=mp.begin(); it!=mp.end(); ++it) {
		for (int i=0; i<it->second; i++) {
			b3.insert (it -> first);
		}
	}
}

// ##deleteAll
template <typename T>
void deleteAll (Bag<T>& b) {
	if(b.ended())return;
	for (b.start(); !b.ended(); b.next()) {
		T val = b.currentValue();
		b.erase (val);
	}
}
