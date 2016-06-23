// 22TheOrderOfStack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;
//�������������������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳���磺
//����˳��1��2��3��4��5		��4��5��3��2��1�������˳��			��4��3��5��1��2���������˳��

//����˼·����1�������һ�����������ָպ���ջ�����֣���ôֱ�ӵ�����
//��2�����һ�¸����������ֲ���ջ�������ѹջ�����л�û����ջ������ѹ�븨��ջ��ֱ������һ����Ҫ����������ѹ��ջ����
//��3������������ֶ�ѹ��ջ��Ȼû���ҵ���һ�����������֣���ô�����в�������һ����������

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

