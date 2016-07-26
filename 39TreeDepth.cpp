// 39TreeDepth.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ�ö���������㣬�������ȡ�

struct BinaryTreeNode {
	int val;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

//����˼·����������Ŀһ����õݹ����������ǰ���ΪNULL��������Ϊ0���������ζ����������ݹ飬ȡ�ϴ����Ϊ�������
int DepthTree(BinaryTreeNode* pRoot) {
	if (pRoot == NULL)
		return 0;

	int left = DepthTree(pRoot->pLeft);
	int right = DepthTree(pRoot->pRight);

	return (left > right) ? (left + 1) : (right + 1);
}



//��������������һ�ö������ĸ���㣬�жϸö������Ƿ�Ϊƽ�������
//����˼·���Ƿ�Ϊƽ�������������������������������������������1��Ϊƽ�������
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

