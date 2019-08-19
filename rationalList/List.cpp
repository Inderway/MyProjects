#include "stdafx.h"
#include "List.h"
#include<iostream>
using namespace std;




void List::makeEmpty()
{
	//cout << "\n调用makeEmpty()!" << endl;
	linkNode* q;
	while (first->link != rear)
	{

		q = first->link;
		first->link = q->link;
		delete q;
	}
	q = first->link;
	first->link = q->link;
	delete q;
	delete first;

}

void List::insert(int x)
{
	linkNode*newNode;
	newNode = new linkNode(x);

	if (newNode == nullptr)
	{
		cerr << "存储分配错误！" << endl;
		exit(1);
	}
	linkNode*currentNode;
	currentNode = first;

	while (currentNode->link!=nullptr)
	{
		//cout << "Circle\n";
		currentNode = currentNode->link;
	}
	currentNode->link = newNode;
	rear = newNode;

}

void List::construct(int n, int m)
{
	
	linkNode*newNode;
	int remain = n % m;
	int number;
	int mode = n % m;
	//double num=double(n)/double(m);
	cout << fixed;
	cout.precision(15);
	if (n / m > 0)
		insert(n / m);
	else
		insert(0);
	//cout << num<<endl;
	/*
	if (int(num )>= 100)//num为三位数
	{

		insert(int(num) / 100);
		num = num - int(num) / 100 * 100;//变为二位数
		//cout << num << endl;
		insert(int(num) / 10);
		num = num - int(num) / 10 * 10;//变为个位数
		insert(int(num));//插入最后一个整数位
		num = num - int(num);
	}
	else if (int(num) >= 10)//num为二位数
	{
		insert(int(num) / 10);		
		num = num - int(num) / 10 * 10;//变为个位数
		//cout << num << endl;
		insert(int(num));//插入最后一个整数位
		num = num - int(num);
	}
	else if (int(num) >= 1)
	{
		insert(int(num));//插入最后一个整数位
		num = num - int(num);
		//cout << num << endl;
	}
	else
	{
		//cout << num << endl;
		insert(0);
	}
	*/
	//cout << num << endl;
	if (remain != 0)//当不整除时
	{
		int denominator = m / gcd(n, m);//分数化简后的分母
		int n2 = 0;
		int n5 = 0;//分母中质因子2和5的个数
		int tmp = denominator;
		
		while (tmp % 2 == 0)
		{
			n2++;
			tmp = tmp / 2;
			
		}
		tmp = denominator;
		while (tmp % 5 == 0)
		{
			n5++;
			tmp = tmp / 5;
		}
		int mx = max(n2, n5);//一开始不在循环节中的个数
		tmp = mx;
		number = mode * 10 / m;
		while (tmp--)
		{
			
			insert(number);
			mode=mode*10%m;
			
		}
		if (number != 0)//为循环小数
		{

			for (int i = 0; i < mx; i++)
			{
				remain = remain * 10 % m;
			}
			int length = 1;//循环节长度


			tmp = remain;
			remain = remain * 10 % m;
			while (remain != tmp)
			{
				length++;
				remain = remain * 10 % m;
			}
			tmp = length;
			number = mode * 10 / m;
			insert(number);
			mode = mode * 10 % m;
			number = mode * 10 / m;
			linkNode*beginNode = rear;//循环节开头
			tmp--;
			while (tmp--)
			{
				insert(number);
				mode = mode * 10 % m;
				number = mode * 10 / m;
			}
			rear->link = beginNode;
			//cout << rear->link->data<<endl;
		}
	}
}

int List::gcd(int n, int m)
{
	if (m==0)
		return n;
	gcd(m, n%m);
}

int List::max(int x, int y)
{
	return x >= y ? x : y;
}

void List::output()
{
	linkNode* current = first->link;
	while (current != rear)
	{

		cout << current->data << "->";
		current = current->link;
	}
	cout << rear->data;
	if (rear->link != nullptr)//为循环小数
	{
		current = rear->link;
		cout << "\n循环节： ";
		while (current != rear)
		{

			cout << current->data << "->";
			current = current->link;
		}
		cout << rear->data<<endl;
	}
	cout << endl;
}