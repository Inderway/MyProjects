#include "stdafx.h"
#include "Map.h"
#include<ctime>
#include<cstdlib>
using namespace std;

enum{lu,ld,ru,rd,l,r,u,d,m};//分别表示点在左上角，左下角，右上角，右下角，左边，右边，上边，下边，中央

Map::Map(int n)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			map_i[i][j] = 'x';//0表示没被踩过且不是地雷
			map_o[i][j] = 0;
		}
	setMine(n);
	setMap_o();
	won = 0;
	
}

void Map::setMine(int n)
{
	int i, j;
	srand(time(0));
	
	while (n > 0)
	{

		i = rand() % 10;

		j = rand() % 10;
		
		while (map_i[i][j] == '*')//已经有雷
		{
			i = rand() % 10;
			j = rand() % 10;//考虑到雷数较少，不会出现多次重复情况，while循环次数会较少

		}
		map_i[i][j] = '*';
		n--;
	}
}

void Map::setMap_o()
{
	for(int i=0;i<10;i++)
		for (int j = 0; j < 10; j++)
		{
			if (map_i[i][j] == '*')
			{
				map_o[i][j] = -1;
				switch (position(i,j))
				{
				case lu: {
	
					if(map_o[i + 1][j]!=-1)
						map_o[i+1][j]++;
					if (map_o[i][j + 1] != -1)
						map_o[i][j+1]++;
					if (map_o[i + 1][j + 1] != -1)
						map_o[i+1][j+1]++;
					break;
				};
				case ld: {
					if (map_o[i - 1][j] != -1)
						map_o[i - 1][j]++;
					if (map_o[i][j + 1] != -1)
						map_o[i][j + 1]++;
					if (map_o[i - 1][j + 1] != -1)
						map_o[i - 1][j + 1]++;
					break;
				};
				case ru: {
					if (map_o[i + 1][j] != -1)
						map_o[i + 1][j]++;
					if (map_o[i][j - 1] != -1)
						map_o[i][j - 1]++;
					if (map_o[i + 1][j - 1] != -1)
						map_o[i + 1][j - 1]++;
					break;
				};
				case rd: {
					if (map_o[i - 1][j] != -1)
						map_o[i - 1][j]++;
					if (map_o[i][j-1] != -1)
						map_o[i][j - 1]++;
					if (map_o[i - 1][j-1] != -1)
						map_o[i - 1][j - 1]++;
					break;
				};
				case u: {
					if (map_o[i][j - 1] != -1)
						map_o[i][j-1]++;
					if (map_o[i][j+1] != -1)
						map_o[i][j + 1]++;
					if (map_o[i + 1][j-1] != -1)
						map_o[i + 1][j - 1]++;
					if (map_o[i + 1][j] != -1)
						map_o[i + 1][j ]++;
					if (map_o[i + 1][j+1] != -1)
						map_o[i + 1][j + 1]++;
					break;
				};
				case d: {
					if (map_o[i ][j-1] != -1)
						map_o[i][j - 1]++;
					if (map_o[i ][j+1] != -1)
						map_o[i][j + 1]++;
					if (map_o[i - 1][j-1] != -1)
						map_o[i -1][j - 1]++;
					if (map_o[i - 1][j] != -1)
						map_o[i - 1][j]++;
					if (map_o[i - 1][j+1] != -1)
						map_o[i - 1][j + 1]++;
					break;
				};
				case l: {
					if (map_o[i - 1][j] != -1)
						map_o[i-1][j]++;
					if (map_o[i + 1][j] != -1)
						map_o[i+1][j]++;
					if (map_o[i - 1][j+1] != -1)
						map_o[i - 1][j +1]++;
					if (map_o[i ][j+1] != -1)
						map_o[i][j+1]++;
					if (map_o[i + 1][j+1] != -1)
						map_o[i + 1][j + 1]++;
					break;
				};
				case r: {
					if (map_o[i - 1][j] != -1)
						map_o[i - 1][j]++;
					if (map_o[i + 1][j] != -1)
						map_o[i + 1][j]++;
					if (map_o[i - 1][j-1] != -1)
						map_o[i - 1][j - 1]++;
					if (map_o[i ][j-1] != -1)
						map_o[i][j - 1]++;
					if (map_o[i + 1][j-1] != -1)
						map_o[i + 1][j - 1]++;
					break;
				};
				case m: {
					if (map_o[i - 1][j] != -1)
						map_o[i - 1][j]++;
					if (map_o[i + 1][j] != -1)
						map_o[i + 1][j]++;
					if (map_o[i - 1][j+1] != -1)
						map_o[i - 1][j + 1]++;
					if (map_o[i][j+1] != -1)
						map_o[i][j + 1]++;
					if (map_o[i + 1][j+1] != -1)
						map_o[i + 1][j + 1]++;
					if (map_o[i - 1][j-1] != -1)
						map_o[i - 1][j - 1]++;
					if (map_o[i][j-1] != -1)
						map_o[i][j - 1]++;
					if (map_o[i + 1][j-1] != -1)
						map_o[i + 1][j - 1]++;
					break;

				};

				}
			}
		}
}


