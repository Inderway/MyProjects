// Tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<fstream>
#include<iostream>
#include"BinaryTree.h"
#include<cmath>

using namespace std;
int getVolumn(int m, int n,int height);//根据data在array中位置求得其在arrayOut中位置


int main()
{
	ifstream fin;
	fin.open("Tree.txt");
	BinaryTree<char> tree('#');
	tree.CreateBinTree(fin,tree.root);
	int height = tree.Height(tree.root);
	int volumn = pow(2, height);
	
	//BinTreeNode<char>* p;
	//tree.Find('G', tree.root,p);
	//cout << p->data << endl;

	//int level=0;
	
	//tree.getLevel(p, tree.root, level);
	//cout << level << endl;
	tree.landscapeOutput(tree.root);
	cout << endl;
	//BinTreeNode<char>* s = tree.root->leftChild;
	//int pos = 0;
	//BinTreeNode<char>*parent;
	//tree.Parent(p,pos,parent);
	//cout << pos << ' ' << parent->data << endl;
	//cout << tree.getVolumn(p)<<' '<<endl;
	char **array;
	array = new char*[height+1];
	for (int i = 0; i <=height; i++)
	{
		array[i] = new char[volumn];
	}

	for (int i = 0; i <=height; i++)
		for (int j = 0; j < volumn; j++)
			array[i][j] = '#';
	tree.store(tree.root, array);
	for (int i = 0; i <=height; i++)
		for (int j = 0; j < volumn; j++)
		{
			cout << array[i][j] <<' ';
			if (j == volumn - 1)
				cout << endl;
		}
	cout << endl;

	//输出数组
	int height2 = 2 * height - 1;
	int volumn2 = int(pow(2, height + 1)) - 1;

	char **arrayOut;
	arrayOut = new char*[height2];
	for (int i = 0; i < height2; i++)
	{
		arrayOut[i] = new char[volumn2];
	}
	for (int i = 0; i <height2; i++)
		for (int j = 0; j < volumn2; j++)
			arrayOut[i][j] = '#';
	arrayOut[0][int(pow(2, height) - 1)] = array[0][0];

	for(int i=0;i<height;i++)
		for (int j = 0; j <int(pow(2,i)); j++)
		{
			if (array[i + 1][2 * j ] != '#')
			{
				for (int k = 1; k <= int(pow(2, (3 - i))); k++)
				{
					arrayOut[2 * i][getVolumn(i, j, height) - k] = '.';
				}
				arrayOut[2 * i + 1][getVolumn(i, j, height) - int(pow(2, (3 - i)))] = '|';
				arrayOut[2 * (i+1)][getVolumn(i, j, height) - int(pow(2, (3 - i)))] = array[i + 1][2 * j];
			}
			if (array[i + 1][2 * j+1] != '#')
			{
				for (int k = 1; k <= int(pow(2, (3 - i))); k++)
				{
					arrayOut[2* i][getVolumn(i, j, height) + k] = '.';
				}
				arrayOut[2* i + 1][getVolumn(i, j, height) + int(pow(2, (3 - i)))] = '|';
				arrayOut[2 * (i+1) ][getVolumn(i, j, height) + int(pow(2, (3 - i)))] = array[i + 1][2 * j+1];
			}

		}

	//cout << getVolumn(2, 2, 4)<<endl;
	for (int i = 0; i <height2; i++)
		for (int j = 0; j < volumn2; j++)
		{
			if (arrayOut[i][j] == '#')
				cout << ' ';
			else 
			{
				cout << arrayOut[i][j];
			
			}
			if (j == volumn2 - 1)
				cout << endl;
		}



	int n;//度为1结点数
	n = tree.Find(tree.root);
	cout << "树中度为1结点数为： " << n<<endl;


	//收尾
	for (int i = 0; i <height2; i++)
	{
		delete[] arrayOut[i];
	}
	delete[]arrayOut;
	
	
	for (int i = 0; i <= height; i++)
	{
		delete[] array[i];
	}
	delete []array;
	fin.close();
	return 0;
}

int getVolumn(int m, int n,int height)
{
	if (m == 0)
		return 15;
	else
	{
		if (n % 2 == 0)
		{
			return getVolumn(m - 1, n / 2,height) - int(pow(2, height-m));

		}
		else
		{
			return getVolumn(m - 1, (n - 1) / 2, height) + int(pow(2, height - m));
		}
	}

}