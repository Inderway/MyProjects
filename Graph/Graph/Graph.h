#pragma once
#include<limits.h>
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
const int  DefaultVertices = 30;

class Graph
{
//Friend
	friend void write(ifstream& fin1,ifstream&fin2, Graph &G);//从文件中中提取数据写入图,fin1为顶点表，fin2为边集合
	friend void output(Graph&G);//输出图的顶点和邻接矩阵
	friend void DFS(Graph& G, int v, bool visited[]);//深度遍历子过程
	friend void DFS(Graph& G, const char&v);//深度遍历总过程
	friend void BFS(Graph& G, const char&v,bool visited[]);//广度遍历子过程
	friend void BFS(Graph& G, const char&v);
public:
	const int maxWeight = INT_MAX;
	Graph(int sz=DefaultVertices);
	~Graph()
	{
		delete[]VerticesList;
		delete[]Edge;
	}
	bool GraphEmpty()const
	{
		if (numEdges == 0)
			return true;
		else
			return false;
	}
	bool GraphFull()const
	{
		if (numEdges == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)
			return true;
		else
			return false;
	}
	char getValue(int i)//顶点值
	{
		return i >= 0 && i < numVertices ? VerticesList[i]:NULL;
	}

	int getFirstNeighbor(int v);//顶点v第一个邻接顶点
	int getNextNeibghbor(int v, int w);//取顶点v的邻接顶点w的下一个邻接顶点
	bool insertVertex(const char&vertex);//插入顶点
	virtual bool inserEdge(int v1, int v2, int cost);//插入边
	bool isAllVisited(bool visited[], int size)//判断是否都已访问
	{
		for (int i = 0; i < size; i++)
		{
			if (!visited[i])
				return false;
		}
		return true;
	}
	
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
	char* VerticesList;//顶点表
	int** Edge;//邻接矩阵

	int getVertexPos(char vertex)
	{
		for (int i = 0; i < numVertices; i++)
			if (VerticesList[i] == vertex)
				return i;
		return -1;
	}

};

class oriented_Graph :public Graph
{
	virtual bool inserEdge(int v1, int v2, int cost);//插入边
};


