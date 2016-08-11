// 57DeleteDuplicateNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

//题意描述：在一个排序的链表中，删除重复的结点
//如：原链表为1->2->3->3->4->4->5，删除重复结点后的链表为1->2->5

void deleteDuplicate(ListNode** pHead) {
	if (pHead == NULL || *pHead == NULL)
		return;

	ListNode* preNode = NULL;
	ListNode* pNode = *pHead;
	while (pNode != NULL) {
		ListNode *pNext = pNode->next;
		bool needDelete = false;
		if (pNext != NULL && pNext->val == pNode->val)
			needDelete = true;

		if (!needDelete) {
			preNode = pNode;
			pNode = pNode->next;
		}
		else {
			int val = pNode->val;
			ListNode* pToBeDel = pNode;
			while (pToBeDel != NULL&&pToBeDel->val == val) {
				pNext = pToBeDel->next;

				delete pToBeDel;
				pToBeDel = NULL;

				pToBeDel = pNext;
			}

			if (preNode == NULL)
				*pHead = pNext;
			else preNode->next = pNext;
			pNode = pNext;
		}
	}
}

int main()
{
	ListNode* node1 = new ListNode();
	ListNode* node2 = new ListNode();
	ListNode* node3 = new ListNode();
	ListNode* node4 = new ListNode();
	ListNode* node5 = new ListNode();
	ListNode* node6 = new ListNode();
	ListNode* node7 = new ListNode();

	node1->val = 1;
	node2->val = 2;
	node3->val = 3;
	node4->val = 3;
	node5->val = 4;
	node6->val = 4;
	node7->val = 5;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;

	deleteDuplicate(&node1);
	
	ListNode* node = node1;
	while (node != NULL) {
		cout << node->val << " ";
		node = node->next;
	}		
	cout << endl;

    return 0;
}

