// 16ReverseList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：定义一个函数，输入一个链表的头结点，反转该链表，并输出反转后的链表

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* CreateNode(int val) {
	ListNode* node = new ListNode();
	node->m_nValue = val;
	node->m_pNext = NULL;
	return node;
}

//头插法
void AddToHead(ListNode** pHead, int value) {
	ListNode* pNode = CreateNode(value);	

	pNode->m_pNext = *pHead;
	*pHead = pNode;
}

//尾插法
void AddToTail(ListNode** pHead, int value) {
	ListNode* pNode = CreateNode(value);

	if (*pHead == NULL)//如果头结点为空
		*pHead = pNode;
	else {//采用尾插法插入结点 
		ListNode* p = *pHead;
		while (p->m_pNext != NULL)
			p = p->m_pNext;
		p->m_pNext = pNode;
	}
}

//反转链表:采用头插法建立链表即可
ListNode* reverseListNode(ListNode* pHead) {	
	if (pHead == NULL)
		return NULL;

	ListNode* pReversedHead = pHead;
	ListNode* pNode = pHead->m_pNext;
	pReversedHead->m_pNext = NULL;
	
	while (pNode != NULL) {	
		ListNode* pNextNode = pNode->m_pNext;		

		pNode->m_pNext = pReversedHead;
		pReversedHead = pNode;
		pNode = pNextNode;
	}
	return pReversedHead;
}

//打印链表
void PrintListNode(ListNode* pHead) {
	ListNode* pNode = pHead;
	while (pNode != NULL) {
		cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

int main()
{
	ListNode* head = new ListNode();
	for (int i = 1; i < 10; i++)
		AddToTail(&head, i);
	PrintListNode(head);

	ListNode* pNode = reverseListNode(head);
	PrintListNode(pNode);

    return 0;
}

