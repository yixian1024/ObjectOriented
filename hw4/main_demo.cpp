#include<iostream>
#include "Bag.h"
using namespace std;

int main(void)
{
		Bag<string> a;						//�LBag constructor
		cout << a.empty() << endl; 			//�O�_����//�L1
		cout << a.ended() << endl;			//�Y����٥����V���M�F��h�^��true//�L1
		a.next();							//�٥��N�����l�ƴN�I�snext()//�LPlease initializes
		a.start();							//��l�Ƥ���A����䤤�@�Ӫ��~�W//�Y�]�]���šA�LPlease input item�{�������a��
		a.insert("a1");     				//"a1"��J�]�]
		a.insert("a2");						//"a2"��J�]�]
											//���X�I�]�ɥi�H�O���N���ǡA�i�H�O��J���ǡA�]�i�H���O�C
											//���O�n�@��next()�쩳�A�I�]�o�Ҧ����س����Q���X�C
		a.start();							//��l�Ƥ���A����䤤�@�Ӫ��~�W
		cout << a.currentValue() << endl;	//�La1��a2
		a.next();							//�������U�@�Ӫ��~
		cout << a.currentValue() << endl;	//�p�G�e���O�La1�A�o�̴N�ӦLa2;�p�G�e���O�La2�A�o�̴N�ӦLa1;
		cout << a.currentCount() << endl;	//����ĴX�Ӫ��~//�L2
		a.next();							//�Y�w�g���쩳//�������NULL

		Bag<string> a_copy = a;				//Copy constructor:�ƻsa//�LBag copy constructor
		cout << a_copy.size() << endl;		//�L2
		a.insert("a3");
		cout << a_copy.size() << endl;		//�٬O�L2

		Bag<string> a_assignment;
		a_assignment.insert("assignment1");
		a_assignment = a;					//��a������a_assignment�Aa_assignment��Ӫ��¦��Ȥ��Ӧs�b/Bag assignment operator/�L
		cout << a_assignment.size() << endl;//�L3
		a_assignment.start();
		cout << a_assignment.currentValue() << endl;//�La1
		a_assignment.next();
		cout << a_assignment.currentValue() << endl;//�La2
		a_assignment.next();
		cout << a_assignment.currentValue() << endl;//�La3

		Bag<int> b;							//�LBag constructor
		b.insert(10);
		b.insert(20);
		b.insert(20);
		b.insert(20);
		b.insert(30);
		b.insert(10);
		cout << b.size() << endl;			//�]�]�����~�`��//�L6
		cout << b.uniqueSize() << endl;		//�]�]���۲����~��//�L3
		cout << b.erase(10) << endl;		//�R��(10)�A�^�ǬO�ĴX�Ӫ��~//�L1//
		cout << b.eraseAll(20) << endl;		//�R���Ҧ�(20)�A�^�ǧR�����`��//�L3
		cout << b.contains(20) << endl;		//�]�]���O�_�]�t(20)//�L0
		cout << b.count(10) << endl;		//�]�]��(10)���ƶq//�L1

        Bag<string> c1, c2, c_result;
		c1.insert("duck");
		c1.insert("duck");
		c1.insert("goose");
		c1.insert("chicken");
		c1.insert("chicken");
																																																 c2.insert("duck");
		c2.insert("goose");
		c2.insert("goose");
		c2.insert("chicken");
		c2.insert("chicken");
		c_result=combine(c1, c2);			//c_result���n��c1�Pc2���Ҧ����~�A�b�o�̴N�S���W�w���ǡA�u�n���~�ƶq���T�Y�i
											//c_result���n��3��"duck", 3��"goose", 4��"chicken"
		c_result=subtract(c1, c2);			//�b�o�̴N�S���W�w���ǡA�u�n���~�ƶq���T�Y�i
                                            //c_result���n��1��"duck", 0��"goose", 0��"chicken"
		return 0;
}
