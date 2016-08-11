// 58GetInorderNext.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：给定一棵二叉树和其中一个结点，如何找出中序遍历顺序的下一个结点
//树中结点除了两分别指向左右子结点的指针外，还有一指向父结点的指针

//       a
//     /   \
//    b      c
//   / \    /  \
// d    e  f    g
//     / \
//    h   i

//解题思路： 上图所示的二叉树中序遍历序列为 d-b-h-e-i-a-f-c-g
//1）给定结点有右子树，则下一结点为该结点右子树的最左子结点【即沿左指针走到头】；
//2）给定结点没有右子树，结果结点是父结点的左子结点，则下一结点为该父结点；
//3）给定结点没有右子树，且为父结点的右子结点，则沿指向父结点的指针向上遍历，
//直到找到一个是它他父结点的左子结点的结点，如果存在则这个结点的父结点就是我们要找的下一个结点；

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

