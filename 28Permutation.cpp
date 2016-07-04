// 28Permutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入一字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
//则打印出由字符a、b、c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba

//解题思路一：将整个过程分成以下三步考虑：
//（1）将字符串看成两部分组成：第一个字符 + 后面所有字符；
//（2）求出所有可能出现在第一个位置的字符；
//（3）固定第一个字符，求出后面字符所有可能的排列；
//为方便起见，用123来示例下。123的全排列有123、132、213、231、312、321这六种
//首先考虑213和321这二个数是如何得出的，显然这二个数123中的1分别与后面两数交换得到的
//然后可以将123的第二个数和每三个数交换得到132。同理可以根据213和321来得231和312
//因此可以知道---全排列就是从第一个数字起每个数分别与它后面的数字交换
//找到这个规律后，递归的代码就很容易写出来了：
void Permutation(char* str, char* pStr);
void Permutation(char* str) {
	if (str == NULL)
		return;
	Permutation(str, str);
}
void Permutation(char* pStr, char* pBegin) {
	if (*pBegin == '\0')
		cout << pStr << endl;
	else {
		for (char* pCh = pBegin; *pCh != '\0'; pCh++) {
			swap(*pBegin, *pCh);
			Permutation(pStr, pBegin + 1);
			swap(*pBegin, *pCh);
		}
	}
}

//解题思路二：k表示当前选取一第几个数，m表示共有多少个数
//void Permutation2(char* pStr, int k, int m) {
//	//assert(pStr);
//
//	if (k == m) {
//		static int num = 1;//局部静态变量，用来统计全排列的个数
//		cout << "第" << num++ << "个排列" << pStr << endl;
//	}
//	else {
//		for (int i = k; i <= m; i++) {
//			swap(*(pStr + k), *(pStr + i));
//			Permutation2(pStr, k + 1, m);
//			swap(*(pStr), *(pStr + i));
//		}
//	}
//}


int main()
{
	char str[] = "abc";
	Permutation(str);
	cout << endl;
	
	//Permutation2(str, 0, strlen(str) - 1);
	return 0;
}