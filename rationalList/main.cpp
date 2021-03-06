// RationalList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"List.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<Windows.h>

using namespace std;
void makeRand(int&n, int&m);
int main()
{
	int n1 = 0; 
	int m1 = 0; 
	int n2 = 0;
	int m2 = 0; 
	int n3 = 0; 
	int m3 = 0;
	makeRand(n1, m1);
	makeRand(n2, m2);
	makeRand(n3, m3);
	cout << "\n-------随机生成三组整数（0<n<1000, 0<m<101,n为分子，m为分母)\n";
	cout << "n1= " << n1 << setw(5) << "m1= " << m1 <<endl;
	cout << "n2= " << n2 << setw(5) << "m2= " << m2 << endl;
	cout << "n3= " << n3 << setw(5) << "m3= " << m3 << endl;
	cout << "\n-------若分数为无限循环小数，则输出循环节-------\n";
	double Ad = double(n1) / double(m1);
	double Bd = double(n2) / double(m2);
	double Cd = double(n3) / double(m3);
	List A;
	A.construct(n1, m1);
	A.output();

	List B;
	B.construct(n2, m2);
	B.output();

	List C;
	C.construct(n3, m3);
	C.output();

	cout << "\n-------这三个分数的double结果为（精确到小数点后13位)-------\n";
	cout << fixed;
	cout.precision(13);
	cout << Ad << endl;
	cout << Bd << endl;
	cout << Cd << endl;
	return 0;
}

void makeRand(int&n, int&m)
{
	LARGE_INTEGER seed;
	QueryPerformanceFrequency(&seed);
	QueryPerformanceCounter(&seed);
	srand(seed.QuadPart);//使生成种子间隔为1ms，以防出现相同随机数
	n = rand() % 1000+1;
	while (n == 1000)
	{
		n = rand() % 1000+1;
	}
	m = rand() % 100 + 1;
}