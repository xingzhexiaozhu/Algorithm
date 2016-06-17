// 13DeleteTheNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//题意描述：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点

//解题思路：要求在O(1)时间内删除结点，则可以这样考虑：
//将给定结点后继结点的值赋给给定结点，然后删除给定结点的后继结点即可

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

//尾插法
void AddToTail(ListNode** pHead, int value) {
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = NULL;
	
	if (*pHead == NULL)//如果头结点为空
		*pHead = pNode;
	else {//采用尾插法插入结点 
		ListNode* p = *pHead;
		while (p->m_pNext != NULL)
			p = p->m_pNext;
		p->m_pNext = pNode;
	}
}

//头插法
void AddToHead(ListNode** pHead, int value) {
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	
	pNode->m_pNext = *pHead;
	*pHead = pNode;
}

void DeleteNode(ListNode** pHead, ListNode* pToBeDeleted) {
	if (!pHead || !pToBeDeleted)
		return;

	if (pToBeDeleted->m_pNext != NULL) {//如果要删除的结点不是尾结点
		ListNode* pNode = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNode->m_nValue;
		pToBeDeleted->m_pNext = pNode->m_pNext;

		delete pNode;
		pNode = NULL;
	}
	else if(*pHead == pToBeDeleted){//如果要删除的结点只有一个头结点
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		pHead = NULL;
	}
	else {//链表有多个结点，且删除的是尾结点
		ListNode* p = *pHead;
		while (p->m_pNext != pToBeDeleted)
			p = p->m_pNext;

		p->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}

}

void PrintList(ListNode* pHead) {
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
		AddToHead(&head, i);
	PrintList(head);

	ListNode* pNode = new ListNode();
	pNode->m_nValue = 100;
	pNode->m_pNext = NULL;

	ListNode* pCurrent = head;
	while (pCurrent->m_pNext != NULL)
		pCurrent = pCurrent->m_pNext;
	pCurrent->m_pNext = pNode;
	PrintList(head);

	DeleteNode(&head, pNode);
	PrintList(head);

    return 0;
}

