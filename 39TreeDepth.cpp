// 39TreeDepth.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入一棵二叉树根结点，求该树深度。

struct BinaryTreeNode {
	int val;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

//解题思路：二叉树题目一般采用递归解决：如果当前结点为NULL则相对深度为0，否则依次对左右子树递归，取较大深度为树的深度
int DepthTree(BinaryTreeNode* pRoot) {
	if (pRoot == NULL)
		return 0;

	int left = DepthTree(pRoot->pLeft);
	int right = DepthTree(pRoot->pRight);

	return (left > right) ? (left + 1) : (right + 1);
}



//本题升级：输入一棵二叉树的根结点，判断该二叉树是否为平衡二叉树
//解题思路：是否为平衡二叉树，二叉树中任意结点的左右子树的深度相差不超过1即为平衡二叉树
bool IsBalanceTree(BinaryTreeNode* pRoot) {
	if (pRoot == NULL)
		return true;

	int left = DepthTree(pRoot->pLeft);
	int right = DepthTree(pRoot->pRight);
	int delta = left - right;
	if (delta > 1 || delta < -1)
		return false;

	return IsBalanceTree(pRoot->pLeft) && IsBalanceTree(pRoot->pRight);
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

	root->val = 1;
	node1->val = 2;
	node2->val = 3;
	node3->val = 4;
	node4->val = 5;
	node5->val = 6;
	node6->val = 7;

	root->pLeft = node1;
	root->pRight = node2;
	node1->pLeft = node3;
	node1->pRight = node4;
	node2->pRight = node5;
	node4->pLeft = node6;

	cout << DepthTree(root) << endl;

	cout << IsBalanceTree(root) << endl;
	
    return 0;
}

