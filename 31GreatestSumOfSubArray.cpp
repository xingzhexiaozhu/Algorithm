// 31GreatestSumOfSubArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������������������ͣ�����һ���������飬������������Ҳ�и�����������һ���������Ķ���������һ�������顣
//������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)
//��{1,-2,3,10,-4,7,2,-5}����������Ϊ��3��10��-4��7��2����ɵ�18

//����˼·һ������������ɣ���Ϊ��Ŀ������Ϊ������ͷ��ʼ�ӣ�����С��0�����ú�Ϊ0
//���浽ĿǰΪֹ���ĺ�
bool isInvalidInput = false;
int FindGreatestSumOfSubArray(int* data, int length) {
	if (data == NULL || length <= 0) {
		isInvalidInput = true;
		return 0;
	}

	isInvalidInput = false;
	int nCurSum = 0;
	int nGreatestSum = 0x80000000;
	for (int i = 0; i < length; i++) {
		if (nCurSum <= 0)
			nCurSum = data[i];
		else nCurSum += data[i];

		if (nCurSum > nGreatestSum)
			nGreatestSum = nCurSum;
	}
	
	return nGreatestSum;
}

//����˼·������̬�滮˼��
//         data[i]           (i=0��f(i-1)<=0)
//f(i)  = 
//         f(i-1) + data[i]  (i!=0��f(i-1)>0)
//����ͬ����һ�����ݹ��е�f(i)��ӦnCurSum����Max{f(i)}��ӦnGreatestSum

int main()
{
	int num[] = { 1,-2,3,10,-4,7,2,-5 };
	cout << FindGreatestSumOfSubArray(num, sizeof(num) / sizeof(num[0])) << endl;

    return 0;
}

