#include "stdafx.h"

#include "minHeap.h"
#include<iostream>
#include<fstream>
using namespace std;



minHeap::minHeap(int sz)
{
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new Item[maxHeapSize];
	if (heap == NULL)
	{
		cerr << "¶Ñ´æ´¢·ÖÅäÊ§°Ü£¡" << endl;
		exit(1);
	}
	currentSize = 0;

}

minHeap::minHeap(Item a[], int n)
{
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new Item[maxHeapSize];
	if (heap == NULL)
	{
		cerr << "¶Ñ´æ´¢·ÖÅäÊ§°Ü!" << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++)
		heap[i] = a[i];
	currentSize = n;
	int currentPos = (currentSize - 2) / 2;
	while (currentPos >= 0)
	{
		siftDown(currentPos, currentSize - 1);
		currentPos--;
	}
}

void minHeap::siftDown(int start, int m)
{
	int i = start;
	int j = 2 * i + 1;
	Item temp = heap[i];
	while (j <= m)
	{
		if (j<m&&heap[j].weight>heap[j+1].weight)
			j++;
		if (temp.weight <= heap[j].weight)
			break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}

	}
	heap[i] = temp;
}

void minHeap::siftUp(int start)
{
	int j = start;
	int i = (j - 1) / 2;
	Item temp = heap[j];
	while (j > 0)
	{
		if (heap[i].weight <= temp.weight)
			break;
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}

	}
	heap[j] = temp;
}

bool minHeap::insert(const Item&x)
{
	if (currentSize == maxHeapSize)
	{
		cerr << "Heap Full" << endl;
		return false;
	}
	heap[currentSize] = x;
	siftUp(currentSize);
	currentSize++;
	return true;
}

bool minHeap::removeMin(Item&x)
{
	if (!currentSize)
	{
		cout << "Heap empty" << endl;
		return false;
	}
	x = heap[0];
	heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);
	return true;
}

HuffmanTree::HuffmanTree(minHeap& h, Item a[], int sz)
{
	leaf = sz;
	tree = new treeNode[2*leaf-1];
	code = new string[leaf];
	int i = leaf;
	treeNode first;
	treeNode second;
	treeNode merge;
	//initialize
	for (int j = 0; j < 2 * leaf - 1; j++)
	{
		tree[j].value.character = 0;
		tree[j].value.weight = 0;
		tree[j].leftChild = -1;
		tree[j].rightChild = -1;
		tree[j].parent = -1;
	}
	for (int j = 0; j < leaf; j++)
	{
		tree[j].value.character =j;
		tree[j].value.weight = a[j].weight;
		tree[j].leftChild = tree[j].rightChild = -1;
	}
	//cout <<endl<< h.currentSize<<endl;
	/*
	for (int j =(sz+1)/2; j < sz; j++)
	{
		tree[j].value.character = j;
		tree[j].value.weight = 0;
		tree[j].leftChild = tree[j].rightChild =-1;
	}
	*/
	while (i<2*leaf-1)
	{
		h.removeMin(first.value);
		h.removeMin(second.value);
		merge.value.character = i;
		merge.value.weight = first.value.weight + second.value.weight;
		merge.leftChild = first.value.character;
		merge.rightChild = second.value.character;
		tree[i] = merge;
		tree[first.value.character].parent = i;
		tree[second.value.character].parent = i;

		i++;
		h.insert(merge.value);

	}
	tree[2 * leaf - 2].parent = -1;
}

HuffmanTree::~HuffmanTree()
{
	delete[] tree;
	delete[] code;
	cout << "\nDestroyed!\n";
}

void HuffmanTree::coding_in(treeNode node, string& r_code)
{
	if (node.parent != -1)
	{
		if (tree[node.parent].leftChild == node.value.character)//¸¸µÄ×ó×ÓÊ÷Îªnode£¬Ôò·´Âë¼Ó0
		{
			r_code += '0';
		}
		if (tree[node.parent].rightChild == node.value.character)
		{
			r_code += '1';
		}
		coding_in(tree[node.parent], r_code);

	}
}

void HuffmanTree::coding()
{
	int i = 0;

	while (i < leaf)
	{
		string r_code;
		coding_in(tree[i], r_code);
		code[i] = reverse(r_code);
		i++;
	}
}

string HuffmanTree::reverse(string temp_code)
{
	string r_code;
	int n = temp_code.length();
	for (int i=0;i<n;i++)
	{
		r_code += temp_code[n - 1 - i];
	}
	return r_code;
}

