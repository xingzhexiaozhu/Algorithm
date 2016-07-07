// 32NumberOf1Between1AndN.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入一个整数n,求从1到n这n个整数的十进制表示中1出现的次数。
//例如输入12，从1到12这些整数中包含1的数字有1、10、11和12，一共出现了5次1

//解题思路一：暴力破解
//依次判断每个数字各个位上1的数量，然后从1到N累加
int NumberOf1(int num) {//计算一个数字含1的数量
	int count = 0;
	while (num != 0) {
		if (num % 10 == 1)
			count++;
		num = num / 10;
	}
	return count;
}
int NumberOf1Between1AndN(int num) {//解题
	int res = 0;
	for (int i = 1; i <= num; i++)
		res += NumberOf1(i);

	return res;
}

//解题思路二：上面的解题思路时间复杂度很大由于没有考虑数字特征
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

	//假设str是“21345”
	//numFirstDigit是数字10000--19999的第一个位中的数目
	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);

	//numOtherDigits是1345--21345除了第一位之外的数位中的数目
	int numOtherDigits = first*(length - 1)*PowerBase10(length - 2);
	//numRecursive是1--1345中的数目
	int numRecursive = Count1(str + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}
int NumberOf1Between1AndN2(int num) {
	if (num <= 0)
		return 0;
	char str[50];
	sprintf_s(str, "%d", num);//将数字转换成字符串
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

