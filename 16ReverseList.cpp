// 16ReverseList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ������������һ�������ͷ��㣬��ת�������������ת�������

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

//ͷ�巨
void AddToHead(ListNode** pHead, int value) {
	ListNode* pNode = CreateNode(value);	

	pNode->m_pNext = *pHead;
	*pHead = pNode;
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

//��ת����:����ͷ�巨����������
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

//��ӡ����
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

