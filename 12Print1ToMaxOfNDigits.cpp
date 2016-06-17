// 12Print1ToMaxOfNDigits.cpp : 定义控制台应用程序的入口点。
//

//题意描述：输入数字n，按顺序打印从1到最大的n位十进制数。比如输入2，则打印1,2,3...999

#include "stdafx.h"
#include<iostream>
using namespace std;

//解题思路一：得到最大数的上限，然后再从1开始循环打印
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

//解题思路二：考虑到大数问题。就是当输入的n较大是时，int已满足不了需求，甚至Long都会溢出
//大数问题一般采用字符串来表示，即字符的每一位都是'0'-'9'的字符。因此n位数字需要(n+1)长度
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
//	memset(num, '0', n);//初始化为全0
//	num[n] = '\n';
//
//	while (!Increment(num))
//		PrintNum(num);
//
//	delete[] num;
//}

//解题思路三：全排列
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

