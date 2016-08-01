// 42LeftRotateString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：给定一个字符串，将字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
//比如输入字符串“abcdefg”和数字2，该函数返回左旋转2位得到结果“cdefgab”

//解题思路：将字符串分成两部分，以题目的例子为例，前2个字符为第一部分，其余为第二部分。先分别翻转两个子部分，再整体翻转
void Reverse(char* pBegin, char* pEnd) {
	if (pBegin == NULL || pEnd == NULL)
		return;
	while (pBegin < pEnd) {
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}
char* LeftRotateString(char* pStr, int n) {
	if (pStr != NULL) {
		int nLength = static_cast<int>(strlen(pStr));
		if (nLength > 0 && n > 0 && n < nLength) {
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + nLength - 1;

			Reverse(pFirstStart, pFirstEnd);//翻转字符串的前n个字符
			Reverse(pSecondStart, pSecondEnd);//翻转字符串的后面字符
			Reverse(pFirstStart, pSecondEnd);//整体翻转
		}
	}
	return pStr;
}

int main()
{
	char str[] = "abcdefg";
	cout << LeftRotateString(str, 2) << endl;

    return 0;
}

