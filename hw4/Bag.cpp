#ifndef BAG_CPP
#define BAG_CPP
#include<iostream>
#include<string>
#include "Bag.h"

using namespace std;

//constructor
		template <class T>
Bag<T>::Bag()
{
		nsize=0;
		unisize=0;
		n_obj=0;
		ptr = NULL;
		cout<<"Bag constructed"<<endl;
}
//destructor
		template<class T>
Bag<T>::~Bag()
{
		delete(ptr);
		delete(nex);
		delete(front);
		cout<<"Bag destructed"<<endl;
}

template<class T>
bool Bag<T>::empty() const
{
		if(nsize==0)
				return true;
		else
				return false;
}

template<class T>
int Bag<T>::size() const
{
	int x = 0;
	for (Listnode *p=front; p->right!=front; p=p->right, x++) {
//		cout << p -> word << endl;
	}
	return x;
}

template<class T>
int Bag<T>::uniqueSize() const
{   
		return unisize;
}

		template<class T>
bool Bag<T>::insert(const T& value)
{
		if(nsize==0)
		{
				front=new Listnode;
				pre=front;
				front->right=front;
				front->left=front;
		}
		nsize++;
		nex=new Listnode;
		nex->word=value;
		pre->right=nex;
		nex->right=front;
		nex->left=pre;
		pre=nex;
		cout<<"Insert "<<pre->word<<endl;
		ptr=NULL;
		Listnode *tmp;
		for(tmp=front->right;tmp!=pre;tmp=tmp->right)
				if(value==tmp->word)
						return true;
		unisize++;
		return true;

}

		template <class T>
int Bag<T>::erase(const T& value)
{
	if (nsize == 0) return 0;
		int n=1,mark=0,temp;
		Listnode *tmp;
		for(tmp=front->right;tmp!=front;tmp=tmp->right,n++)
				if(tmp->word==value)
				{
						if(mark==0)
						{
							cout<<"Delete "<<n<<" "<<value<<endl;
							temp=n;
							nsize--;
							(tmp->left)->right=tmp->right;
							(tmp->right)->left=tmp->left;
							ptr=NULL;
						}
						mark++;
				}  
		if(mark==1)
				unisize--;
		return temp;
}

template<class T>
int Bag<T>::eraseAll(const T& value)
{
		int n=0;
		Listnode *tmp;
		for(tmp=front->right;tmp!=front;tmp=tmp->right)
				if(tmp->word==value)
				{
						nsize--;
						n++;
						(tmp->left)->right=tmp->right;
						(tmp->right)->left=tmp->left;
				}
		if(n==0)
				return n;
		ptr=NULL;
		unisize--;
		cout<<"Erase all "<<value<<endl;
		return n;
}

template <class T>
bool Bag<T>::contains(const T& value) const
{
		Listnode *tmp;
		for(tmp=front->right;tmp!=front;tmp=tmp->right)
				if(tmp->word==value)
						return true;
		return false;
}

template <class T>
int Bag<T>::count(const T& value) const
{
		int n=0;
		Listnode *tmp;
		for(tmp=front->right;tmp!=front;tmp=tmp->right)
				if(tmp->word==value)
						n++;
		return n;
}

		template<class T>
void Bag<T>::start()
{
		if(nsize==0)
		{
				cerr<<"Please input item"<<endl;
				return;
		}
		ptr=front->right;
		n_obj=1;
		return;
}

template<class T>
void Bag<T>::next()
{
		if(nsize==0)
		{
				cerr<<"Please initialize"<<endl;
				return ;
		}
		ptr=ptr->right;
		n_obj++;
		if(n_obj>nsize)
				ptr=NULL;
		return;
}

template<class T>
bool Bag<T>::ended() const
{
		if(ptr == NULL)
				return true;
		return false;
}

template <class T>
const T& Bag<T>:: currentValue() const
{
		if(ptr==NULL)
		{
				cerr<<"Please initialize"<<endl;
				return NULL;
		}
		return ptr->word;
}

template<class T>
int Bag<T>::currentCount() const
{
		return n_obj;
}

template<class T>
Bag<T> &Bag<T>::operator=(const Bag<T>& tmp)
{
	for(start();!ended();next())
		erase(currentValue());
	for(tmp.start();!tmp.ended();tmp.next())
		insert(tmp.currentValue());
	return; 
}
#endif
