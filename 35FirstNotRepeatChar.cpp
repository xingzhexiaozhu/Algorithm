// 35FirstNotRepeatChar.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//�������������ַ������ҳ���һ��ֻ����һ�ε��ַ���������"abaccdeff"�������'b'

//����˼·һ��������ģ��
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