int Map::position(int i,int j)
{
	if (i == 0 && j == 0)
		return lu;
	else if (i == 0 && j == 9)
		return ru;
	else if (i == 9 && j == 0)
		return ld;
	else if (i == 9 && j == 9)
		return rd;
	else if (i == 0)
		return u;
	else if (i == 9)
		return d;
	else if (j == 0)
		return l;
	else if (j == 9)
		return r;
	else
		return m;

}

void Map::output()
{
	/*
	for(int i=0;i<10;i++)
		for (int j = 0; j < 10; j++)
		{
			
			if (j == 9)
			{
				cout.width(3);
				cout << map_o[i][j] << endl;
			}
			else
			{
				cout.width(3);
				cout << map_o[i][j] << ' ';
			}
		}
	cout << endl;
	*/
	for (int i = 0; i<10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (j == 9)
			{
				if (map_i[i][j] == '*')
				{
					cout.width(3);
					cout <<'x'<< endl;
				}
				else
				{
					cout.width(3);
					cout << map_i[i][j] << endl;
				}
			}
			else
			{
				if (map_i[i][j] == '*')
				{
					cout.width(3);
					cout << 'x' << ' ';
				}
				else
				{
					cout.width(3);
					cout << map_i[i][j] << ' ';
				}
			}
		}
}

void Map::sweep(int i, int j)
{
	if (map_i[i][j] == '*')
	{
		won = 2;//输了
		cout << "Game Over!" << endl;
	}
	if (map_o[i][j] > 0)
	{
		map_i[i][j] = char(map_o[i][j])+48;
	}
	else
	{
		map_i[i][j] = char(0)+48;
		map_o[i][j] = 9;
		switch (position(i, j))
		{
		case lu: {
			if(map_o[i][j+1]!=9)
				sweep(i, j + 1);
			if(map_o[i+1][j] != 9)
				sweep(i + 1, j);
			break;
		};
		case ld: {
			if(map_o[i][j + 1] != 9)
				sweep(i, j + 1);
			if(map_o[i-1][j] != 9)
				sweep(i - 1, j);
			break;
		};
		case ru: {
			if (map_o[i ][j-1] != 9)
				sweep(i, j - 1);
			if (map_o[i + 1][j] != 9)
				sweep(i + 1, j);
			break;
		};
		case rd: {
			if (map_o[i][j-1] != 9)
				sweep(i, j - 1);
			if (map_o[i - 1][j] != 9)
				sweep(i - 1, j);
			break;
		};
		case u: {
			if (map_o[i ][j+1] != 9)
				sweep(i, j + 1);
			if (map_o[i ][j-1] != 9)
				sweep(i, j-1);
			if (map_o[i + 1][j] != 9)
				sweep(i + 1, j);
			break;
		};
		case d: {
			if (map_o[i ][j+1] != 9)
				sweep(i, j + 1);
			if (map_o[i ][j-1] != 9)
				sweep(i, j - 1);
			if (map_o[i - 1][j] != 9)
				sweep(i -1, j);
			break;
		};
		case l: {
			if (map_o[i ][j+1] != 9)
				sweep(i, j + 1);
			if (map_o[i +1][j] != 9)
				sweep(i+1, j );
			if (map_o[i - 1][j] != 9)
				sweep(i - 1, j);
			break;
		};
		case r: {
			if (map_o[i ][j-1] != 9)
				sweep(i, j - 1);
			if (map_o[i + 1][j] != 9)
				sweep(i + 1, j);
			if (map_o[i - 1][j] != 9)
				sweep(i - 1, j);
			break;
		};
		case m: {
			if (map_o[i ][j+1] != 9)
				sweep(i, j + 1);
			if (map_o[i +1][j] != 9)
				sweep(i + 1, j);
			if (map_o[i - 1][j] != 9)
				sweep(i - 1, j);
			if (map_o[i ][j-1] != 9)
				sweep(i, j - 1);
			break;
		};
		}
	}
}

void Map::win(int n)
{
	int count = 0;
	char win[10][10];
	for (int i = 0; i<10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (map_i[i][j] == '*')
				win[i][j] = 'x';
			else
				win[i][j] = map_i[i][j];
		}
	for (int i = 0; i<10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (win[i][j] == 'x')
				count++;
		}
	if (count == n)
	{
		cout << "You win!\n";
		won = 1;//赢了
	}

}

bool Map::isReapted(int i, int j)
{
	if (map_i[i][j] != 'x'&&map_i[i][j] != '*')
	{
		cout << "此点已探索过！\n";
		return true;
	}
	else
		return false;
}

Map::~Map()
{
}

