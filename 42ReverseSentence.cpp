// 42ReverseSentence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//��������������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵������ڲ����ַ�˳�򲻱䡣Ϊ������������ź���ͨ��ĸһ������
//���磺���롰I am a student.���������student. a am I��

//����˼·�����η�ת����һ�η�ת�������ӣ��ڶ��η�ת�����ÿ������
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

	//��ת��������
	Reverse(pBegin, pEnd);

	//��ת�����е�ÿ������
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

