// 59IsSymmetrical.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//����������ʵ��һ�������жϸ�����һ�ö������ǲ��ǶԳƵ�.���һ�ö����������ľ���һ������Ϊ�ԳƵģ������ǶԳƵ�

struct BinaryTreeNode
{
	char val;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

//����˼·���õݹ�ʵ��
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	if (pRoot1 == NULL && pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL || pRoot2 == NULL)
		return false;
	if (pRoot1->val != pRoot2->val)
		return false;

	return isSymmetrical(pRoot1->pLeft, pRoot2->pRight) &&
		isSymmetrical(pRoot1->pRight, pRoot2->pLeft);
}
bool isSymmetrical(BinaryTreeNode* pRoot) {
	return isSymmetrical(pRoot, pRoot);
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

	node1->val = 8;
	node2->val = 6;
	node3->val = 6;
	node4->val = 5;
	node5->val = 7;
	node6->val = 7;
	node7->val = 5;

	node1->pLeft = node2;
	node1->pRight = node3;
	node2->pLeft = node4;
	node2->pRight = node5;
	node3->pLeft = node6;
	node3->pRight = node7;

	cout << isSymmetrical(node1) << endl;

    return 0;
}

