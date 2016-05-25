// 5ListNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<stack>
using namespace std;

//题意描述：从尾到头打印链表（假设不允许改变输入链表的结构）

struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

void AddToTail(ListNode** pHead, int value) {
	ListNode* pNew = new ListNode();
	pNew->m_nKey = value;
	pNew->m_pNext = NULL;

	if (*pHead == NULL)
		*pHead = pNew;
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}

//解题思路：从头到尾遍历链表，依次将各结点放入栈中，待链表访问完毕，再从栈中弹出每个元素输出
//循环遍历
void PrintListReversingly_Iteratively(ListNode *pHead) {
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != NULL) {//遍历链表
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty()) {
		pNode = nodes.top();
		cout << pNode->m_nKey << " ";
		nodes.pop();
	}
	cout << endl;
}
//递归遍历
void PrintListReversingly_Iteratively1(ListNode *pHead) {
	if (pHead != NULL) {
		if (pHead->m_pNext != NULL) {
			PrintListReversingly_Iteratively1(pHead->m_pNext);
		}
		cout << pHead->m_nKey << " ";
	}
}

int main()
{
	ListNode* head = new ListNode();
	for (int i = 1; i < 10; i++)
		AddToTail(&head, i);

	PrintListReversingly_Iteratively(head);
	PrintListReversingly_Iteratively1(head);

	return 0;
}

