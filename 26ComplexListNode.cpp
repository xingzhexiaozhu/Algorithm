// 26ComplexListNode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//��������ĸ���
//������������ʵ�ֺ���ComplexListNode *Clone(ComplexListNode* head)������һ����������
//�ڸ��������У�ÿ����������һ��pNextָ��ָ��һ��һ������⣬����һ��pOtherָ���������������NULL

struct ComplexListNode {
	int val;
	ComplexListNode* pNext;
	ComplexListNode* pOther;
};

//����˼·�������Ϊ�������裺
//1��������������ԭʼ�����������N�������½��N`���ٰ�N`���ӵ�N�ĺ��棻
//2�����ý���pOtherָ���Ӧ�Ľ��,���ԭʼ�����Ͻ��N��pOtherָ��ָ��S��������Ӧ�ĸ��ƽ��N`��pOtherָ���ָ��S����һ�����S`��
//3����������Ϊ��������,������λ�õĽ����pNextָ�����������ԭʼ����ż��λ����pNextָ�������������Ǹ��Ƶ�����

//����ԭʼ�����������N�������½��N`���ٰ�N`���ӵ�N�ĺ���
void CloneNodes(ComplexListNode* head) {
	ComplexListNode* pNode = head;
	while (pNode != NULL) {
		ComplexListNode* tmpNode = new ComplexListNode();
		tmpNode->val = pNode->val;
		tmpNode->pNext = pNode->pNext;
		tmpNode->pOther = NULL;

		pNode->pNext = tmpNode;
		pNode = tmpNode->pNext;
	}
}

//���ý���pOtherָ���Ӧ�Ľ��,���ԭʼ�����Ͻ��N��pOtherָ��ָ��S��������Ӧ�ĸ��ƽ��N`��pOtherָ���ָ��S����һ�����S`
void SetpOther(ComplexListNode* head) {
	ComplexListNode* pNode = head;
	while (pNode != NULL) {
		if (pNode->pOther != NULL)
			pNode->pNext->pOther = pNode->pOther->pNext;
		pNode = pNode->pNext->pNext;
	}
}

//��������Ϊ��������,������λ�õĽ����pNextָ�����������ԭʼ����ż��λ����pNextָ�������������Ǹ��Ƶ�����
ComplexListNode* SplitList(ComplexListNode* head) {
	ComplexListNode* pNode = head;
	ComplexListNode* CopyHead = NULL;
	ComplexListNode* pCopyNode = NULL;
	
	if (pNode != NULL) {//�����������ͷ
		CopyHead = pNode->pNext;
		pNode->pNext = CopyHead->pNext;
		pNode = pNode->pNext;
	}
	
	pCopyNode = CopyHead;
	while (pNode != NULL) {
		pCopyNode->pNext = pNode->pNext;
		pCopyNode = pCopyNode->pNext;
		pNode->pNext = pCopyNode->pNext;
		pNode = pNode->pNext;
	}

	return CopyHead;
}

ComplexListNode* CloneList(ComplexListNode* head) {
	CloneNodes(head);
	SetpOther(head);
	ComplexListNode* pNewHead = SplitList(head);
	return pNewHead;
}


void ShowList(ComplexListNode* head) {
	ComplexListNode* pNode = head;
	cout << "\t" << "˳�����������";
	while (pNode != NULL) {
		cout << pNode->val << " " ;
		pNode = pNode->pNext;
	}
	cout << endl;
	
	pNode = head;
	cout << "\t" << "pOtherָ�������";
	while (pNode != NULL) {
		if (pNode->pOther != NULL)
			cout << pNode->val << "-" << pNode->pOther->val << "\t";
		pNode = pNode->pNext;
	}
	cout << endl;
}

int main()
{
	ComplexListNode* head = new ComplexListNode();
	ComplexListNode* node1 = new ComplexListNode();
	ComplexListNode* node2 = new ComplexListNode();
	ComplexListNode* node3 = new ComplexListNode();
	ComplexListNode* node4 = new ComplexListNode();

	head->val = 1;
	node1->val = 2;
	node2->val = 3;
	node3->val = 4;
	node4->val = 5;

	head->pNext = node1;	
	node1->pNext = node2;
	node2->pNext = node3;
	node3->pNext = node4;

	head->pOther = node2;
	node1->pOther = node3;
	node2->pOther = node4;

	cout << "����ǰԭʼ�������:" << endl;
	ShowList(head);
	ComplexListNode* pHead = CloneList(head);
	cout << "���ƺ�ԭʼ�������:" << endl;
	ShowList(head);
	cout << "���ƺ����������:" << endl;
	ShowList(pHead);

    return 0;
}

