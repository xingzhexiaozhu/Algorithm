// 26ComplexListNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//复杂链表的复制
//题意描述：请实现函数ComplexListNode *Clone(ComplexListNode* head)，复制一个复杂链表。
//在复杂链表中，每个结点除了有一个pNext指针指向一下一个结点外，还有一个pOther指向链表中任意结点或NULL

struct ComplexListNode {
	int val;
	ComplexListNode* pNext;
	ComplexListNode* pOther;
};

//解题思路：这里分为三个步骤：
//1）复制链表，复制原始链表的任意结点N并创建新结点N`，再把N`链接到N的后面；
//2）设置结点的pOther指针对应的结点,如果原始链表上结点N的pOther指针指向S，则它对应的复制结点N`的pOther指针就指向S的下一个结点S`；
//3）将链表拆分为两个链表,把奇数位置的结点用pNext指针链接起就是原始链表，偶数位置用pNext指针链接起来就是复制的链表；

//复制原始链表的任意结点N并创建新结点N`，再把N`链接到N的后面
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

//设置结点的pOther指针对应的结点,如果原始链表上结点N的pOther指针指向S，则它对应的复制结点N`的pOther指针就指向S的下一个结点S`
void SetpOther(ComplexListNode* head) {
	ComplexListNode* pNode = head;
	while (pNode != NULL) {
		if (pNode->pOther != NULL)
			pNode->pNext->pOther = pNode->pOther->pNext;
		pNode = pNode->pNext->pNext;
	}
}

//将链表拆分为两个链表,把奇数位置的结点用pNext指针链接起就是原始链表，偶数位置用pNext指针链接起来就是复制的链表
ComplexListNode* SplitList(ComplexListNode* head) {
	ComplexListNode* pNode = head;
	ComplexListNode* CopyHead = NULL;
	ComplexListNode* pCopyNode = NULL;
	
	if (pNode != NULL) {//设置新链表表头
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
	cout << "\t" << "顺序链表输出：";
	while (pNode != NULL) {
		cout << pNode->val << " " ;
		pNode = pNode->pNext;
	}
	cout << endl;
	
	pNode = head;
	cout << "\t" << "pOther指针情况：";
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

	cout << "复制前原始链表输出:" << endl;
	ShowList(head);
	ComplexListNode* pHead = CloneList(head);
	cout << "复制后原始链表输出:" << endl;
	ShowList(head);
	cout << "复制后复制链表输出:" << endl;
	ShowList(pHead);

    return 0;
}

