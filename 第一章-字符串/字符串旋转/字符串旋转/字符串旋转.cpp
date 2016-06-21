// 字符串旋转.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

/*
字符串的旋转

参与人数：2706 时间限制：3秒 空间限制：32768K
本题知识点： 字符串 编程基础
算法知识视频讲解

题目描述

对于一个字符串，和字符串中的某一位置，请设计一个算法，将包括i位置在内的左侧部分移动到右边，将右侧部分移动到左边。

给定字符串A和它的长度n以及特定位置p，请返回旋转后的结果。
测试样例：

"ABCDEFGH",8,4

返回："FGHABCDE"


*/
void swap(string &A, int l, int r){
	if (l >= r)
		return;
	char tmp = A[l];
	A[l] = A[r];
	A[r] = tmp;
}
string rotateString(string A, int n, int p) {  //三次反转
	for (int i = 0; i <= p/2; i++){
		swap(A, i, p - i);
	}
	cout << A << endl;
	for (int i = 1; i <= (n - p)/2; i++){
		swap(A, i + p, n - i);
	}
	cout << A << endl;
	for (int i = 0; i<n/2; i++){
		swap(A, i, n - i - 1);
	}
	return A;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << rotateString("ABCDEFGH", 8, 4);
	return 0;
}

