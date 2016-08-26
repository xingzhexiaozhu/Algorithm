// 63KthTreeNode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ�ö��������������ҳ����еĵ�K��Ľ��

struct BinaryTreeNode
{
	int val;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

//����˼·����������������������������
BinaryTreeNode* KthTreeNode(BinaryTreeNode* pRoot, int &k) {
	BinaryTreeNode* node = NULL;

	if (pRoot->pLeft != NULL)
		node = KthTreeNode(pRoot->pLeft, k);

	if (node == NULL) {
		if (k == 1)
			node = pRoot;
		k--;
	}

	if (node == NULL && pRoot->pRight != NULL)
		node = KthTreeNode(pRoot->pRight, k);

	return node;
}
BinaryTreeNode* findKthTreeNode(BinaryTreeNode* pRoot, int k) {
	if (pRoot == NULL || k == 0)
		return NULL;

	return KthTreeNode(pRoot, k);
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

	node1->val = 5;
	node2->val = 3;
	node3->val = 7;
	node4->val = 2;
	node5->val = 4;
	node6->val = 6;
	node7->val = 8;

	node1->pLeft = node2;
	node1->pRight = node3;
	node2->pLeft = node4;
	node2->pRight = node5;
	node3->pLeft = node6;
	node3->pRight = node7;

	BinaryTreeNode* node = findKthTreeNode(node1, 3);

	if(node != NULL)
		cout << node->val << endl;

    return 0;
}

