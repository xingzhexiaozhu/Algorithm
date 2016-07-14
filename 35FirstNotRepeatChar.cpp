// 35FirstNotRepeatChar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出'b'

//解题思路一：用数组模拟
char firstNotRepeatChar(char* pStr) {
	if (pStr == NULL)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (int i = 0; i < tableSize; i++)
		hashTable[i] = 0;

	char *p = pStr;
	while (*p != '\0')
		hashTable[*(p++)]++;

	p = pStr;
	while (*p != '\0') {
		if (hashTable[*p] == 1)
			return *p;
		p++;
	}
	return '\0';
}

int main()
{
	char ch[] = "abaccdeff";
	cout << firstNotRepeatChar(ch) << endl;

    return 0;
}

