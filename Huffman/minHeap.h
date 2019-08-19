#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

const int DefaultSize = 100;
struct Item
{
	int character;
	int weight;
};
//从0-25对应a-z，26-32对应' ', ';', '.', ',', '-', '?', '''

class minHeap
{

public:
	minHeap(int sz=DefaultSize);
	minHeap(Item a[], int n);
	~minHeap() { delete[]heap; }
	bool insert(const Item&x);
	bool removeMin(Item&x);
	bool isEmpty()const
	{
		return (currentSize == 0) ? true : false;
	}
	bool isFull()const
	{
		return (currentSize == maxHeapSize) ? true : false;
	}
	void MakeEmpty() { currentSize = 0; }

	Item*  heap;
	int currentSize;
private:
	

	int maxHeapSize;
	void siftDown(int start, int m);
	void siftUp(int start);
};

//Huffman树,静态链表
struct treeNode
{
	Item value;
	int leftChild;
	int rightChild;
	int parent;
};

class HuffmanTree
{
public:
	HuffmanTree(minHeap& h,Item a[],int sz);
	~HuffmanTree();
	void coding();
	string reverse(string temp_code);//将倒序编码转正序
	void uncode();//解码
	int tranform(char c);
	char tranform(int n);
	
	treeNode *tree;
	string *code;

private:
	int leaf;

	void coding_in(treeNode node, string& r_code);

};
