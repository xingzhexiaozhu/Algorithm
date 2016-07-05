// 31GreatestSumOfSubArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：（连续子数组的最大和）输入一个整形数组，数组里有正数也有负数。数组中一个或连续的多个整数组成一个子数组。
//求所有子数组的和的最大值，要求时间复杂度为O(n)
//如{1,-2,3,10,-4,7,2,-5}，返回最大和为｛3，10，-4，7，2｝组成的18

//解题思路一：分析数组规律，以为题目中例子为例，从头开始加，当和小于0则重置和为0
//保存到目前为止最大的和
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

//解题思路二：动态规划思想
//         data[i]           (i=0或f(i-1)<=0)
//f(i)  = 
//         f(i-1) + data[i]  (i!=0或f(i-1)>0)
//代码同上面一样，递归中的f(i)对应nCurSum，而Max{f(i)}对应nGreatestSum

int main()
{
	int num[] = { 1,-2,3,10,-4,7,2,-5 };
	cout << FindGreatestSumOfSubArray(num, sizeof(num) / sizeof(num[0])) << endl;

    return 0;
}

