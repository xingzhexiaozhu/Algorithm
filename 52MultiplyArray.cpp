// 52MultiplyArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

//题意描述：给定一个数组A[0，1，……，n-1]，请构建一个数组B[0，1，……，n-1]，其中B中的元素
//B[i] = A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用乘除法

//解题思路一：最直观的解法就是先求出乘积，然后运用除法，但题目明确要求不能用除法。
//解题思路二：两层for循环
//解题思路三：
vector<int> multiply(vector<int> array) {
	int len = array.size();
	vector<int> res(len, 0);

	if (len < 1)
		return res;

	res[0] = 1;
	for (int i = 1; i < len; i++)
		res[i] = res[i - 1] * array[i - 1];

	int temp = 1;
	for (int i = len - 1; i >= 0; i--) {
		res[i] *= temp;
		temp *= array[i];
	}

	return res;
}


int main()
{
	vector<int> num = { 1,2,3,4 };
	vector<int> res = multiply(num);	

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

    return 0;
}

