#ifndef BAG_H
#define BAG_H
using namespace std;

	
template <class T>
class Bag
{
	typedef struct Listnode
	{	
		T word;
		struct Listnode *right,*left;
	}Listnode;

	private:
	int nsize,unisize,n_obj;

	public:
	Listnode *ptr,*pre,*front,*nex;
	Bag& operator=(const Bag &tmp);
	Bag();
	~Bag();
	bool empty() const;
	int size() const;
	int uniqueSize() const;
	bool insert(const T& value);
	int erase(const T& value);
	int eraseAll(const T& value);
	bool contains(const T& value) const;
	int count(const T& value) const;
	void start();
	void next();
	bool ended() const;
	const T& currentValue() const;
	int currentCount() const;

};
#include "Bag.cpp"
#endif
