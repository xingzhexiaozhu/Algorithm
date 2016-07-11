// 34UglyNumber.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//�������������ǰ�ֻ��������2��3��5��������������Ugly Number��.�󰴴�С�����˳��ĵ�1500��������
//����6��8���ǳ�������14��Ϊ������Ϊ����������7��ϰ�������ǰ�1������һ������

//����˼·һ������ж������Ƿ�Ϊ����������ǳ���������1���������������ж���һ��
bool isUglyNumber(int n) {//�ж�����n�Ƿ�Ϊ����
	while ((n >= 5) && (n % 5 == 0))
		n = n / 5;
	while ((n >= 3) && (n % 3 == 0))
		n = n / 3;
	while ((n >= 2) && (n % 2 == 0))
		n = n / 2;

	return (n == 1) ? true : false;
}
int GetUglyNumber(int index) {//���index������
	if (index <= 0)
		return 0;

	int count = 0;
	int num;
	for (num = 1; count != index; ++num)
		if (isUglyNumber(num))
			++count;
	return num - 1;
}

//����˼·����ǰ��ļ���Ч�ʵ�����Ϊ��ÿ���������Ƿ�Ϊ��������Ҫ��������ж�.
//���ݶ���һ������Ӧ������һ��������2��3��5�Ľ������˿��Դ���һ�����飬��������õĳ���
int Min(int num1, int num2, int num3) {
	int min = (num1 < num2) ? num1 : num2;
	min = (min < num3) ? min : num3;
	return min;
}
int GetUglyNumber2(int index) {
	if (index <= 0)
		return 0;

	int* pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *p2 = pUglyNumbers;
	int *p3 = pUglyNumbers;
	int *p5 = pUglyNumbers;

	while (nextUglyIndex < index) {
		int min = Min(*p2 * 2, *p3 * 3, *p5 * 5);
		while (*p2 * 2 < pUglyNumbers[nextUglyIndex])
			++p2;
		while (*p3 * 3 < pUglyNumbers[nextUglyIndex])
			++p3;
		while (*p5 * 5 < pUglyNumbers[nextUglyIndex])
			++p5;

		++nextUglyIndex;
	}

	int theNumber = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return theNumber;
}


int main()
{
	cout << GetUglyNumber2(150) << endl;//�õ���150������

    return 0;
}

