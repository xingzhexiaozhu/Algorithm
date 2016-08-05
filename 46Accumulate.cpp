// 46Accumulate.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//������������1+2+����+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C��

//����˼·һ���ݹ鰡��f(n) = n + f(n-1)����ѽ����������if������
int Sum(int n) {
	if (n == 1) 
		return 1;
	return n + Sum(n - 1);
}
//ͬ���ĵݹ飬����if�жϡ��д��⡿����n��Ϊ0ʱ���ú���B::Sum����n����0ʱ���ú���A::Sum
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

//����˼·�����ú���ָ�����
typedef int(*fun)(int);
int Sum3_boundary(int n) {
	return 0;
}
int Sum3(int n) {
	static fun f[2] = { Sum3_boundary, Sum3 };
	return n + f[!!n](n - 1);
}

//����˼·��������ģ�����
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

