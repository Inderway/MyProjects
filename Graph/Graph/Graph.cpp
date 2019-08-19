#include "stdafx.h"
#include "Graph.h"
#include<iomanip>

Graph::Graph(int sz)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	int i, j;
	VerticesList = new char[maxVertices];
	Edge = new int*[maxVertices];
	for (i = 0; i < maxVertices; i++)
		Edge[i] = new int[maxVertices];
	for (i = 0; i < maxVertices; i++)
		for (j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) ? 0 : maxWeight;
}


bool Graph::insertVertex(const char&vertex)
{
	if (numVertices == maxVertices)
		return false;
	VerticesList[numVertices++] = vertex;
	return true;
}

bool Graph::inserEdge(int v1, int v2, int cost)
{
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < maxVertices&&Edge[v1][v2] == maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else return false;
}

bool oriented_Graph::inserEdge(int v1, int v2, int cost)
{
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < maxVertices&&Edge[v1][v2] == maxWeight)
	{
		Edge[v1][v2]= cost;
		numEdges++;
		return true;
	}
	else return false;
}

void write(ifstream& fin1, ifstream&fin2, Graph &G)
{
	int i, j, k, m,n;
	char e1, e2;
	int weight;
	fin1 >> n;//写入点
	fin2 >> m;//写入边
	for (i = 0; i < n; i++)//建立顶点表
	{
		fin1 >> e1;
		G.insertVertex(e1);
	}
	i = 0;
	while (i < m)
	{
		fin2 >> e1 >> e2 >> weight;
		j = G.getVertexPos(e1);
		k = G.getVertexPos(e2);
		if (j == -1 || k == -1)
			cout << "边信息有误！" << endl;
		else
		{
			G.inserEdge(j, k, weight);
			i++;
		}
	}
}

void output(Graph&G)
{

	for (int i = 0; i < 3; i++)
		cout << ' ';
	cout << '|';
	int j = 0;
	for (int i = 0; i < 4 * G.numVertices; i++)
	{

		if (i == 4 * j + 3)
			cout << G.VerticesList[j++];
		else
			cout << ' ';
	}
	cout <<endl;
	cout << "   | ";
	for (int i = 0; i < 4 * G.numVertices; i++)
	{
		cout << '-';
	}
	cout << endl;
	for (int i = 0; i < G.numVertices; i++)
	{
		cout << G.VerticesList[i] << "  |";
		for (int k = 0; k < G.numVertices; k++)
		{
			if (G.Edge[i][k] == G.maxWeight)
			{
				cout << setw(4) << setiosflags(ios::right) << ' ';
			}
			else
				cout << setw(4) << setiosflags(ios::right) << G.Edge[i][k];
		}
		cout << endl;
	}
}

int Graph::getFirstNeighbor(int v)
{
	if (v != -1)
	{
		for (int col = 0; col < numVertices; col++)
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
				return col;
	}
	return -1;
}

int Graph::getNextNeibghbor(int v, int w)
{
	if (v != -1 && w != -1)
	{
		for (int col = w + 1; col < numVertices; col++)
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
				return col;
	}
	return -1;
}

void DFS(Graph& G, int v, bool visited[])
{
	
	cout << G.getValue(v) ;
	visited[v] = true;
	int w = G.getFirstNeighbor(v);
	while (w != -1)
	{
		cout << "->";
		if (visited[w] == true)
		{

			cout << '(' << G.VerticesList[w] << ')' ;
		}
		if (visited[w] == false)
		{
			DFS(G, w, visited);

		}
		w = G.getNextNeibghbor(v, w); 

	}
}

void DFS(Graph& G, const char&v)
{
	int i, loc, n = G.numVertices;
	bool* visited = new bool[n];
	for (i = 0; i < n; i++)
		visited[i] = false;
	loc = G.getVertexPos(v);
	DFS(G, loc, visited);
	cout << endl;
	for (i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			DFS(G, i, visited);
			cout << endl;
		}
	}
	delete[]visited;
}

void BFS(Graph& G, const char&v, bool visited[])
{
	int w;
	int loc = G.getVertexPos(v);
	cout << G.getValue(loc);
	visited[loc] = true;
	queue<int>Q;
	Q.push(loc);
	while (!Q.empty())
	{
		loc = Q.front();
		Q.pop();
		w = G.getFirstNeighbor(loc);
		while (w != -1)
		{
			cout << "->";
			if (visited[w] == true)
				cout << '(' << G.VerticesList[w] << ')';
			if (visited[w] == false)
			{
				cout << G.getValue(w);
				visited[w] = true;
				Q.push(w);
			}
			w = G.getNextNeibghbor(loc, w);
		}
	}
}

void BFS(Graph& G, const char&v)
{
	int i, n = G.numVertices;
	bool* visited = new bool[n];
	for (i = 0; i < n; i++)
		visited[i] = false;
	BFS(G, v, visited);
	cout << endl;
	for (i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			BFS(G, G.VerticesList[i], visited);
			cout << endl;
		}
	}
	delete[]visited;
}