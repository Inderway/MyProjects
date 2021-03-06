// ReversePolishNotation.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <afxwin.h>

#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

void change(char* t_s1, char*t_s2);
int priority(char t_ch);
double calculate(char* t_s);


int main()
{
	char c[100] = { "6*(6+9)" };
	char a[100] = { '\0' };
	change(c, a);
	cout << a;
	cout << endl;
	double b = 124.21512;
	char d[100] = { '\0' };
	sprintf_s(d,100,"%.3lf",b);
	cout << d;


	
	
	
	
	
	
	
	return 0;
}

int priority(char t_ch)
{
	switch (t_ch)
	{
		case '(':case '@':return 0; 
		case '+':case '-':return 1;
		case '*':case '/':return 2;
		
	}
}

void change(char* t_s1, char* t_s2)
{
	stack<char> t_S;
	int i = 0, j = 0;
	char t_ch;


	t_S.push('@');
	t_ch= t_s1[i++];
	while (t_ch != '\0')
	{

		if (t_ch == '(')
		{
			t_S.push(t_ch);

			t_ch = t_s1[i++];
		}
		else if (t_ch == ')')
		{
			while (t_S.top() != '(')

			{
				t_s2[j++] = t_S.top();
				t_s2[j++] = ' ';
				t_S.pop();
			}

			t_S.pop();
			t_ch = t_s1[i++];
		}
		else if (t_ch == '+' || t_ch == '-' || t_ch == '*' || t_ch == '/' )
		{

			while (priority(t_S.top()) >=priority(t_ch))
			{
				t_s2[j++] = t_S.top();
				t_s2[j++] = ' ';
				t_S.pop();
	
			}

			t_S.push(t_ch);
			t_ch = t_s1[i++];
		}
		else
		{
			while ((t_ch >= '0' && t_ch <= '9') || t_ch == '.')
			{
				t_s2[j++] = t_ch;
				t_ch = t_s1[i++];
			}
			t_s2[j++] = ' ';
		}
	}

	while (t_S.top() != '@')
	{
		t_s2[j++] = t_S.top();
		t_s2[j++] = ' ';
		t_S.pop();

	}
	t_s2[j++] = '\0';
}

double calculate(char* t_s)
{
	stack<char*>t_S;
	int i = 0;
	double t_result;
	char t_ch = t_s[i++];
	while (t_ch != '\0')
	{
		if (t_ch == ' ')
			t_ch = t_s[i++];



		else if(t_ch=='+'|| t_ch =='-'||t_ch=='*' || t_ch == '/')
		{
			switch (t_ch)
			{
				case '+': 
				{
					t_result = atof(t_S.top());
					t_S.pop();
					t_result += atof(t_S.top());
					t_S.pop();
					char temp[10];
					sprintf_s(temp, 10, "%.3lf", t_result);
					t_S.push(temp);
					t_ch = t_s[i++];
				};
				case '-':
				{
					t_result = atof(t_S.top());
					t_S.pop();
					t_result -= atof(t_S.top());
					t_S.pop();
					char temp[10];
					sprintf_s(temp, 10, "%.3lf", t_result);
					t_S.push(temp);
					t_ch = t_s[i++];
				};
				case '*':
				{
					t_result = atof(t_S.top());
					t_S.pop();
					t_result *= atof(t_S.top());
					t_S.pop();
					char temp[10];
					sprintf_s(temp, 10, "%.3lf", t_result);
					t_S.push(temp);
					t_ch = t_s[i++];
				};
				case '/':
				{
					t_result = atof(t_S.top());
					t_S.pop();
					t_result /= atof(t_S.top());
					t_S.pop();
					char temp[10];
					sprintf_s(temp, 10, "%.3lf", t_result);
					t_S.push(temp);
					t_ch = t_s[i++];
				};
			}
		}
		else
		{
			char t_str[10] = { '\0' };
			int j = 0;
			while (t_ch >= '0'&&t_ch <= '9' || t_ch == '.')
			{
				t_str[j++] = t_ch;
				t_ch = t_s[i++];
			}
			t_S.push(t_str);
		}
	}
	t_result = atof(t_S.top());
	return t_result;
}

