// BinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//创建二叉树结点
BinaryTreeNode* CreateBinaryTreeNode(int value) {
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;
	return pNode;
}

//连接二叉树结点
void ConnectionTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if (pParent != NULL) {
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

//求二叉树深度
int TreeDepth(BinaryTreeNode* pRoot) {
	if(pRoot == NULL){//如果pRoot为NULL则深度为0，递归返回的条件
		return 0;
	}
	//如果pRoot不为NULL，那么深度至少为1，所以left和right为1
	int left = 1;
	int right = 1;
	left += TreeDepth(pRoot->m_pLeft);//左子树深度
	right += TreeDepth(pRoot->m_pRight);//右子树深度

	return left > right ? left : right;//返回深度较大那一个
}

//反转二叉树
BinaryTreeNode* InvertedTree(BinaryTreeNode* pRoot) {
	if (pRoot == NULL) return 0;
	BinaryTreeNode* tempNode = pRoot->m_pLeft;
	pRoot->m_pLeft = InvertedTree(pRoot->m_pRight);
	pRoot->m_pRight = InvertedTree(tempNode);
	return pRoot;
}

//判断两个二叉树是否相同
//方法一
bool isSameTree1(BinaryTreeNode* p, BinaryTreeNode* q) {
	if ((p == NULL) && (q == NULL)) return true;
	if ((p == NULL) || (q == NULL)) return false;
	if (p->m_nValue != q->m_nValue) return false;
	bool left = isSameTree(p->m_pLeft, q->m_pLeft);
	bool right = isSameTree(p->m_pRight, q->m_pRight);
	return (left == true) && (right == true);
}
//方法二
bool isSameTree(BinaryTreeNode* p, BinaryTreeNode* q) {
	if ((p == NULL) && (q == NULL)) return true;
	else if (p == NULL || q == NULL) return false;
	return p->m_nValue==q->m_nValue && isSameTree(p->m_pLeft, q->m_pRight) && isSameTree(p->m_pRight, q->m_pRight);
}

int main()
{
	//            1
	//         /      \
	//        2        3
	//       /\         \
	//      4  5         6
	//           /
	//        7


	//创建树结点
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	//连接树结点
	ConnectionTreeNodes(pNode1, pNode2, pNode3);
	ConnectionTreeNodes(pNode2, pNode4, pNode5);
	ConnectionTreeNodes(pNode3, NULL, pNode6);
	ConnectionTreeNodes(pNode5, pNode7, NULL);

	int depth = TreeDepth(pNode1);
	cout << depth << endl;

	system("pause");

    return 0;
}

