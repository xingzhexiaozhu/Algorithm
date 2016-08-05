// 45LastNumberInCircle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<list>
using namespace std;

//题意描述：0，1，……，n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里面删除第m个数字。求这个圆圈中最后剩下的一个数字

//解题思路一：模拟一个环，然后每次删除第m个数字，暴力破解
int LastRemaining(int n, int m) {
	if (n < 1 || m < 1)
		return -1;
		
	list<int> num;
	for (int i = 0; i < n; i++)
		num.push_back(i);

	list<int>::iterator cur = num.begin();
	while (num.size() > 1) {//不断删除list中第m个数
		for (int i = 1; i < m; i++) {//每次循环找到第n个数
			cur++;
			if (cur == num.end())
				cur = num.begin();
		}

		list<int>::iterator next = ++cur;
		if (next == num.end())
			next = num.begin();

		--cur;
		num.erase(cur);//删除该数字
		cur = next;
	}
	return *(cur);
}

//解题思路二：上述思路可行，但明显时间复杂度O(mn)。因此还是希望找找删除数字有什么规律。
//递归公式：         0  ,                 n = 1
//         f(n,m)= {
//                   [f(n-1,m)+m] % n ,   n > 1
int LastRemaining2(int n, int m) {
	if (n < 1 || m < 1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; i++)
		last = (last + m) % i;
	return last;
}

int main()
{
	int n, k;
	while (cin >> n >> k) {
		cout << LastRemaining(n, k) << " " << LastRemaining2(n, k) << endl;
	}

    return 0;
} 

