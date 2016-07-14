// 36InversePairs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//题意描述：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组，求出这个数组中的逆序对的总数

//解题思路一：每扫描到一个数字就逐个比较该数字和它后面的数字的大小，如果比后面的数字小则这两个数字就组成一个逆序对
//这样n个数字的算法时间复杂度为O(n^2)
int InversePairs(int* data, int length) {
	if (data == NULL || length < 2)
		return 0;

	int totalInversePairs = 0;
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1;j < length;j++) {
			if (data[i] > data[j])
				++totalInversePairs;
		}
	}
	return totalInversePairs;
}

//解题思路二：为避免时间复杂度为O(n^2)，每次扫描数字时不能拿它和后面的数字比较
//将数组递归划分成两个子数组，至每个子数组长度为1，再依次合并两相邻数组，如果存在逆序数，则逆序对计数加，并排序
//至全部排列完毕。时间复杂度为O(nlogn)
int InversePairsCore(int* data, int* copy, int start, int end) {
	if (start == end) {
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;
	
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start&&j >= start + length + 1) {
		if (data[i] > data[j]) {
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else {
			copy[indexCopy--] = data[j--];
		}
	}

	for (;i >= start;--i)
		copy[indexCopy--] = data[i];
	for (;j >= start + length + 1;--j)
		copy[indexCopy--] = data[j];

	return left + right + count;
}
int InversePairs2(int* data, int length) {
	if (data == NULL || length < 0)
		return 0;
	
	int* copy = new int[length];
	for (int i = 0; i < length; i++)
		copy[i] = data[i];

	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;

	return count;
}


int main()
{
	int data[] = { 7,5,6,4 };
	cout << InversePairs(data, sizeof(data) / sizeof(data[0])) << endl;
	
	cout<<InversePairs2(data, sizeof(data) / sizeof(data[0])) << endl;

    return 0;
}

