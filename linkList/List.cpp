#include "stdafx.h"
#include"List.h"
#include<iostream>
using namespace std;
void SiCircList::input(int a[],int size)
{
	linkNode*newNode;
	for (int i = 0; i < size; i++)
	{
		newNode = new linkNode(a[i]);
		if (newNode == nullptr)
		{
			cerr << "存储分配错误！" << endl;
			exit(1);
		}
		newNode->link = first;
		rear->link = newNode;
		rear = newNode;
	
	}
}

void SiCircList::reverse()
{
	if (isEmpty())
		cout << "链表为空！";
	else
	{
		linkNode* current = first;
		linkNode* before = first;
		current = current->link;
		first->link = rear;
		while (current != first)
		{
			linkNode* temp = current;
			current = current->link;
			temp->link = before;
			before = temp;

		}


	}

}

void SiCircList::output()
{
	linkNode* current = first->link;
	while (current != first)
	{

		cout << current->data << "->";
		current = current->link;


	}


}

void SiCircList::makeEmpty()
{
	cout << "调用makeEmpty()!" << endl;
	linkNode* q;
	while (first->link !=first)
	{

		q = first->link;
		first->link = q->link;
		delete q;
	}
	delete first;

}

void SiCircList::debug()
{
	if (rear->link == first)
		cout << "True!" << endl;
	if (first == nullptr)
		cout << "True!" << endl;
}