// �ַ�����ȫ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*
�ַ���������

����������3002 ʱ�����ƣ�1�� �ռ����ƣ�32768K
����֪ʶ�㣺 �ַ���
�㷨֪ʶ��Ƶ����

��Ŀ����
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba�� ����밴��ĸ˳�������
��������:

����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��
*/
void solve(vector<string> &vec, string &str, int from, int to){
	//if(to <=1)
	//   return;
	if (from == to){
		if (find(vec.begin(), vec.end(), str) == vec.end())    //�ַ������ظ�����aa
			vec.push_back(str);
	}
	else{
		for (int j = from; j <= to; j++){
			swap(str[from], str[j]);
			solve(vec, str, from + 1, to);
			swap(str[from], str[j]);
		}
	}
}
vector<string> Permutation(string str) {
	vector<string> ret;
	solve(ret, str, 0, str.size() - 1);
	sort(ret.begin(), ret.end());   //�ֵ���
	return ret;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

