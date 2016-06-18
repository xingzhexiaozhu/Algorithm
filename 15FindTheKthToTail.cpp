// 15FindTheKthToTail.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入一个链表，输出该链表倒数第K个结点

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

//解题思路：使用两个指针，指针1先走(k-1)步，指针2再从头开始，当指针1走到链表结尾时指针2所指结点就是倒数第K个结点
//处理过程注意链表为空、输入K不合法、链表结点数小于K的情况
ListNode* findKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL || k <= 0)
		return NULL;//链表为空时返回空

	ListNode* first = pListHead;
	ListNode* second = pListHead;

	for (unsigned int i = 0; i < k - 1; i++) {
		if (first == NULL)
			return NULL;//当链表结点数小于K时返回空

		first = first->next;//第一个指针先走k-1位
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

