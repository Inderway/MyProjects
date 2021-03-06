// Ex4_1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void createArray(int a[],int n);//构建元素为正数或负数的数组
void arrange(int a[], int n, int Out[]);//测试函数，将负数置于正数前

int main()
{
	int a[10] = { 0 };
	int out[10] = { 0 };
	createArray(a, 10);
	arrange(a, 10, out);
	cout << "原数组：\n";
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	cout << "\n整理后：\n";
	for (int i = 0; i < 10; i++)
		cout << out[i] << ' ';

	
	
	return 0;
}


void createArray(int a[], int n)
{
	bool op;//判定正负
	int data;//整数的绝对值，取1到10
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		op = rand() % 2;
		data= rand() % 10 + 1;
		if (!op)//为负数
			data = 0 - data;

			a[i] = data;
	}
}

void arrange(int a[], int n, int Out[])
{
	int posA = 0;
	int posB = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			Out[posA++] = a[i];
		else
			Out[posB--] =a[i];
	}

}