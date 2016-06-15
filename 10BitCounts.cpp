// 10BitCounts.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ����������������ֶ�������ʽ��1�ĸ���

//����˼·һ����������ÿ������һλ����1�ĸ���
//int NumberOf1(int n) {
//	int count = 0;
//	while (n) {
//		if (n & 1)
//			count++;
//		n = n >> 1;
//	}
//	return count;
//}

//����˼·������������˼·�������ڸ�����ʽ��������ָ�����������ѭ��
//�޸�Ϊ�����ƶ����λ���ӵ͵���λ�жϸ���λ�Ƿ�Ϊ1
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

//����˼·�������Ľⷨ������˸���������ѭ������ʽ����ѭ���Ĵ����������������Ƶ�λ��
//��һ��������ȥ1�ٺ�ԭ�������������㣬��Ѹ��������ұ�һ��1���0����ôһ�������Ķ����Ʊ�ʾ��
//�ж��ٸ�1���Ϳ��Խ��ж��ٴ������Ĳ���
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

