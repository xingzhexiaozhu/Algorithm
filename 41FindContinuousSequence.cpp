// 41FindContinuousSequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入一个正数Num，打印出所有和为Num的连续正数序列（至少含两个数）。
//例如输入15，由于1+2+3+4+5=14+5+6=7+8=15，所以打印3个连续的序列1-5、4-6、7-8

//解题思路：借鉴上一题目的思路，因为连续的正数序列至少有两个数字，所以先声明两个数字并初始化begin=1、end=2，则序列和为3。
//以Num=9为例：3<9故end=3，序列和为6；	6<9故end=4，序列和为10；	10>9故bedgin=2，序列和为9。 然后依次类推，到begin为(Num+1)/2即找到所有符合条件的
void PrintSequence(int begin, int end) {//打印序列
	for (int i = begin; i <= end; i++)
		cout << i << " ";
	cout << endl;
}
void FindContinuousSequence(int num) {//找序列
	if (num < 3)
		return;

	int begin = 1, end = 2;
	int curSum = begin + end;
	int threshold = (num + 1) / 2;
	while (begin < threshold) {
		if (curSum == num)
			PrintSequence(begin, end);
		//else if (curSum < num) {//错误解法，会死循环
		//	++end;
		//	curSum += end;
		//}
		//else {
		//	curSum -= begin;
		//	++begin;
		//}
		while (curSum > num && begin < threshold) {
			curSum -= begin;
			begin++;

			if (curSum == num)
				PrintSequence(begin, end);
		}
		end++;
		curSum += end;
	}
}

int main()
{
	int num;
	while (cin >> num) {
		FindContinuousSequence(num);
	}

    return 0;
}

