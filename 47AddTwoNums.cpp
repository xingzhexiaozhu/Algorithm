// 47AddTwoNums.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：写一个函数，求两个整数之和，要求函数体内不得使用+、-、*、/四则运算符号

//解题思路：除了四则运算，剩下的就是位运算了。
//         第一步：不进位加法（异或运算）；
//         第二步：求进位（先与再左移1位）；
//         第三步：将上面两步的结果相加【即重复上面两步运算，至进位为0，返回】
int Add(int num1, int num2) {
	int sum, carry;
	do {
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}

int main()
{
	int num1, num2;
	while (cin >> num1 >> num2) {
		cout << Add(num1, num2) << endl;
	}

    return 0;
}

