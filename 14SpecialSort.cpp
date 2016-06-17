// 14SpecialSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ�����飬ʵ��һ��������������������������ʹ����������λ�������ǰ�棬����ż��λ������ĺ���

//����˼·һ��������ŵ�˼�룬ʹ������ָ�룬ָ��1ָ�������һ��Ԫ�أ���ǰ����������ָ��2ָ���������һ��Ԫ�أ��Ӻ���ǰ��������
//��ָ��1ָ��Ԫ��Ϊż��ָ��2ָ��Ԫ��Ϊ��ʱ������Ԫ�أ�����ָ������ʱ��������
void ReorderOddEven(int* pData, int length) {
	if (pData == NULL || length == 0)
		return;
	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd) {
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
			pBegin++;
		while (pEnd > pBegin && (*pEnd & 0x1) == 0)
			pEnd--;

		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

//����˼·����������չ���������Թ������ǰ������������������Ϊǰ�������֡������Ƿ��ܱ�3������Ϊǰ���������أ�
//������������Ƿ���ֻ�Ǻ���������ѭ�����жϱ�׼�����˱仯�������ط���ȫһ���������������ǰ�������������������֣�
//һ�������ж�����Ӧ���������ǰ�벿�ֻ��Ǻ�벿�֣����ǲ������Ĳ�������
void Reorder(int* pData, int length, bool(*func)(int)) {
	if (pData == NULL || length == 0)
		return;

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd) {
		while (pBegin < pEnd && !func(*pBegin))
			pBegin++;
		while (pEnd > pBegin && func(*pEnd))
			pEnd--;

		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n) {
	return (n & 0x1) == 0;
}

void ReorderOddEven1(int* pData, int length) {
	Reorder(pData, length, isEven);
}

int main()
{
	int num[] = { 1,2,3,4,5 };
	ReorderOddEven1(num, 5);
	for (int i = 0; i < 5; i++)
		cout << num[i] << " ";
	cout << endl;

    return 0;
}

