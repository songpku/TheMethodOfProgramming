// 最长回文子串.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


/*
HDU 3068 最长回文

参与人数：10 时间限制：2秒 空间限制：32768K
算法知识视频讲解

题目描述
给出一个只由小写英文字符a,b,c...y,z组成的字符串S,求S中最长回文串的长度.
回文就是正反读都是一样的字符串,如aba, abba等
输入描述:

输入有多组case,不超过120组,每组输入为一行小写英文字符a,b,c...y,z组成的字符串S
两组case之间由空行隔开(该空行不用处理)

字符串长度len <= 110000

输出描述:
每一行一个整数x,对应一组case,表示该组case的字符串中所包含的最长回文长度.

输入例子:
aaaa
abab

输出例子:
4
3
*/
/*中心法-超时。
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
	//i为回文中心位置
	for(i=0;i<n;i++){
		//回文为奇数
		for(j=0;(i-j>=0)&&(i+j<n);++j){
			if(s[i-j] !=s[i+j])
				break;
			c=j*2+1;
		}
		if(c>max){
			max = c ;
		}
		//回文为偶数
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
	return lenMax - 1; //减去1
}

int main(){
	while (~scanf("%s", in)){
		str[0] = '$';  //防止越界，因为$和任何字母都不匹配，所以manacher中的while会跳出
		int i = 0;
		for (; in[i] != 0; i++){
			str[i * 2 + 1] = '#';
			str[i * 2 + 2] = in[i];
		}
		str[i * 2 + 1] = '#';
		str[i * 2 + 2] = 0; //判断只字符串尾部
		printf("%d\n", manacher());
	}
}


