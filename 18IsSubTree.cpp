// 18IsSubTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入两棵二叉树A和B，判断B是不是A的子结构

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* CreateTreeNode(int value) {
	BinaryTreeNode* treeNode = new BinaryTreeNode();
	treeNode->m_nValue = value;
	treeNode->m_pLeft = NULL;
	treeNode->m_pRight = NULL;

	return treeNode;
}

//解题思路：依次判断B的根结点是否与A的某一结点相同，如果是则进一步判断B的子结点是否为A对应结点的子结点
bool DoesTreeaHaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	return DoesTreeaHaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTreeaHaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}
bool IsSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	bool result = false;
	if (pRoot1 != NULL && pRoot2 != NULL) {
		if (pRoot1->m_nValue == pRoot2->m_nValue)
			result = DoesTreeaHaveTree2(pRoot1, pRoot2);
		if (!result)
			result = IsSubTree(pRoot1->m_pLeft, pRoot2);
		if (!result)
			result = IsSubTree(pRoot2->m_pRight, pRoot2);
	}
	
	return result;
}

int main()
{
	BinaryTreeNode* node1 = CreateTreeNode(8);
	BinaryTreeNode* node2 = CreateTreeNode(8);
	BinaryTreeNode* node3 = CreateTreeNode(7);
	BinaryTreeNode* node4 = CreateTreeNode(9);
	BinaryTreeNode* node5 = CreateTreeNode(2);
	BinaryTreeNode* node6 = CreateTreeNode(4);
	BinaryTreeNode* node7 = CreateTreeNode(7);
	node1->m_pLeft = node2;
	node1->m_pRight = node3;
	node2->m_pLeft = node4;
	node2->m_pRight = node5;
	node5->m_pLeft = node6;
	node5->m_pRight = node7;

	BinaryTreeNode* node10 = CreateTreeNode(8);
	BinaryTreeNode* node11 = CreateTreeNode(9);
	BinaryTreeNode* node12 = CreateTreeNode(2);
	node10->m_pLeft = node11;
	node10->m_pRight = node12;

	cout << IsSubTree(node1, node11)<<endl;

    return 0;
}

