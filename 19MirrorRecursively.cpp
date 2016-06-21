// 19MirrorRecursively.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<queue>
using namespace std;

//��������������һ�ö�������������ľ���

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//���������
BinaryTreeNode* CreateNode(int x) {
	BinaryTreeNode* node = new BinaryTreeNode();
	node->m_nValue = x;
	node->m_pLeft = NULL;
	node->m_pRight = NULL;
	return node;
}

//��ӡ����㣨���������
void PrintTree(BinaryTreeNode* root) {	
	if (root->m_pLeft != NULL)
		PrintTree(root->m_pLeft);

	cout << root->m_nValue << " ";

	if (root->m_pRight != NULL)
		PrintTree(root->m_pRight);
}

//��������ľ��񣨼������������������ӽ�㣩
//����һ���޷���ֵ�ĺ����ݹ����
void mirrorRecursively(BinaryTreeNode* root) {
	if (root == NULL)
		return;
	if (root->m_pLeft == NULL && root->m_pRight == NULL)
		return ;

	BinaryTreeNode* tempNode = root->m_pLeft;
	root->m_pLeft = root->m_pRight;
	root->m_pRight = tempNode;

	if (root->m_pLeft)
		mirrorRecursively(root->m_pLeft);
	if (root->m_pRight)
		mirrorRecursively(root->m_pRight);
}
//���������з���ֵ�ĺ����ݹ����
BinaryTreeNode* mirrorRecursively2(BinaryTreeNode* root) {
	if (root == NULL)
		return NULL;

	BinaryTreeNode* tempNode = root->m_pLeft;
	root->m_pLeft = mirrorRecursively2(root->m_pRight);
	root->m_pRight = mirrorRecursively2(tempNode);

	return root;
}

int main()
{
	BinaryTreeNode* node1 = CreateNode(8);
	BinaryTreeNode* node2 = CreateNode(6);
	BinaryTreeNode* node3 = CreateNode(10);
	BinaryTreeNode* node4 = CreateNode(5);
	BinaryTreeNode* node5 = CreateNode(7);
	BinaryTreeNode* node6 = CreateNode(9);
	BinaryTreeNode* node7 = CreateNode(11);
	node1->m_pLeft = node2;
	node1->m_pRight = node3;
	node2->m_pLeft = node4;
	node2->m_pRight = node5;
	node3->m_pLeft = node6;
	node3->m_pRight = node7;
	PrintTree(node1);
	cout << endl;

	//mirrorRecursively(node1);
	//PrintTree(node1);

	BinaryTreeNode* node = mirrorRecursively2(node1);
	PrintTree(node);

    return 0;
}

