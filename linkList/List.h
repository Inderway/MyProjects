#pragma once
#include<iostream>
struct linkNode
{
	int data;
	linkNode* link;
	linkNode(linkNode*next=nullptr):link(next){}
	linkNode(int d,linkNode*next=nullptr):data(d),link(next){}
};

class SiCircList
{
public:
	SiCircList() { first = new linkNode; first->link = first; rear = first; }
	~SiCircList() { makeEmpty(); std::cout << "Destroy!" <<std::endl; }
	void input(int a[],int size);//β�巨����
	bool isEmpty() { return rear == first ? true : false; }
	void reverse();//�͵�ת��
	void output();
	void makeEmpty();//�ÿ�
	void debug();
private:
	linkNode * first, *rear;

};