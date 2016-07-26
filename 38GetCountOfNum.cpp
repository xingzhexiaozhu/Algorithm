// 38GetCountOfNum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：统计一个数字在排序数组中出现的次数。例如输入排序数组{1,2,3,3,3,3,4,5}和数字3，由于3在这个数组中出现了4次，因此输出4

//解题思路一：顺序扫描，时间复杂度为O(n)
//解题思路二：利用二分查找，分别找到第一个符合要求的数字和最后一个符合要求的数字，即可得到所求结果
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

	int firstNumIndex = GetFirstNumIndex(data, length, key, 0, length-1);//寻找第一个key
	int lastNumIndex = GetLastNumIndex(data, length, key, 0, length-1);  //寻找最后一个key
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

