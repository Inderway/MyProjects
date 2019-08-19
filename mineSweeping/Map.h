#pragma once
#include<iostream>
class Map
{


public:
	Map(int n = 0);
	~Map();
	void setMine(int);//埋地雷
	void setMap_o();//雷图输出图像设置
	int position(int,int);//返回位置判定
	void output();
	void sweep(int, int);
	void win(int);
	int won;//胜利标志
	bool isReapted(int ,int);
private:
	char map_i[10][10];
	int map_o[10][10];



};

