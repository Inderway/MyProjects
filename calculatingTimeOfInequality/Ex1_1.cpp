// Ex1_1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<time.h>
using namespace std;

int Inequality(int, int&,int&);

int main()
{
	clock_t start, stop;
	double time;
	start = clock();
	int n[5] = { 50,500,5000,50000,500000};
	
	int numberResult[5] = { 0 };
	int countResult[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{

		Inequality(n[i],numberResult[i],countResult[i]);
		cout << "满足不等式1+2+3+...+i>=" << n[i] << "的最小i值为: " <<
			Inequality(n[i], numberResult[i], countResult[i]) << endl
			<< "算法步数为: " << countResult[i] << endl<<endl;

			
	}
	stop = clock();
	time = (double)(stop - start);
	cout.precision(3);
	cout << "程序运行时间为："<<time/CLOCKS_PER_SEC<<"s"<<endl;
	
	system("pause");
	return 0;
}

int Inequality(int num, int& numberR, int& countR)
{
	int i = 1;
	countR++;
	int sum = 1;
	countR++;
	while (sum<num)
	{
		countR++;
		i++;
		sum += i;
		countR+=2;
	}
	numberR = i;
	countR++;
	countR++;
	return numberR;
}
