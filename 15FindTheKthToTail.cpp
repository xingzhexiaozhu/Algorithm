// 15FindTheKthToTail.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ�������������������K�����

struct ListNode
{
	int val;
	ListNode *next;
};

ListNode* CreateNode(int val) {
	ListNode* node = new ListNode();
	node->val = val;
	node->next = NULL;
	return node;
}

//����˼·��ʹ������ָ�룬ָ��1����(k-1)����ָ��2�ٴ�ͷ��ʼ����ָ��1�ߵ������βʱָ��2��ָ�����ǵ�����K�����
//�������ע������Ϊ�ա�����K���Ϸ�����������С��K�����
ListNode* findKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL || k <= 0)
		return NULL;//����Ϊ��ʱ���ؿ�

	ListNode* first = pListHead;
	ListNode* second = pListHead;

	for (unsigned int i = 0; i < k - 1; i++) {
		if (first == NULL)
			return NULL;//����������С��Kʱ���ؿ�

		first = first->next;//��һ��ָ������k-1λ
	}

	while (first->next != NULL) {
		first = first->next;
		second = second->next;
	}

	return second;
}

int main()
{
	ListNode* node1 = CreateNode(1);
	ListNode* node2 = CreateNode(2);
	ListNode* node3 = CreateNode(3);
	ListNode* node4 = CreateNode(4);
	ListNode* node5 = CreateNode(5);
	ListNode* node6 = CreateNode(6);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	ListNode* node = findKthToTail(node1, 3);
	cout << node->val << endl;

	return 0;
}

