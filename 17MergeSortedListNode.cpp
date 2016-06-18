// 17MergeSortedListNode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������������������������ϲ���������ʹ�������еĽ�����ǰ��յ��������
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

//β�巨
void AddToTail(ListNode** pHead, int value) {
	ListNode* pNode = CreateNode(value);

	if (*pHead == NULL)//���ͷ���Ϊ��
		*pHead = pNode;
	else {//����β�巨������ 
		ListNode* p = *pHead;
		while (p->m_pNext != NULL)
			p = p->m_pNext;
		p->m_pNext = pNode;
	}
}

//��ӡ����
void PrintListNode(ListNode* pHead) {
	ListNode* pNode = pHead;
	while (pNode != NULL) {
		cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

//����һ���ϲ������������ѭ���ⷨ
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* pNewHead = NULL;//�����������ͷ���
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
//���������ϲ�����������ĵݹ�ⷨ
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

