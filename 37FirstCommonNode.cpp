// 37FirstCommonNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入两个链表，找出它们的一个公共结点
struct  ListNode
{
	int value;
	ListNode* pNext;
};

//解题思路：由于每个结点都有一个pNext指针，如果两链表有公共结点，则从第一个公共结点后链表完全重合，即如果有公共结点，就是有公共尾链表 
//有了上面的分析，则就可以倒着数公共结点了，因此解法一是采用栈（空间换时间），解法二（这里采用）如下：
//分别得到两链表长度m、n，较长链表先走|m-n|步，然后共同向后遍历，遇到的第一个公共结点即为所求
int GetListLength(ListNode *head) {//计算链表长度
	int len = 0;
	ListNode* tempNode = head;
	while (tempNode != NULL){
		++len;
		tempNode = tempNode->pNext;
	}

	return len;
}
ListNode* FirstCommonNode(ListNode* head1, ListNode* head2) {
	int m = GetListLength(head1);
	int n = GetListLength(head2);

	//分别得到长链表和短链表，及二者长度差
	ListNode* LongList = head1;
	ListNode* ShortList = head2;
	int diffLen = m - n;
	if (m < n) {
		LongList = head2;
		ShortList = head1;
		diffLen = n - m;
	}

	for (int i = 0;i < diffLen;i++)//长链表先从头结点前进diffLen个长度
		LongList = LongList->pNext;

	while (LongList != NULL && ShortList != NULL && LongList->value != ShortList->value) {
		LongList = LongList->pNext;
		ShortList = ShortList->pNext;
	}
	return LongList;
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

	node1->value = 1;
	node2->value = 2;
	node3->value = 3;

	node4->value = 6;
	node5->value = 7;
	
	node6->value = 4;
	node7->value = 5;

	node1->pNext = node2;
	node2->pNext = node3;
	node3->pNext = node4;

	node4->pNext = node5;

	node6->pNext = node7;
	node7->pNext = node4;

	ListNode* node = FirstCommonNode(node1, node6);
	cout << node->value << endl;

    return 0;
}

