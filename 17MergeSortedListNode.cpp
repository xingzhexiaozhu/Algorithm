// 17MergeSortedListNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入两个递增排序的链表，合并这两链表并使新链表中的结点仍是按照递增排序的
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

//打印链表
void PrintListNode(ListNode* pHead) {
	ListNode* pNode = pHead;
	while (pNode != NULL) {
		cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

//方法一：合并两排序链表的循环解法
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* pNewHead = NULL;//新排序链表的头结点
	if (pHead2->m_nValue < pHead1->m_nValue) {
		pNewHead = pHead2;
		pHead2 = pHead2->m_pNext;
	}
	else {
		pNewHead = pHead1;
		pHead1 = pHead1->m_pNext;
	}

	ListNode* pNode = pNewHead;
	while (pHead1 != NULL && pHead2 != NULL) {
		if (pHead2->m_nValue < pHead1->m_nValue) {
			pNode->m_pNext = pHead2;
			pHead2 = pHead2->m_pNext;
		}
		else {
			pNode->m_pNext = pHead1;
			pHead1 = pHead1->m_pNext;
		}
		
		pNode = pNode->m_pNext;
	}
	
	if (pHead1 != NULL) 
		pNode->m_pNext = pHead1;
	if (pHead2 != NULL)
		pNode->m_pNext = pHead2;

	return pNewHead;
}
//方法二：合并两排序链表的递归解法
ListNode* Merge1(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* pNewHead = NULL;
	if (pHead1->m_nValue < pHead2->m_nValue) {
		pNewHead = pHead1;
		pNewHead->m_pNext = Merge1(pHead1->m_pNext, pHead2);
	}
	else {
		pNewHead = pHead2;
		pNewHead->m_pNext = Merge1(pHead1, pHead2->m_pNext);
	}

	return pNewHead;
}

int main()
{
	ListNode* head1 = new ListNode();
	for (int i = 1; i < 5; ++i)
		AddToTail(&head1, 2 * i - 1);
	PrintListNode(head1);

	ListNode* head2 = new ListNode();
	for (int i = 1; i < 5; ++i)
		AddToTail(&head2, 2 * i);
	PrintListNode(head2);

	ListNode* pNode = Merge(head1,head2);
	PrintListNode(pNode);

	//ListNode* pNode = Merge1(head1, head2);
	//PrintListNode(pNode);

    return 0;
}

