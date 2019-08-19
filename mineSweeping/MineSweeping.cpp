// MineSweeping.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Map.h"
#include<iostream>
using namespace std;



int main()
{

	int start = 0;//为0时不开始，为1时开始
	int row, column;//要踩的点
	cout << "是否开始扫雷游戏？" << endl
		<< "是： y, 否： n" << endl;
	char judge;//是否开始游戏判定
	cin >> judge;
	while(judge != 'y' || judge != 'n')
	{
		if (judge == 'y' || judge == 'n')//judge为y或为n时都不会跳出循环，故设置break
			break;
		cout << "指令无效！请重新输入！" << endl;
		cin >> judge;

	}
	if (judge == 'y')
		start = 1;
	else
		start = 0;
	while (start)
	{
		cout << "请输入地雷个数，不得超过15个：" << endl;
		int n;
		cin >> n;
		while(n > 15 || n < 0)
		{
			cout << "输入无效，请重新输入！(地雷数在0到15之间，包括0和15)" << endl;
			cin >> n;

		}
		Map a(n);
		a.output();


		while (a.won==0)
		{
			cout << "输入要踩的点：（坐标范围为0到9）\n";
			cin >> row >> column;
			
			while (a.isReapted(row, column))
			{
				cin >> row >> column;
			}
			
			a.sweep(row, column);
			a.output();
			a.win(n);

		}

		cout << "是否继续？" << endl
			<< "是： y, 否： n" << endl;
		char judge;//是否开始游戏判定
		cin >> judge;
		while (judge != 'y' || judge != 'n')
		{
			if (judge == 'y' || judge == 'n')//judge为y或为n时都不会跳出循环，故设置break
				break;
			cout << "指令无效！请重新输入！" << endl;
			cin >> judge;

		}
		if (judge == 'y')
			start = 1;
		else
			start = 0;
	}
	/*
	int a[10] = { 0 };
	int i = 9;
	a[i + 1] = i;
	for (int j = 0; j < 10; j++)
		cout << a[j];
	
	int a[2][2] = { 1,2,3,4 };
	for (int i = 0; i<2; i++)
		for (int j = 0; j < 2; j++)
		{

			if (j == 1)
				cout << a[i][j] << endl;
			else
				cout << a[i][j] << ' ';

		}
	*/

}

