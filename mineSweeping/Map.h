#pragma once
#include<iostream>
class Map
{


public:
	Map(int n = 0);
	~Map();
	void setMine(int);//�����
	void setMap_o();//��ͼ���ͼ������
	int position(int,int);//����λ���ж�
	void output();
	void sweep(int, int);
	void win(int);
	int won;//ʤ����־
	bool isReapted(int ,int);
private:
	char map_i[10][10];
	int map_o[10][10];



};

