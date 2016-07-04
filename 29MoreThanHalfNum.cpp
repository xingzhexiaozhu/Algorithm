// 29MoreThanHalfNum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>//包含sort()函数
using namespace std;

//题意描述：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}，返回2

//解题思路一：先将数组排序，这里可以借助快排的思想；然后由于数字出现次数超过数组长度的一半，所以直接返回(n/2)处的数字即可
int moreThanHalfNum(vector<int> num) {
	if (num.size() == 0)
		return -1;
	sort(num.begin(), num.end());
	return num[num.size() / 2];
}

//解题思路二：因为数组中某数字出现次数超过一半，所以从头开始统计数字：
//当下一个数字与上一个数字相同，计数+1；不同计数-1；当计数为0时，重新保存下一个数字并设置计数为1
//最后一次把次数设置为1的数字即为所求
int moreThanHalfNum2(vector<int> num) {
	if (num.size() == 0)
		return -1;
	int res = num[0];//数字
	int count = 1;//计数
	for (int i = 1; i < num.size(); i++) {
		if (count == 0) {
			res = num[i];
			count = 1;
		}else if (res == num[i])
				count++;
		else count--;
	}

	return res;
}

int main()
{
	vector<int> num = { 1,2,3,2,2,2,5,4,2 };
	
	cout << moreThanHalfNum(num) << endl;

	cout << moreThanHalfNum2(num) << endl;

    return 0;
}

