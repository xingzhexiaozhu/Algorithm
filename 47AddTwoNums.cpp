// 47AddTwoNums.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//����������дһ������������������֮�ͣ�Ҫ�������ڲ���ʹ��+��-��*��/�����������

//����˼·�������������㣬ʣ�µľ���λ�����ˡ�
//         ��һ��������λ�ӷ���������㣩��
//         �ڶ��������λ������������1λ����
//         �������������������Ľ����ӡ����ظ������������㣬����λΪ0�����ء�
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

