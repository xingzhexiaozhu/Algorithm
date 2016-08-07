// 51DuplicationiInArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：在一个长度为n的数组中所有数字都在0-(n-1)之间，数组中某些数字是重复的，但不知道几个数字重复了，也不知道重复了几次。
//请找出数组中任意一个重复的数字。例如如果输入长为7的数组{2,3,1,0,2,5,3}，那么对应输出的是重复的数字2或者3

//解题思路一：排序，然后遍历查找到第一个重复的数字【排序的时间复杂度最少为O(nlogn)，还有查找时间复杂度】

//解题思路二：哈希表【时间复杂度为O(n)，但需要额外的空间】

//解题思路三：从头遍历数组，a[i]与i比，如果相等则下一位；如果不相等则index=a[i]然后a[i]与a[index]交换，至一趟结束就可以找到重复元素
bool duplicate(int num[], int length, int *duplicateNum) {
	if(num == NULL || length < 1)
		return false;

	for (int i = 0; i < length; i++) {
		while (num[i] != i) {
			if (num[i] == num[num[i]]) {
				*duplicateNum = num[i];
				return true;
			}
			int temp = num[i];
			num[i] = num[temp];
			num[temp] = temp;
		}
	}

	return false;
}

int main()
{
	int num[] = { 2,3,1,0,2,5,3 };
	int res;
	if (duplicate(num, sizeof(num) / sizeof(num[0]), &res))
		cout << res << endl;
	else cout << "No duplicate num!" << endl;

    return 0;
}

