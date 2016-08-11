// 58GetInorderNext.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ�ö�����������һ����㣬����ҳ��������˳�����һ�����
//���н��������ֱ�ָ�������ӽ���ָ���⣬����һָ�򸸽���ָ��

//       a
//     /   \
//    b      c
//   / \    /  \
// d    e  f    g
//     / \
//    h   i

//����˼·�� ��ͼ��ʾ�Ķ����������������Ϊ d-b-h-e-i-a-f-c-g
//1�����������������������һ���Ϊ�ý���������������ӽ�㡾������ָ���ߵ�ͷ����
//2���������û�����������������Ǹ��������ӽ�㣬����һ���Ϊ�ø���㣻
//3���������û������������Ϊ���������ӽ�㣬����ָ�򸸽���ָ�����ϱ�����
//ֱ���ҵ�һ�����������������ӽ��Ľ�㣬���������������ĸ�����������Ҫ�ҵ���һ����㣻

struct BinaryTreeNode
{
	char val;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
	BinaryTreeNode* pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {
	if (pNode == NULL)
		return NULL;

	BinaryTreeNode* pNext = NULL;
	if (pNode->pRight != NULL) {
		BinaryTreeNode* pRight = pNode->pRight;
		while (pRight->pLeft != NULL)
			pRight = pRight->pLeft;
		pNext = pRight;
	}
	else if(pNode->pParent != NULL){
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->pParent;
		while (pParent != NULL && pCurrent == pParent->pRight) {
			pCurrent = pParent;
			pParent = pParent->pParent;
		}
		pNext = pParent;
	}

	return pNext;
}

int main()
{
	BinaryTreeNode* node1 = new BinaryTreeNode();
	BinaryTreeNode* node2 = new BinaryTreeNode();
	BinaryTreeNode* node3 = new BinaryTreeNode();
	BinaryTreeNode* node4 = new BinaryTreeNode();
	BinaryTreeNode* node5 = new BinaryTreeNode();
	BinaryTreeNode* node6 = new BinaryTreeNode();
	BinaryTreeNode* node7 = new BinaryTreeNode();
	BinaryTreeNode* node8 = new BinaryTreeNode();
	BinaryTreeNode* node9 = new BinaryTreeNode();

	node1->val = 'a';
	node2->val = 'b';
	node3->val = 'c';
	node4->val = 'd';
	node5->val = 'e';
	node6->val = 'f';
	node7->val = 'g';
	node8->val = 'h';
	node9->val = 'i';

	node1->pLeft = node2;
	node1->pRight = node3;
	node2->pParent = node1;
	node3->pParent = node1;

	node2->pLeft = node4;
	node2->pRight = node5;
	node3->pLeft = node6;
	node3->pRight = node7;

	node4->pParent = node2;
	node5->pParent = node2;
	node6->pParent = node3;
	node7->pParent = node3;

	node5->pLeft = node8;
	node5->pRight = node9;
	node8->pParent = node5;
	node9->pParent = node5;

	cout << GetNext(node1)->val << endl;//a->next = f
	cout << GetNext(node4)->val << endl;//d->next = b
	cout << GetNext(node9)->val << endl;//i->next = a

    return 0;
}

