// 46Accumulate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：求1+2+……+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）

//解题思路一：递归啊，f(n) = n + f(n-1)。哎呀，好像用了if。。。
int Sum(int n) {
	if (n == 1) 
		return 1;
	return n + Sum(n - 1);
}
//同样的递归，不用if判断【有创意】。当n不为0时调用函数B::Sum，当n等于0时调用函数A::Sum
//class A;
//A* array[2];
//class A {
//public:
//	virtual int Sum(int n) {
//		return 0;
//	}
//};
//class B : public A {
//public:
//	virtual int Sum(int n) {
//		return array[!!n]->Sum(n - 1) + n;
//	}
//};
//int Sum2(int n) {
//	A a;
//	B b;
//	array[0] = &a;
//	array[1] = &b;
//}

//解题思路二：用函数指针求解
typedef int(*fun)(int);
int Sum3_boundary(int n) {
	return 0;
}
int Sum3(int n) {
	static fun f[2] = { Sum3_boundary, Sum3 };
	return n + f[!!n](n - 1);
}

//解题思路三：利用模板求解
template <unsigned int n> struct Sum4
{
	enum Value{N = Sum4_solution<n-1>::N + n};
};
template<> struct Sum4<1>
{
	enum Value{N = 1};
};

int main()
{
	int n;
	while (cin >> n) {
		cout << Sum(n) << "\t" << Sum3(n) << endl;
	}

    return 0;
}

