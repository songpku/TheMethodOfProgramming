// ������Ӵ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


/*
HDU 3068 �����

����������10 ʱ�����ƣ�2�� �ռ����ƣ�32768K
�㷨֪ʶ��Ƶ����

��Ŀ����
����һ��ֻ��СдӢ���ַ�a,b,c...y,z��ɵ��ַ���S,��S������Ĵ��ĳ���.
���ľ�������������һ�����ַ���,��aba, abba��
��������:

�����ж���case,������120��,ÿ������Ϊһ��СдӢ���ַ�a,b,c...y,z��ɵ��ַ���S
����case֮���ɿ��и���(�ÿ��в��ô���)

�ַ�������len <= 110000

�������:
ÿһ��һ������x,��Ӧһ��case,��ʾ����case���ַ�����������������ĳ���.

��������:
aaaa
abab

�������:
4
3
*/
/*���ķ�-��ʱ��
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int longestPalindrome(const char *s,int n){
	int i,j,max,c;
	if(s==0 || n<1){
		return 0;
	}
	max =0;
	//iΪ��������λ��
	for(i=0;i<n;i++){
		//����Ϊ����
		for(j=0;(i-j>=0)&&(i+j<n);++j){
			if(s[i-j] !=s[i+j])
				break;
			c=j*2+1;
		}
		if(c>max){
			max = c ;
		}
		//����Ϊż��
		for(j=0;(i-j>=0)&&(i+j+1<n);++j){
			if(s[i-j] != s[i+j+1]){
				break;
			}
			c=j*2+2;
		}
		if(c>max){
			max = c;
		}
	}
	return max;
}
int main(){
	string in;
	while (cin >> in){
		int ret = 0;
		int size = in.size();
		for (int i = 0; i<size; i++){
			int j = i, k = i, cnt = 1;
			while ((--j)>=0 && ++k<size){
				if (in[j] != in[k])
					break;
				cnt += 2;
			}
			ret = max(ret, cnt);
		}
		cout << ret << endl;
	}

}
*/

#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAXLEN = 221000;
int len[MAXLEN];
char str[MAXLEN];
char in[111000];

int manacher(){
	int p = 0, po = 0, lenMax = 0, i;
	for (i = 1; str[i] != 0; i++){
		if (i<p){
			len[i] = min(len[2 * po - i], p - i);
		}
		else{
			len[i] = 0;
		}
		while (str[i + len[i]] == str[i - len[i]]){
			++len[i];
		}
		if (len[i] + i>p){
			p = len[i] + i;
			po = i;
		}
		if (lenMax<len[i])
			lenMax = len[i];

	}
	return lenMax - 1; //��ȥ1
}

int main(){
	while (~scanf("%s", in)){
		str[0] = '$';  //��ֹԽ�磬��Ϊ$���κ���ĸ����ƥ�䣬����manacher�е�while������
		int i = 0;
		for (; in[i] != 0; i++){
			str[i * 2 + 1] = '#';
			str[i * 2 + 2] = in[i];
		}
		str[i * 2 + 1] = '#';
		str[i * 2 + 2] = 0; //�ж�ֻ�ַ���β��
		printf("%d\n", manacher());
	}
}


