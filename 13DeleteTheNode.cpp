// 13DeleteTheNode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//�����������������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ���ý��

//����˼·��Ҫ����O(1)ʱ����ɾ����㣬������������ǣ�
//����������̽���ֵ����������㣬Ȼ��ɾ���������ĺ�̽�㼴��

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

//β�巨
void AddToTail(ListNode** pHead, int value) {
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = NULL;
	
	if (*pHead == NULL)//���ͷ���Ϊ��
		*pHead = pNode;
	else {//����β�巨������ 
		ListNode* p = *pHead;
		while (p->m_pNext != NULL)
			p = p->m_pNext;
		p->m_pNext = pNode;
	}
}

//ͷ�巨
void AddToHead(ListNode** pHead, int value) {
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	
	pNode->m_pNext = *pHead;
	*pHead = pNode;
}

void DeleteNode(ListNode** pHead, ListNode* pToBeDeleted) {
	if (!pHead || !pToBeDeleted)
		return;

	if (pToBeDeleted->m_pNext != NULL) {//���Ҫɾ���Ľ�㲻��β���
		ListNode* pNode = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNode->m_nValue;
		pToBeDeleted->m_pNext = pNode->m_pNext;

		delete pNode;
		pNode = NULL;
	}
	else if(*pHead == pToBeDeleted){//���Ҫɾ���Ľ��ֻ��һ��ͷ���
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		pHead = NULL;
	}
	else {//�����ж����㣬��ɾ������β���
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

