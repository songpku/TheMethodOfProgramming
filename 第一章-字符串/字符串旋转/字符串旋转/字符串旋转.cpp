// �ַ�����ת.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

/*
�ַ�������ת

����������2706 ʱ�����ƣ�3�� �ռ����ƣ�32768K
����֪ʶ�㣺 �ַ��� ��̻���
�㷨֪ʶ��Ƶ����

��Ŀ����

����һ���ַ��������ַ����е�ĳһλ�ã������һ���㷨��������iλ�����ڵ���ಿ���ƶ����ұߣ����Ҳಿ���ƶ�����ߡ�

�����ַ���A�����ĳ���n�Լ��ض�λ��p���뷵����ת��Ľ����
����������

"ABCDEFGH",8,4

���أ�"FGHABCDE"


*/
void swap(string &A, int l, int r){
	if (l >= r)
		return;
	char tmp = A[l];
	A[l] = A[r];
	A[r] = tmp;
}
string rotateString(string A, int n, int p) {  //���η�ת
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

