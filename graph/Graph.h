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
	friend void write(ifstream& fin1,ifstream&fin2, Graph &G);//���ļ�������ȡ����д��ͼ,fin1Ϊ�����fin2Ϊ�߼���
	friend void output(Graph&G);//���ͼ�Ķ�����ڽӾ���
	friend void DFS(Graph& G, int v, bool visited[]);//��ȱ����ӹ���
	friend void DFS(Graph& G, const char&v);//��ȱ����ܹ���
	friend void BFS(Graph& G, const char&v,bool visited[]);//��ȱ����ӹ���
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
	char getValue(int i)//����ֵ
	{
		return i >= 0 && i < numVertices ? VerticesList[i]:NULL;
	}

	int getFirstNeighbor(int v);//����v��һ���ڽӶ���
	int getNextNeibghbor(int v, int w);//ȡ����v���ڽӶ���w����һ���ڽӶ���
	bool insertVertex(const char&vertex);//���붥��
	virtual bool inserEdge(int v1, int v2, int cost);//�����
	bool isAllVisited(bool visited[], int size)//�ж��Ƿ��ѷ���
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
	char* VerticesList;//�����
	int** Edge;//�ڽӾ���

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
	virtual bool inserEdge(int v1, int v2, int cost);//�����
};


