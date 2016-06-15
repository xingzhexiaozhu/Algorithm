// 9Fibonacci.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入数字n，输出斐波那契数列的第n项

//解法一：经典递归调用（效率低，有较多重复计算）
long long Fibonacci(unsigned int n) {
	if (n == 0 || n == 1)
		return n;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//解法二：保存中间计算结果即可
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

