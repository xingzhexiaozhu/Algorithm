// 27ConvertBinarySearchTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
//�磺����������       10
//                    /  \
//                   6    14
//                 / \    / \
//                4   8  12  16
//��Ӧ��ת�����˫������[4<>6<>8<>10<>12<>14<>16]

struct BinaryTreeNode {
	int val;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

//����˼·���������������������������ģ����������Ĵ���һ�㶼�ǵݹ���бȽϷ��㣬
//���ｫ���ֳ������������Ƚ����������Ľ��ֱ��ų�˫������Ȼ���������������͸����ʹ�����ų�˫������
//�����������ǽ�������pLeftָ��������˳���ǰһ����㣬��pRightָ������˳��ĺ�һ�����
void ConvertToList(BinaryTreeNode* root, BinaryTreeNode**pNode);

BinaryTreeNode* ConvertToList(BinaryTreeNode* root) {
	BinaryTreeNode* pNode = NULL;
	ConvertToList(root, &pNode);
	
	//������һ���õ���˫������pNodeÿ��ָ���������һ����㣬��������Ҫ�ҵ�ͷ��㷵��
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

//�����������������
void ShowTree(BinaryTreeNode* root) {
	if (root->pLeft != NULL)
		ShowTree(root->pLeft);
	cout << root->val << " ";
	if (root->pRight != NULL)
		ShowTree(root->pRight);
}

//˫�����˫������
void ShowList(BinaryTreeNode* head) {
	BinaryTreeNode* pNode = head;
	cout << "�������˫������";
	while (pNode->pRight != NULL) {
		cout << pNode->val << " ";
		pNode = pNode->pRight;
	}
	cout << pNode->val << endl;

	cout << "�������˫������";
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
	
	cout << "��ʼ���������������������";
	ShowTree(root);
	cout << endl;

	BinaryTreeNode* head = ConvertToList(root);
	ShowList(head);

    return 0;
}

