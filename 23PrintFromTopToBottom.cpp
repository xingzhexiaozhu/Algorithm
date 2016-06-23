// 23PrintFromTopToBottom.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<queue>
using namespace std;

//�������������ϵ��´�ӡ��������ÿ����㣬ͬһ��Ľ�㰴�մ����ҵ�˳���ӡ����
//      8
//     / \
//    6   10
//   / \  / \
//  5  7 9   11
//�������°���δ�ӡ8��6��10��5��7��9��11

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//����˼·���������в�α����������������ӡ�����������
void printFromTopToBottom(BinaryTreeNode* pTreeRoot) {
	if (!pTreeRoot)
		return;
	queue<BinaryTreeNode *> q;

	q.push(pTreeRoot);
	while (q.size()) {
		BinaryTreeNode* pNode = q.front();//ȡ������Ԫ��
		q.pop();//����Ԫ�س���

		cout << pNode->m_nValue<<"\t";

		if (pNode->m_pLeft)
			q.push(pNode->m_pLeft);
		if (pNode->m_pRight)
			q.push(pNode->m_pRight);
	}
}

//�������������
BinaryTreeNode* CreateBinaryTreeNode(int value) {
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;
	return pNode;
}

//���Ӷ��������
void ConnectionTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if (pParent != NULL) {
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

//�������
void PreOrder(BinaryTreeNode* pTreeRoot) {
	cout << pTreeRoot->m_nValue << "\t";
	if (pTreeRoot->m_pLeft != NULL)
		PreOrder(pTreeRoot->m_pLeft);
	if (pTreeRoot->m_pRight != NULL)
		PreOrder(pTreeRoot->m_pRight);
}
//�������
void InOrder(BinaryTreeNode* pTreeRoot) {
	if (pTreeRoot->m_pLeft != NULL)
		InOrder(pTreeRoot->m_pLeft);
	cout << pTreeRoot->m_nValue << "\t";
	if (pTreeRoot->m_pRight != NULL)
		InOrder(pTreeRoot->m_pRight);
}
//�������
void AfterOrder(BinaryTreeNode* pTreeRoot) {
	if (pTreeRoot->m_pLeft != NULL)
		InOrder(pTreeRoot->m_pLeft);	
	if (pTreeRoot->m_pRight != NULL)
		InOrder(pTreeRoot->m_pRight);
	cout << pTreeRoot->m_nValue << "\t";
}

int main()
{
	BinaryTreeNode* node1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* node2 = CreateBinaryTreeNode(6);
	BinaryTreeNode* node3 = CreateBinaryTreeNode(10);
	BinaryTreeNode* node4 = CreateBinaryTreeNode(5);
	BinaryTreeNode* node5 = CreateBinaryTreeNode(7);
	BinaryTreeNode* node6 = CreateBinaryTreeNode(9);
	BinaryTreeNode* node7 = CreateBinaryTreeNode(11);

	ConnectionTreeNodes(node1, node2, node3);
	ConnectionTreeNodes(node2, node4, node5);
	ConnectionTreeNodes(node3, node6, node7);

	PreOrder(node1);
	cout << endl;

	InOrder(node1);
	cout << endl;

	AfterOrder(node1);
	cout << endl;

	printFromTopToBottom(node1);
	
    return 0;
}

