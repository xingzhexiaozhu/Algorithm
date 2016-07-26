// 38GetCountOfNum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//����������ͳ��һ�����������������г��ֵĴ���������������������{1,2,3,3,3,3,4,5}������3������3����������г�����4�Σ�������4

//����˼·һ��˳��ɨ�裬ʱ�临�Ӷ�ΪO(n)
//����˼·�������ö��ֲ��ң��ֱ��ҵ���һ������Ҫ������ֺ����һ������Ҫ������֣����ɵõ�������
int GetFirstNumIndex(int* data, int len, int k, int start, int end) {
	if (start > end)
		return -1;
	
	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];
	if (middleData == k) {
		if (middleIndex > 0 && data[middleIndex - 1] != k || middleIndex == 0)
			return middleIndex;
		else end = middleIndex-1;
	}
	else if (middleData > k)
		end = middleIndex - 1;
	else start = middleIndex + 1;

	return GetFirstNumIndex(data, len, k, start, end);
}
int GetLastNumIndex(int* data, int len, int k, int start, int end) {
	if (start > end)
		return -1;

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if (middleData == k) {
		if (middleIndex < len - 1 && data[middleIndex + 1] != k || middleIndex == len - 1)
			return middleIndex;
		else start = middleIndex + 1;
	}
	else if (middleData < k)
		start = middleIndex + 1;
	else end = middleIndex - 1;

	return GetLastNumIndex(data, len, k, start, end);
}
int getCountOfNum(int* data, int length, int key) {
	if (data == NULL || length <= 0)
		return 0;

	int firstNumIndex = GetFirstNumIndex(data, length, key, 0, length-1);//Ѱ�ҵ�һ��key
	int lastNumIndex = GetLastNumIndex(data, length, key, 0, length-1);  //Ѱ�����һ��key
	int count = 0;
	if (firstNumIndex > -1 && lastNumIndex > -1)
		count = lastNumIndex - firstNumIndex + 1;
	return count;
}

int main()
{
	int data[] = { 1,2,3,3,3,3,4,5 };
	cout << getCountOfNum(data, sizeof(data) / sizeof(data[0]), 3) << endl;

    return 0;
}