void HuffmanTree::uncode()
{
	ifstream fin;
	ofstream fout;
	fin.open("code.txt");
	fout.open("uncode.txt");

	char ch_i;
	
	fin >> noskipws;
	int pos = 2*leaf-2;
	while (fin >> ch_i)
	{
		if (ch_i == '0')
		{
			pos = tree[pos].leftChild;
			if (pos >= 0 && pos < leaf)
			{
				fout << tranform(pos);
				pos = 2 * leaf - 2;
			}
		}
		if (ch_i == '1')
		{
			pos = tree[pos].rightChild;
			if (pos >= 0 && pos < leaf)
			{
				fout << tranform(pos);
				pos = 2 * leaf - 2;
			}
		}
	}
	//fin >> ch_i;

	//uncode_in(pos, ch_i, fin, fout);

	fin.close();
	fout.close();
}

int HuffmanTree::tranform(char c)
{
	int n = 0;
	switch (c)
	{
	case 'A':n = 0; break;
	case'a':n = 0; break;
	case'B':n = 1; break;
	case'b':n = 1; break;
	case'C':n = 2; break;
	case'c':n = 2; break;
	case'D':n = 3; break;
	case'd':n = 3; break;
	case'E':n = 4; break;
	case'e':n = 4; break;
	case'F':n = 5; break;
	case'f':n = 5; break;
	case'G':n = 6; break;
	case'g':n = 6; break;
	case'H':n = 7; break;
	case'h':n = 7; break;
	case'I':n = 8; break;
	case'i':n = 8; break;
	case'J':n = 9; break;
	case'j':n = 9; break;
	case'K':n = 10; break;
	case'k':n = 10; break;
	case'L':n = 11; break;
	case'l':n = 11; break;
	case'M':n = 12; break;
	case'm':n = 12; break;
	case'N':n = 13; break;
	case'n':n = 13; break;
	case'O':n = 14; break;
	case'o':n = 14; break;
	case'P':n = 15; break;
	case'p':n = 15; break;
	case'Q':n = 16; break;
	case'q':n = 16; break;
	case'R':n = 17; break;
	case'r':n = 17; break;
	case'S':n = 18; break;
	case's':n = 18; break;
	case'T':n = 19; break;
	case't':n = 19; break;
	case'U':n = 20; break;
	case'u':n = 20; break;
	case'V':n = 21; break;
	case'v':n = 21; break;
	case'W':n = 22; break;
	case'w':n = 22; break;
	case'X':n = 23; break;
	case'x':n = 23; break;
	case'Y':n = 24; break;
	case'y':n = 24; break;
	case'Z':n = 25; break;
	case'z':n = 25; break;
	case' ':n = 26; break;
	case';':n = 27; break;
	case'.':n = 28; break;
	case',':n = 29; break;
	case'-':n = 30; break;
	case'?':n = 31; break;
	case'\'':n = 32; break;
	}
	return n;
}

char HuffmanTree::tranform(int n)
{
	char ch;
	switch (n)
	{
	case 0:ch = 'a'; break;
	case 1:ch = 'b'; break;
	case 2:ch = 'c'; break;
	case 3:ch = 'd'; break;
	case 4:ch = 'e'; break;
	case 5:ch = 'f'; break;
	case 6:ch = 'g'; break;
	case 7:ch = 'h'; break;
	case 8:ch = 'i'; break;
	case 9:ch = 'j'; break;
	case 10:ch = 'k'; break;
	case 11:ch = 'l'; break;
	case 12:ch = 'm'; break;
	case 13:ch = 'n'; break;
	case 14:ch = 'o'; break;
	case 15:ch = 'p'; break;
	case 16:ch = 'q'; break;
	case 17:ch = 'r'; break;
	case 18:ch = 's'; break;
	case 19:ch = 't'; break;
	case 20:ch = 'u'; break;
	case 21:ch = 'v'; break;
	case 22:ch = 'w'; break;
	case 23:ch = 'x'; break;
	case 24:ch = 'y'; break;
	case 25:ch = 'z'; break;
	case 26:ch = ' '; break;
	case 27:ch = ';'; break;
	case 28:ch = '.'; break;
	case 29:ch = ','; break;
	case 30:ch = '-'; break;
	case 31:ch = '?'; break;
	case 32:ch = '\''; break;

	}
	return ch;
}

