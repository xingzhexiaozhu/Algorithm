// 11PowerOfNum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;

//题意描述：实现函数double Power(double base, int exponent)，求base的exponent次方，
//不得使用库函数，同时不需要考虑大数问题

//解法一：直接按照次方数来计算
//double Power(double base, int exponent) {
//	double result = 1;
//	for (int i = 0; i < exponent; ++i)
//		result *= base;
//
//	return result;
//}


//解法二：上述解法过于简单，没有考虑exp为负数或0的情况，所以程序鲁棒性不够
//全面但不够高效的做法
//double PowerWithUnsignedExponent(double base, int exp) {
//	double result = 1.0;
//	for (int i = 0; i < exp; i++)
//		result *= base;
//	return result;
//}
//
//bool equal(double num1, double num2) {
//	if (abs(num1 - num2) < 0.0000001)
//		return true;
//	else return false;
//}
//
//bool g_InvalidInput = false;
//double Power(double base, int exponent) {
//	g_InvalidInput = false;
//	if (equal(base, 0.0) && exponent < 0) {
//		g_InvalidInput = true;
//		return 0.0;
//	}
//
//	unsigned int absExponent = (unsigned int)(exponent);
//	if (exponent < 0)
//		absExponent = (unsigned int)(-exponent);
//
//	double result = PowerWithUnsignedExponent(base, absExponent);
//	if (exponent < 0)
//		result = 1.0 / result;
//
//	return result;
//}

//解法三：
bool equal(double num1, double num2) {
	if (abs(num1 - num2) < 0.0000001)
		return true;
	else return false;
}


double PowerWithUnsignedExponent(double base, int exp) {
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;

	double result = PowerWithUnsignedExponent(base, exp >> 1);
	result *= result;
	if ((exp & 0x1) == 1)
		result *= base;
	return result;
}

bool g_InvalidInput = false;
double Power(double base, int exponent) {
	g_InvalidInput = false;
	if (equal(base, 0.0) && exponent < 0) {
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}

int main()
{
	double base;
	int exp;
	while (cin >> base >> exp) {
		cout << Power(base, exp) << endl;
	}

    return 0;
}

