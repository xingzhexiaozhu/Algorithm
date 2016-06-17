// 12Print1ToMaxOfNDigits.cpp : �������̨Ӧ�ó������ڵ㡣
//

//������������������n����˳���ӡ��1������nλʮ����������������2�����ӡ1,2,3...999

#include "stdafx.h"
#include<iostream>
using namespace std;

//����˼·һ���õ�����������ޣ�Ȼ���ٴ�1��ʼѭ����ӡ
//void Print1ToMaxOfNDigits(int n) {
//	int num = 1;
//	int i = 0;
//	while (i < n) {
//		num *= 10;
//		++i;
//	}
//	
//	for (int i = 0; i < num; i++)
//		cout << i << "\t";
//	cout << endl;
//}

//����˼·�������ǵ��������⡣���ǵ������n�ϴ���ʱ��int�����㲻����������Long�������
//��������һ������ַ�������ʾ�����ַ���ÿһλ����'0'-'9'���ַ������nλ������Ҫ(n+1)����
//bool Increment(char * num) {
//	bool isOverFlow = false;
//	int nTakeOver = 0;
//	int nLength = strlen(num);
//	for (int i = nLength - 1; i >= 0; i--) {
//		int nSum = num[i] - '0' + nTakeOver;
//		if (i == nLength - 1)
//			nSum++;
//		if (nSum >= 10) {
//			if (i == 0)
//				isOverFlow = true;
//			else {
//				nSum -= 10;
//				nTakeOver = 1;
//				num[i] = '0' + nSum;
//			}
//		}
//		else {
//			num[i] = '0' + nSum;
//			break;
//		}
//	}
//	return isOverFlow;
//}
//void PrintNum(char* num) {
//	bool isBeginning0 = true;
//	int nLength = strlen(num);
//	for (int i = 0; i < nLength; i++) {
//		if (isBeginning0 && num[i] != '0')
//			isBeginning0 = false;
//		if (!isBeginning0)
//			cout << num[i];
//	}
//	cout << endl;
//}
//void Print1ToMaxOfNDigits(int n) {
//	if (n <= 0)
//		return;
//	char *num = new char[n + 1];
//	memset(num, '0', n);//��ʼ��Ϊȫ0
//	num[n] = '\n';
//
//	while (!Increment(num))
//		PrintNum(num);
//
//	delete[] num;
//}

//����˼·����ȫ����
void PrintNum(char* num) {
	bool isBeginning0 = true;
	int nLength = strlen(num);
	for (int i = 0; i < nLength; i++) {
		if (isBeginning0 && num[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
			cout << num[i];
	}
	cout << endl;
}
void Print1ToMaxOfNDigitsRecursively(char* num, int length, int index) {
	if (index == length - 1) {
		PrintNum(num);
		return;
	}
	for (int i = 0; i < 10; i++) {
		num[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(num, length, index + 1);
	}
}
void Print1ToMaxOfNDigits(int n) {
	if (n <= 0)
		return;
	char* num = new char[n + 1];
	num[n] = '\n';
	for (int i = 0; i < 10; i++) {
		num[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(num, n, 0);
	}
	delete[]num;
}

int main()
{
	int n;
	while (cin >> n) {
		Print1ToMaxOfNDigits(n);
	}
    return 0;
}

