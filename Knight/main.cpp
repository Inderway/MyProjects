// Knight.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>

using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int a=0,int b=0):x(a),y(b){}
	Pos operator+(Pos&b)
	{
		Pos result;
		result.x = this->x + b.x;
		result.y = this->y + b.y;
		return result;
	}
};
//移动初始化,八个方向



void go(Pos& p,int &count,int sz,int** &board);

bool isOut(Pos p,int sz);//判断是否越界

Pos move(int i);//移动函数

void countBoard(Pos s,int** &cntBoard,int sz);//标记棋盘
bool isFull(int**&cntBoard, int sz);//判断标记棋盘是否已满
void findPath(Pos f, int**&Path, int**&cntBoard, int sz);//寻找最短路径
int main()
{

	int size;
	Pos startPos;
	cout << "---输入棋盘大小---\n";
	cin >> size;
	cout << "---输入骑士开始坐标---\n";
	cin >> startPos.x >> startPos.y;
	//cout << startPos.x << ' ' << startPos.y<<endl;
	//来人，端棋盘
	int** board;
	board = new int*[size];
	for (int i = 0; i < size; i++)
		board[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			board[i][j] = 0;

	int** cntBoard;//求最短路径时标记数字用棋盘
	cntBoard = new int*[size];
	for (int i = 0; i < size; i++)
		cntBoard[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cntBoard[i][j] = 0;
	int**path;//最短路径输出棋盘
	path= new int*[size];
	for (int i = 0; i < size; i++)
		path[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			path[i][j] = 0;

	//上骑士
	int count = 1;
	go(startPos, count, size, board);
	//输出棋盘
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(4) << board[i][j];
		}
		cout << endl;
	}
	//求最短路径
	Pos start;
	Pos final;
	cout << "\n-----求最短路径-----\n输入起点坐标:\n";
	cin >> start.x >> start.y;
	cout << "输入终点坐标:\n";
	cin >> final.x >> final.y;
	countBoard(start, cntBoard, size);
	findPath(final, path, cntBoard, size);
	//输出路径
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(4) << path[i][j];
		}
		cout << endl;
	}
	//cout << board[4][5] << endl;
	//来人，撤棋盘

	for (int i = 0; i < size; i++)
		delete []path[i];
	delete[]path;
	for (int i = 0; i < size; i++)
		delete []cntBoard[i];
	delete[]cntBoard;

	for (int i = 0; i < size; i++)
		delete []board[i];
	delete []board;

	return 0;
}

bool isOut(Pos p, int sz)
{
	if (p.x >= sz || p.x  < 0
		|| p.y >= sz || p.y < 0)
		return true;
	return false;
}

void go(Pos &p,int& count,int sz,int**&board)
{
	if (!isOut(p, sz) && board[p.x][p.y] == 0)
	{
		board[p.x][p.y] = count;
		count++;
		//cout << count << endl;
		for (int k = 0; k < 8; k++)
		{
			Pos tmp;
			Pos m = move(k);
			tmp = p + m;
			go(tmp,count,sz,board);
		}
	
	}
	


}

Pos move(int i)
{
	Pos tmp0(-1, 2);
	Pos tmp1(1, 2);
	Pos tmp2(2, 1);
	Pos tmp3(2, -1);
	Pos tmp4(1, -2);
	Pos tmp5(-1, -2);
	Pos tmp6(-2, -1);
	Pos tmp7(-2, 1);
	switch (i)
	{

	case 0:return tmp0; break;
	case 1:return tmp1; break;
	case 2:return tmp2; break;
	case 3:return tmp3; break;
	case 4:return tmp4; break;
	case 5:return tmp5; break;
	case 6:return tmp6; break;
	case 7:return tmp7; break;
	}
}

void countBoard(Pos s, int** &cntBoard,int sz)
{
	int cntB = 1;
	cntBoard[s.x][s.y] = cntB;
	while (!isFull(cntBoard, sz))
	{
		for(int i=0;i<sz;i++)
			for (int j = 0; j < sz; j++)
			{
				if (cntBoard[i][j] == cntB)
				{
					for (int k = 0; k < 8; k++)
					{
						Pos m = move(k);
						Pos tmp;
						tmp.x = i + m.x;
						tmp.y = j + m.y;
						if (!isOut(tmp, sz) && cntBoard[tmp.x][tmp.y] == 0)
						{
							cntBoard[tmp.x][tmp.y] = cntB + 1;
						}
					}
									}
			}
		cntB++;
	}
}

bool isFull(int**&cntBoard, int sz)
{
	for(int i=0;i<sz;i++)
		for (int j = 0; j < sz; j++)
		{
			if (cntBoard[i][j] == 0)
				return false;
		}
	return true;
}

void findPath(Pos f, int**&Path, int**&cntBoard, int sz)
{
	int cnt = cntBoard[f.x][f.y];
	Path[f.x][f.y] = cnt;
	while (cnt > 1)
	{
		for(int i=0;i<sz;i++)
			for (int j = 0; j < sz; j++)
			{
				
				if (Path[i][j] == cnt)
				{
					for (int k = 0; k < 8; k++)
					{
						Pos m = move(k);
						Pos tmp;
						tmp.x = i + m.x;
						tmp.y = j + m.y;
						if (!isOut(tmp, sz) && cntBoard[tmp.x][tmp.y] == cnt-1)
						{
							Path[tmp.x][tmp.y] = cnt - 1;
						}
					}
				}
			}
		cnt--;
	}
}