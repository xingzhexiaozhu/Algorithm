// 42LeftRotateString.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ���ַ��������ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
//���������ַ�����abcdefg��������2���ú�����������ת2λ�õ������cdefgab��

//����˼·�����ַ����ֳ������֣�����Ŀ������Ϊ����ǰ2���ַ�Ϊ��һ���֣�����Ϊ�ڶ����֡��ȷֱ�ת�����Ӳ��֣������巭ת
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

			Reverse(pFirstStart, pFirstEnd);//��ת�ַ�����ǰn���ַ�
			Reverse(pSecondStart, pSecondEnd);//��ת�ַ����ĺ����ַ�
			Reverse(pFirstStart, pSecondEnd);//���巭ת
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

