// 32NumberOf1Between1AndN.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ������n,���1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�����
//��������12����1��12��Щ�����а���1��������1��10��11��12��һ��������5��1

//����˼·һ�������ƽ�
//�����ж�ÿ�����ָ���λ��1��������Ȼ���1��N�ۼ�
int NumberOf1(int num) {//����һ�����ֺ�1������
	int count = 0;
	while (num != 0) {
		if (num % 10 == 1)
			count++;
		num = num / 10;
	}
	return count;
}
int NumberOf1Between1AndN(int num) {//����
	int res = 0;
	for (int i = 1; i <= num; i++)
		res += NumberOf1(i);

	return res;
}

//����˼·��������Ľ���˼·ʱ�临�ӶȺܴ�����û�п�����������
//
int PowerBase10(unsigned int n) {
	int res = 1;
	for (unsigned int i = 0; i < n; i++)
		res *= 10;
	return res;
}
int Count1(const char* str) {
	if (!str || *str<'0' || *str>'9' || *str == '\0')
		return 0;
	
	int first = *str - '0';
	unsigned int length = static_cast<unsigned int>(strlen(str));

	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first > 0)
		return 1;

	//����str�ǡ�21345��
	//numFirstDigit������10000--19999�ĵ�һ��λ�е���Ŀ
	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);

	//numOtherDigits��1345--21345���˵�һλ֮�����λ�е���Ŀ
	int numOtherDigits = first*(length - 1)*PowerBase10(length - 2);
	//numRecursive��1--1345�е���Ŀ
	int numRecursive = Count1(str + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}
int NumberOf1Between1AndN2(int num) {
	if (num <= 0)
		return 0;
	char str[50];
	sprintf_s(str, "%d", num);//������ת�����ַ���
	return Count1(str);
}

int main()
{
	int n;
	while (cin >> n) {
		cout << NumberOf1Between1AndN(n) << "\t" << NumberOf1Between1AndN2(n) << endl;
	}		

    return 0;
}

