// Huffman_Code.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"minHeap.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

void input(Item a[],int n);//将文件读取入a中并令其weight等于字符出现次数
void output(Item frequency[],int n);
void output(treeNode a[], int n);
void output(HuffmanTree& ht, int n);
void outputFile(HuffmanTree& ht);//编码入文件
char tranform(int n);//将character的int翻译成char
int tranform(char c);
bool compare();//比较解码与源文件（忽略大小写）
int main()
{
	const int quantity = 33;
	Item frequency[quantity];
	//初始化存储次数的数组
	for (int i = 0; i < 33; i++)
		frequency[i].weight = 0;
	for (int i = 0; i < 33; i++)
		frequency[i].character = i;

	//初始化结束

	//output(frequency, quantity);
	cout << "\n-----各字符出现频次-----\n";
	input(frequency, quantity);
	output(frequency, quantity);
	cout << "\n-----最小堆-----\n";
	minHeap heap{ frequency,quantity };
	output(heap.heap, quantity);
	
	HuffmanTree HT(heap, frequency,quantity);
	cout << "\n-----哈夫曼树-----\n第一行为结点，第二行为权值，第三行为父结点，第四，五行为左，右子树\n";
	output(HT.tree, 2*quantity-1);
	cout << "\n-----各字符编码-----\n";
	HT.coding();
	
	output(HT, quantity);
	outputFile(HT);

	HT.uncode();

	if (compare())
		cout << "\n完美契合!\n";
	else
		cout << "\n出现不同！\n";
	return 0;
}

int tranform(char c)
{
	int n=0;
	switch (c)
	{
	case 'A':n = 0; break;
	case'a':n = 0; break;
	case'B':n = 1; break;
	case'b':n = 1; break;
	case'C':n = 2; break;
	case'c':n = 2; break;
	case'D':n = 3; break;
	case'd':n = 3; break;
	case'E':n = 4; break;
	case'e':n = 4; break;
	case'F':n = 5; break;
	case'f':n = 5; break;
	case'G':n = 6; break;
	case'g':n = 6; break;
	case'H':n = 7; break;
	case'h':n = 7; break;
	case'I':n = 8; break;
	case'i':n = 8; break;
	case'J':n = 9; break;
	case'j':n = 9; break;
	case'K':n = 10; break;
	case'k':n = 10; break;
	case'L':n = 11; break;
	case'l':n = 11; break;
	case'M':n = 12; break;
	case'm':n = 12; break;
	case'N':n = 13; break;
	case'n':n = 13; break;
	case'O':n = 14; break;
	case'o':n = 14; break;
	case'P':n = 15; break;
	case'p':n = 15; break;
	case'Q':n = 16; break;
	case'q':n = 16; break;
	case'R':n = 17; break;
	case'r':n = 17; break;
	case'S':n = 18; break;
	case's':n = 18; break;
	case'T':n = 19; break;
	case't':n = 19; break;
	case'U':n = 20; break;
	case'u':n = 20; break;
	case'V':n = 21; break;
	case'v':n = 21; break;
	case'W':n = 22; break;
	case'w':n = 22; break;
	case'X':n = 23; break;
	case'x':n = 23; break;
	case'Y':n = 24; break;
	case'y':n = 24; break;
	case'Z':n = 25; break;
	case'z':n = 25; break;
	case' ':n = 26; break;
	case';':n = 27; break;
	case'.':n = 28; break;
	case',':n = 29; break;
	case'-':n = 30; break;
	case'?':n = 31; break;
	case'\'':n = 32; break;
	}
	return n;
}

void outputFile(HuffmanTree& ht)
{
	ofstream fout;
	ifstream fin;
	fout.open("code.txt");
	fin.open("text.txt");
	fin >> noskipws;
	char ch;
	while (fin >> ch)
	{
		fout << ht.code[tranform(ch)];
	}
	fin.close();
	fout.close();

}

void output(treeNode a[], int n)
{
	for (int i = 0; i <(n+1)/2; i++)
		cout << setw(5) << tranform(a[i].value.character);
	for (int i = (n+1)/2; i <n;  i++)
		cout << setw(5) << a[i].value.character;
	cout << endl<<endl;
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i].value.weight;
	cout << endl<<endl;
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i].parent;
	cout << endl<<endl;
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i].leftChild;
	cout << endl<<endl;
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i].rightChild;
}

void output(Item a[], int n)
{
	for (int i = 0; i < n;i++ )
		cout << setw(4)<<tranform(a[i].character);
	cout << endl;
	for (int i = 0; i < n;i++ )
		cout << setw(4)<<a[i].weight ;
}

void output(HuffmanTree& ht, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << tranform(ht.tree[i].value.character) << ':'
		<< ht.code[i] << endl;

}

