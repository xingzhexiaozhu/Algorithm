// 27ConvertBinarySearchTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
//如：二叉搜索树       10
//                    /  \
//                   6    14
//                 / \    / \
//                4   8  12  16
//对应的转换后的双向链表：[4<>6<>8<>10<>12<>14<>16]

struct BinaryTreeNode {
	int val;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

//解题思路：二叉搜索树的中序遍历是有序的，而对于树的处理一般都是递归进行比较方便，
//这里将树分成左右子树，先将左、右子树的结点分别排成双向链表，然后连接左右子树和根结点使整体排成双向链表
//具体做法就是将树结点的pLeft指向其链表顺序的前一个结点，将pRight指向链表顺序的后一个结点
void ConvertToList(BinaryTreeNode* root, BinaryTreeNode**pNode);

BinaryTreeNode* ConvertToList(BinaryTreeNode* root) {
	BinaryTreeNode* pNode = NULL;
	ConvertToList(root, &pNode);
	
	//经过上一步得到的双向链表，pNode每次指向链表最后一个结点，所以这里要找到头结点返回
	BinaryTreeNode* head = pNode;
	while (head != NULL && head->pLeft != NULL)
		head = head->pLeft;
	return head;
}

void ConvertToList(BinaryTreeNode* root, BinaryTreeNode**pNode) {
	if (pNode == NULL)
		return;
	BinaryTreeNode* tmp = root;
	
	if (tmp->pLeft != NULL)
		ConvertToList(tmp->pLeft, pNode);
	tmp->pLeft = *pNode;
	if (*pNode != NULL)
		(*pNode)->pRight = tmp;

	*pNode = tmp;

	if (tmp->pRight != NULL)
		ConvertToList(tmp->pRight, pNode);
}

//中序遍历二叉搜索树
void ShowTree(BinaryTreeNode* root) {
	if (root->pLeft != NULL)
		ShowTree(root->pLeft);
	cout << root->val << " ";
	if (root->pRight != NULL)
		ShowTree(root->pRight);
}

//双向遍历双向链表
void ShowList(BinaryTreeNode* head) {
	BinaryTreeNode* pNode = head;
	cout << "正向遍历双向链表：";
	while (pNode->pRight != NULL) {
		cout << pNode->val << " ";
		pNode = pNode->pRight;
	}
	cout << pNode->val << endl;

	cout << "反向遍历双向链表：";
	while (pNode->pLeft != NULL) {
		cout << pNode->val << " ";
		pNode = pNode->pLeft;
	}
	cout << pNode->val << endl;
}

int main()
{
	BinaryTreeNode* root = new BinaryTreeNode();
	BinaryTreeNode* node1 = new BinaryTreeNode();
	BinaryTreeNode* node2 = new BinaryTreeNode();
	BinaryTreeNode* node3 = new BinaryTreeNode();
	BinaryTreeNode* node4 = new BinaryTreeNode();
	BinaryTreeNode* node5 = new BinaryTreeNode();
	BinaryTreeNode* node6 = new BinaryTreeNode();

	root->val = 10;
	node1->val = 6;
	node2->val = 14;
	node3->val = 4;
	node4->val = 8;
	node5->val = 12;
	node6->val = 16;

	root->pLeft = node1;
	root->pRight = node2;
	node1->pLeft = node3;
	node1->pRight = node4;
	node2->pLeft = node5;
	node2->pRight = node6;
	
	cout << "初始二叉搜索树的中序遍历：";
	ShowTree(root);
	cout << endl;

	BinaryTreeNode* head = ConvertToList(root);
	ShowList(head);

    return 0;
}

