// 字符串的所有组合.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
/*例如“abc”输出a,b,c,ab,ac,bc,abc*/
void DFS(char str[], char ss[], int pos, int cnt, int n)
{
	if (n == pos)
	{
		ss[cnt] = '\0';
		if (cnt != 0) printf("%s\n", ss);
		return;
	}
	ss[cnt] = str[pos];
	DFS(str, ss, pos + 1, cnt + 1, n);
	DFS(str, ss, pos + 1, cnt, n);
}
//递归
/*
int main()
{
	char str[] = "abc";
	char ss[10];
	DFS(str, ss, 0, 0, 3);
	return 0;
}*/
//非递归
int main()
{
	char str[] = "abc";
	int n = 3;
	char ss[10];
	for (int i = 1; i<(2 << n - 1); i++)
	{
		int t = i;
		int cnt = 0;
		while (t)
		{
			int x = t & 1;
			if (x) printf("%c", str[cnt]);
			t >>= 1;
			cnt++;
		}
		printf("\n");
	}
	return 0;
}

