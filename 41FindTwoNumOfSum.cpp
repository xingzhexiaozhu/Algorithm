// 41FindTwoNumOfSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
using namespace std;

//题意描述：输入一个递增排序的数组和一个数字Sum，在数组中查找两个数，使得它们的和正好是Sum，如果有多对和为Sum则任意输出一对即可

//解题思路一：在Java中运用HashMap集合，key = Sum - curNum、value = curNum，每当遍历下一个数字时先判断该数字是否在map中的key出现过，出现则找到
//同理使用set
bool FindNumersWithSum(int data[], int len, int sum, int* num1, int* num2) {
	if (data == NULL || len <= 0)
		return false;

	map<int, int> mymap;
	for (int i = 0; i < len; i++) {
		map<int, int>::iterator it = mymap.find(data[i]);
		if (it != mymap.end()) {//找到主键
			*num1 = it->first;
			*num2 = it->second;
			return true;
		}
		//如果没找到主键，则插入当前数值对，key=sum-data[i]、value=data[i]
		mymap.insert(pair<int, int>(sum - data[i], data[i]));
	}
	return false;
}
//解题思路二：使用两个指针，则第一个指针指向数组头，第二个指针指向数组尾，然后求和：
//           >sum第二个指针前移；<sum则第一个指针后移；=sum则返回
bool FindNumbersWithSum2(int data[], int len, int sum, int* num1, int* num2) {
	if (data == NULL || len <= 0)
		return false;

	int ahead = 0, tail = len - 1;
	while (tail > ahead) {
		if (data[ahead] + data[tail] > sum) {
			tail--;
		}
		else if(data[ahead] + data[tail] < sum) {
			ahead++;
		}else {
			*num1 = data[ahead];
			*num2 = data[tail];
			return true;
		}
	}

	return false;
}

int main()
{
	int num[] = { 1,2,4,7,11,15 };
	int num1, num2, sum = 15;
	//if (FindNumersWithSum(num, sizeof(num) / sizeof(int), sum, &num1, &num2)) {
	//	cout << num1 << "\t" << num2 << endl;
	//}
	//else cout << "Not Found!" << endl;

	if (FindNumbersWithSum2(num, sizeof(num) / sizeof(int), sum, &num1, &num2)) {
		cout << num1 << "\t" << num2 << endl;
	}
	else cout << "Not Found!" << endl;

    return 0;
}