void input(Item frequency[], int n)
{
	ifstream fin;
	fin.open("text.txt");
	char ch;
	fin >> noskipws;
	while (fin>>ch)
	{
		switch (ch)
		{
		case 'A':frequency[0].weight++; continue;
		case'a':frequency[0].weight++; continue;
		case'B':frequency[1].weight++; continue;
		case'b':frequency[1].weight++; continue;
		case'C':frequency[2].weight++; continue;
		case'c':frequency[2].weight++; continue;
		case'D':frequency[3].weight++; continue;
		case'd':frequency[3].weight++; continue;
		case'E':frequency[4].weight++; continue;
		case'e':frequency[4].weight++; continue;
		case'F':frequency[5].weight++; continue;
		case'f':frequency[5].weight++; continue;
		case'G':frequency[6].weight++; continue;
		case'g':frequency[6].weight++; continue;
		case'H':frequency[7].weight++; continue;
		case'h':frequency[7].weight++; continue;
		case'I':frequency[8].weight++; continue;
		case'i':frequency[8].weight++; continue;
		case'J':frequency[9].weight++; continue;
		case'j':frequency[9].weight++; continue;
		case'K':frequency[10].weight++; continue;
		case'k':frequency[10].weight++; continue;
		case'L':frequency[11].weight++; continue;
		case'l':frequency[11].weight++; continue;
		case'M':frequency[12].weight++; continue;
		case'm':frequency[12].weight++; continue;
		case'N':frequency[13].weight++; continue;
		case'n':frequency[13].weight++; continue;
		case'O':frequency[14].weight++; continue;
		case'o':frequency[14].weight++; continue;
		case'P':frequency[15].weight++; continue;
		case'p':frequency[15].weight++; continue;
		case'Q':frequency[16].weight++; continue;
		case'q':frequency[16].weight++; continue;
		case'R':frequency[17].weight++; continue;
		case'r':frequency[17].weight++; continue;
		case'S':frequency[18].weight++; continue;
		case's':frequency[18].weight++; continue;
		case'T':frequency[19].weight++; continue;
		case't':frequency[19].weight++; continue;
		case'U':frequency[20].weight++; continue;
		case'u':frequency[20].weight++; continue;
		case'V':frequency[21].weight++; continue;
		case'v':frequency[21].weight++; continue;
		case'W':frequency[22].weight++; continue;
		case'w':frequency[22].weight++; continue;
		case'X':frequency[23].weight++; continue;
		case'x':frequency[23].weight++; continue;
		case'Y':frequency[24].weight++; continue;
		case'y':frequency[24].weight++; continue;
		case'Z':frequency[25].weight++; continue;
		case'z':frequency[25].weight++; continue;
		case' ':frequency[26].weight++; continue;
		case';':frequency[27].weight++; continue;
		case'.':frequency[28].weight++; continue;
		case',':frequency[29].weight++; continue;
		case'-':frequency[30].weight++; continue;
		case'?':frequency[31].weight++; continue;
		case'\'':frequency[32].weight++; continue;
		}
	}
	fin.close();
}

char tranform(int n)
{
	char ch;
	switch (n)
	{
	case 0:ch = 'a'; break;
	case 1:ch = 'b'; break;
	case 2:ch = 'c'; break;
	case 3:ch = 'd'; break;
	case 4:ch = 'e'; break;
	case 5:ch = 'f'; break;
	case 6:ch = 'g'; break;
	case 7:ch = 'h'; break;
	case 8:ch = 'i'; break;
	case 9:ch = 'j'; break; 
	case 10:ch = 'k'; break;
	case 11:ch = 'l'; break;
	case 12:ch = 'm'; break;
	case 13:ch = 'n'; break;
	case 14:ch = 'o'; break;
	case 15:ch = 'p'; break;
	case 16:ch = 'q'; break;
	case 17:ch = 'r'; break;
	case 18:ch = 's'; break;
	case 19:ch = 't'; break;
	case 20:ch = 'u'; break;
	case 21:ch = 'v'; break;
	case 22:ch = 'w'; break;
	case 23:ch = 'x'; break;
	case 24:ch = 'y'; break;
	case 25:ch = 'z'; break;
	case 26:ch = ' '; break;
	case 27:ch = ';'; break;
	case 28:ch = '.'; break;
	case 29:ch = ','; break;
	case 30:ch = '-'; break;
	case 31:ch = '?'; break;
	case 32:ch = '\''; break;

	}
	return ch;
}

bool compare()
{
	cout << "\n-----比较解码文件与原文件是否一致（忽略大小写）-----\n";
	ifstream fin1;
	ifstream fin2;
	fin1.open("text.txt");
	fin2.open("uncode.txt");
	char ch1, ch2;
	while (fin1 >> ch1 && fin2 >> ch2)
	{
		if (ch1 >= 'A'&&ch1 <= 'Z')
			ch1 =char( ch1 + 32);
		if (ch1 != ch2)
			return 0;
	}
	return 1;
}