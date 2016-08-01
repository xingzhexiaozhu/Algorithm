// 42ReverseSentence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//题意描述：输入一个英文句子，翻转句子中单词的顺序，但单词内部的字符顺序不变。为简单起见，标点符号和普通字母一样处理。
//例如：输入“I am a student.”，输出“student. a am I”

//解题思路：两次翻转。第一次翻转整个句子，第二次翻转里面的每个单词
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
char* ReverseSentence(char* pData) {
	if (pData == NULL)
		return NULL;

	char* pBegin = pData;
	char* pEnd = pData;
	while (*pEnd != '\0')
		pEnd++;
	pEnd--;

	//翻转整个句子
	Reverse(pBegin, pEnd);

	//翻转句子中的每个单词
	pBegin = pEnd = pData;
	while (*pBegin != '\0') {
		if (*pBegin == ' ') {
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0') {
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else {
			pEnd++;
		}
	}
	return pData;	
}


int main()
{
	char str[] = "I am a student.";
	
	cout << ReverseSentence(str) << endl;	

    return 0;
}

