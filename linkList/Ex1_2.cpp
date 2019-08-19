// Ex1_2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include"List.h"
using namespace std;

int main()
{

	ifstream fin;
	fin.open("data.txt");
	
	if (!fin.is_open())
		cerr << "文件打开错误！";
	else
	{



		int size;
		fin >> size;


		int*a;
		a = new int[size];
		//int a[17] = { 0 };
		for (int i = 0; i < size; i++)
		{
			fin >> a[i];
			//cout << a[i] << ' ';
		}
		SiCircList list;
		//list.debug();

		list.input(a, size);
		cout << "当前链表为：" << endl;

		list.output();
		cout << endl;
		cout << "就地转置后链表为： " << endl;
		list.reverse();
		list.output();
		cout << endl;
		delete a;
		char b = '\0';
		cout << b;

	}
	fin.close();
	cout << "Done!\n";
	system("pause");



	return 0;
}

