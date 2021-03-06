// Hash.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"HashTable.h"
#include<ctime>
#include<cstdlib>
#include<Windows.h>
#include<iostream>

using namespace std;

int main()
{
	int n[3] = { 10,20,50 };
	for (int i = 0; i < 3; i++) 
	{
		int *a = new int[n[i]];
		int prim;
		cout << "\n\n从质数序列{3,7,11,19}中选取一个值(此时关键码个数为： "<<n[i]<<")：\n";
		cin>> prim;
		for (int j = 0; j < n[i]; j++)
		{
			LARGE_INTEGER seed;
			QueryPerformanceFrequency(&seed);
			QueryPerformanceCounter(&seed);
			srand(seed.QuadPart);//使生成种子间隔为1ms，以防出现相同随机数
			a[j] = rand() % 1000 + 1;
		}
		HashTable H(prim, n[i], prim+1);//桶数比所取质数多1
		H.create(a);
		H.output(a);
		delete[]a;

	}
	return 0;
}

