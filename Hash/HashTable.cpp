#include "stdafx.h"
#include "HashTable.h"
#include<iostream>
#include<assert.h>
#include<iomanip>
using namespace std;
HashTable::HashTable(int d, int k,int sz)
{
	divisor = d;
	TableSize = sz;
	key = k;
	ht = new ChainNode*[sz];
	assert(ht != NULL);
	//cout << "\nBuild success!\n";
	for (int i = 0; i < TableSize; i++)
		ht[i] = new ChainNode;
}





bool HashTable::insert(const int&d)
{
	int j = d % divisor;
	//cout << j << endl;
	//ht[j]->data = 0;
	//cout << ht[j];
	ChainNode* current = ht[j];
	//if (ht[j]->link==nullptr)
	//	cout <<j<<" Null\n";
	while (current->link != nullptr)
	{
		current = current->link;
	}
	ChainNode* newNode = new ChainNode(d);
	current->link = newNode;

	//cout << "Insert success!\n";
	return true;
}

int HashTable::search(const int k)
{
	int count = 1;
	int j = k % divisor;
	//cout << j << endl;
	ChainNode* p = ht[j]->link;
	//if (p == nullptr)
		//cout << "NULL\n";
	while (p!= nullptr)
	{
		if (p->data != k)
		{
			count++;
			//cout << p->data << endl;
			p = p->link;
		}
		else
			break;

	}
	//cout << count<<endl;
	return count;
}

float HashTable::ASL(int*& a)
{
	float sa;
	int numerator=0;
	for (int i = 0; i < key; i++)
		numerator += search(a[i]);
	sa = float(numerator) / float(key);
	return sa;
}

void HashTable::create(int*&a)
{
	for (int i = 0; i < key; i++)
	{
		//cout << a[i] <<endl;
		//cout << "Ready to insert\n";
		insert(a[i]);
	}
}

float HashTable::ASLun()
{
	float ua;
	int numerator = 0;
	for (int i = 0; i < divisor; i++)
	{
		//cout << unsearch(i)<<endl;
		numerator += unsearch(i);
	}
	//cout << numerator <<endl;
	ua = float(numerator) / float(divisor);
	return ua;
}

int HashTable::unsearch(int pos)
{
	int count = 1;
	ChainNode*p = ht[pos];
	//if (pos == 4)
	//	cout << ht[pos]->data<<endl;
	while (p->link!= nullptr)
	{
		count++;
		//cout << p->link->data << endl;
		p = p->link;
	}
	//cout << count<<endl;
	return count;
}

void HashTable::output(int*&a)
{
	cout << "�ؼ���: ";
	for (int i = 0; i < key; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n\n--��ǰHash�������--\n"
		<<setw(4)<<"����ȡ�෨�ĳ����� "<<divisor
		<<setw(4)<<"  Ͱ�ĸ����� "<<TableSize
		<<setw(4)<<"  �ؼ��������"<<key<<endl
		<<setw(4)<<"Ͱ��"<<setw(8)<<"�ؼ���\n";
	for (int i = 0; i < TableSize; i++)
	{
		cout << setw(4) << i<<"    ";
		ChainNode*p = ht[i];
		while (p->link != nullptr)
		{
			cout << setw(4) << p->link->data;
			p = p->link;
		}
		cout << endl;
	}
	cout << "ͨ�������㷨���ԱȽϴ���������ƽ����������ASL.\n"
		<<setw(10)<<"Sa = "<<ASL(a)
		<<" ,Ua = "<<ASLun();
	cout << "\n\n����alpha, ����ƽ����������ASL.\n";
	float Sa=0;
	float Ua = 0;
	alpha(Sa, Ua);

	cout << "n = " << key << ", m = " << divisor << "  Sa = "
		<< Sa << " , Ua = " << Ua << endl;

}

void HashTable::alpha(float &Sn, float &Un)
{
	int count = 0;
	for (int i = 0; i < TableSize; i++)
	{
		if (ht[i]->link != nullptr)
			count++;
	}
	float a = float(count) / float(TableSize);
	Sn = 0.5*(1 +1 / (1 - a));
	Un = 0.5*(1+1/((1-a)*(1-a)));
}