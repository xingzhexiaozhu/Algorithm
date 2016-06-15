// 9Fibonacci.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//������������������n�����쳲��������еĵ�n��

//�ⷨһ������ݹ���ã�Ч�ʵͣ��н϶��ظ����㣩
long long Fibonacci(unsigned int n) {
	if (n == 0 || n == 1)
		return n;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//�ⷨ���������м����������
long long Fibonacci1(unsigned int n) {
	int result[] = { 0,1 };
	if (n < 2)
		return result[n];

	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN = 0;
	for (unsigned int i = 2; i <= n; i++) {
		fibN = fibNMinusOne + fibNMinusTwo;
		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}

	return fibN;
}

int main()
{
	int n;
	while (cin >> n) {
		cout << Fibonacci(n) <<"\t"<< Fibonacci1(n) <<endl;
	}

    return 0;
}

