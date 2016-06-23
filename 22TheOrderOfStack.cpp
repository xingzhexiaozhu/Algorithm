// 22TheOrderOfStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;
//题意描述：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。如：
//输入顺序：1，2，3，4，5		则4，5，3，2，1是其输出顺序			但4，3，5，1，2不是其输出顺序

//解题思路：（1）如果下一个弹出的数字刚好是栈顶数字，那么直接弹出；
//（2）如果一下个弹出的数字不在栈顶，则把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要弹出的数字压入栈顶；
//（3）如果所有数字都压入栈仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列

bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
	bool bPossible = false;

	if (pPush != NULL && pPop != NULL && nLength > 0) {
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		stack<int> stackData;

		while (pNextPop - pPop < nLength) {
			while (stackData.empty() || stackData.top() != *pNextPop) {
				if (pNextPush - pPush == nLength)
					break;

				stackData.push(*pNextPush);

				pNextPush++;
			}

			if (stackData.top() != *pNextPop)
				break;

			stackData.pop();
			pNextPop++;
		}

		if (stackData.empty() && pNextPop - pPop == nLength)
			bPossible = true;
	}

	return bPossible;
}

int main()
{
	int array[] = { 1,2,3,4,5 };

	int test1[] = { 4,5,3,2,1 };
	cout << IsPopOrder(array, test1, 5)<< endl;
	
	int test2[] = { 4,3,5,1,2 };
	cout << IsPopOrder(array, test2, 5) << endl;

    return 0;
}

