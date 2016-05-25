// 5ListNode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
#include<stack>
using namespace std;

//������������β��ͷ��ӡ�������費����ı���������Ľṹ��

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

//����˼·����ͷ��β�����������ν���������ջ�У������������ϣ��ٴ�ջ�е���ÿ��Ԫ�����
//ѭ������
void PrintListReversingly_Iteratively(ListNode *pHead) {
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != NULL) {//��������
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
//�ݹ����
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

