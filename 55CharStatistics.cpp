// 55CharStatistics.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：请实现一个函数用来找出字符流中第一个只出现一次的字符
//例如：输入“go”第一个只出现一次的字符是“g”；
//      输入“google”第一个只出现一次的字符是“l”

//解题思路一：数组模拟，数组下标表示对应的字符
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

//解题思路二：思路同上
class CharStatistics {
private:
	int occurrence[256];
	int index;
public:
	CharStatistics() :index(0) {
		for (int i = 0; i < 256; i++)
			occurrence[i] = -1;
	}
	void Insert(char ch) {
		if (occurrence[ch] == -1)
			occurrence[ch] = index;
		else if (occurrence[ch] >= 0)
			occurrence[ch] = -2;

		index++;
	}
	char FirstAppearingOnce() {
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();
		for (int i = 0; i < 256; i++) {
			if (occurrence[i] >= 0 && occurrence[i] < minIndex) {
				ch = (char)i;
				minIndex = occurrence[i];
			}
			return ch;
		}
	}
	//occurrence[i]: a char with ASCII value i
	//occurrence[i]=-1 the char has not found
	//occurrence[i]=-2 the char has been found multiple times
	//occurrence[i]>=0 the char has been found only once
};

int main()
{
	char ch[] = "abaccdeff";
	cout << firstNotRepeatChar(ch) << endl;

    return 0;
}

