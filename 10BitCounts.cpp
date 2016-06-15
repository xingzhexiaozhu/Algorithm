// 10BitCounts.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入一个整数，输出该数字二进制形式中1的个数

//解题思路一：将该数字每次右移一位，计1的个数
//int NumberOf1(int n) {
//	int count = 0;
//	while (n) {
//		if (n & 1)
//			count++;
//		n = n >> 1;
//	}
//	return count;
//}

//解题思路二：上述解题思路不适用于负数形式，如果出现负数则会出现死循环
//修改为依次移动标记位，从低到高位判断各个位是否为1
//int NumberOf1(int n) {
//	int count = 0;
//	unsigned int flag = 1;
//	while (flag) {
//		if (n&flag)
//			count++;
//		flag = flag << 1;
//	}
//	return count;
//}

//解题思路三：二的解法虽避免了负数出现死循环的形式，但循环的次数等于整数二进制的位数
//把一个整数减去1再和原来整数做与运算，会把该整数最右边一个1变成0，那么一个整数的二进制表示中
//有多少个1，就可以进行多少次这样的操作
int NumberOf1(int n) {
	int count = 0;
	while (n) {
		count++;
		n = (n - 1)&n;
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n) {
		cout << NumberOf1(n) << endl;
	}
    return 0;
}

