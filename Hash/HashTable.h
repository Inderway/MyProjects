#pragma once
#include<iostream>
const int DefaultSize = 100;
struct ChainNode
{
	int data;
	ChainNode* link;
	ChainNode(int n, ChainNode* next = nullptr) :data(n), link(next) {}
	ChainNode(ChainNode*next = nullptr):link(next) {}
};

class HashTable
{
public:
	HashTable(int d, int k,int sz=DefaultSize);
	~HashTable() { delete[]ht; }
	bool insert(const int&d);
	void create(int*&a);//根据关键码构建Hash表
	int search(const int k);//返回查找次数
	float ASL(int*& a);//计算搜索成功平均搜索长度
	float ASLun();//计算搜索不成功平均搜索长度
	int unsearch(int pos);//计算ASLun用
	void output(int*& a);
	void alpha(float &Sn,float &Un);//计算理论平均搜索长度
private:
	int divisor;
	int TableSize;
	int key;//关键码个数
	ChainNode**ht;

};

