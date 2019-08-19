#pragma once
#include<iostream>
struct linkNode
{
	int data;
	linkNode* link;
	linkNode(linkNode*next = nullptr) :link(next) {}
	linkNode(int d, linkNode*next = nullptr) :data(d), link(next) {}
};


class List
{
public:
	List() { first = new linkNode; rear = first; }
	//~List() { makeEmpty(); std::cout << "Destroy!" << std::endl; }
	bool isEmpty() { return first->link==first ? true : false; }
	void makeEmpty();
	void insert(int x);//插入
	void construct(int n,int m);//构造有理数链表
	void output();
	int gcd(int n, int m);
	int max(int x, int y);
private:
	linkNode * first;
	linkNode*rear;
};

