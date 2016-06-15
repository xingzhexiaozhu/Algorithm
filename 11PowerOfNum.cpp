// 11PowerOfNum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
using namespace std;

//����������ʵ�ֺ���double Power(double base, int exponent)����base��exponent�η���
//����ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ�������

//�ⷨһ��ֱ�Ӱ��մη���������
//double Power(double base, int exponent) {
//	double result = 1;
//	for (int i = 0; i < exponent; ++i)
//		result *= base;
//
//	return result;
//}


//�ⷨ���������ⷨ���ڼ򵥣�û�п���expΪ������0����������Գ���³���Բ���
//ȫ�浫������Ч������
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

//�ⷨ����
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

