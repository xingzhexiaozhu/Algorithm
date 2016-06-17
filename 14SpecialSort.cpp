// 14SpecialSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入一个数组，实现一个函数将数组中数字重新排序，使得所有奇数位于数组的前面，所有偶数位于数组的后面

//解题思路一：借鉴快排的思想，使用两个指针，指针1指向数组第一个元素（从前向后遍历），指针2指向数组最后一个元素（从后向前遍历），
//当指针1指向元素为偶且指针2指向元素为奇时交换两元素，当两指针相遇时遍历结束
void ReorderOddEven(int* pData, int length) {
	if (pData == NULL || length == 0)
		return;
	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd) {
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
			pBegin++;
		while (pEnd > pBegin && (*pEnd & 0x1) == 0)
			pEnd--;

		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

//解题思路二：问题扩展，比如面试官让我们按照数字正负将数组分为前后两部分、按照是否能被3整除分为前后两部分呢？
//与上面相比我们发现只是函数中两个循环的判断标准发生了变化，其他地方完全一样。所以这里我们把整个函数解耦成两部分：
//一个函数判断数字应该在数组的前半部分还是后半部分；二是拆分数组的操作部分
void Reorder(int* pData, int length, bool(*func)(int)) {
	if (pData == NULL || length == 0)
		return;

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd) {
		while (pBegin < pEnd && !func(*pBegin))
			pBegin++;
		while (pEnd > pBegin && func(*pEnd))
			pEnd--;

		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n) {
	return (n & 0x1) == 0;
}

void ReorderOddEven1(int* pData, int length) {
	Reorder(pData, length, isEven);
}

int main()
{
	int num[] = { 1,2,3,4,5 };
	ReorderOddEven1(num, 5);
	for (int i = 0; i < 5; i++)
		cout << num[i] << " ";
	cout << endl;

    return 0;
}

