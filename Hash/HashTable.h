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
	void create(int*&a);//���ݹؼ��빹��Hash��
	int search(const int k);//���ز��Ҵ���
	float ASL(int*& a);//���������ɹ�ƽ����������
	float ASLun();//�����������ɹ�ƽ����������
	int unsearch(int pos);//����ASLun��
	void output(int*& a);
	void alpha(float &Sn,float &Un);//��������ƽ����������
private:
	int divisor;
	int TableSize;
	int key;//�ؼ������
	ChainNode**ht;

};

