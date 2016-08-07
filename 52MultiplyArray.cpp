// 52MultiplyArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

//��������������һ������A[0��1��������n-1]���빹��һ������B[0��1��������n-1]������B�е�Ԫ��
//B[i] = A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó˳���

//����˼·һ����ֱ�۵Ľⷨ����������˻���Ȼ�����ó���������Ŀ��ȷҪ�����ó�����
//����˼·��������forѭ��
//����˼·����
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

