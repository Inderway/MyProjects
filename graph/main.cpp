// Graph.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Graph.h"

int main()
{
	ifstream fin1;
	ifstream fin2;
	fin1.open("vertex.txt");
	fin2.open("edge.txt");
	Graph G;
	write(fin1, fin2, G);
	output(G);

	
	
	fin1.close();
	fin2.close();
	fin1.open("vertex.txt");
	fin2.open("edge.txt");
	oriented_Graph oG;
	write(fin1, fin2, oG);
	cout << endl;
	cout << "----深度遍历----\n";
	DFS(G, 'c');
	cout << endl;
	cout << "----广度遍历----\n";
	BFS(G,'c');
	cout << "\n\n有向图：\n";
	output(oG);
	cout << "\n----深度遍历----\n";
	DFS(oG, 'c');
	cout << endl;
	cout << "----广度遍历----\n";
	BFS(oG, 'c');
	fin1.close();
	fin2.close();
	return 0;
}

