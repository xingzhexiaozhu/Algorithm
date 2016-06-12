// BinaryTreeNode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������ĳ��������ǰ���������������Ľ�������ؽ����ö��������������������ͷ��㡣���磺
//ǰ��{1,2,4,7,3,5,6,8}������{4,7,2,1,5,3,8,6}��

struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore(int * startPreorder, int *endPreOrder, int* startInorder, int* endInorder) {
	//��������ĵ�һ�������Ǹ����
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	if (startPreorder == endPreOrder) {
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw exception("Invalid input");
	}

	//����������������ҵ������
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;

	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw exception("Invalid input");

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0) {
		//����������
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreOrder - startPreorder) {
		//����������
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreOrder, rootInorder + 1, endInorder);
	}

	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;//������������Ϊ�գ����߳���С�ڵ���0�����ؿ�

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

int main()
{
	int preNode[] = { 1,2,4,7,3,5,6,8 };
	int inNode[] = { 4,7,2,1,5,3,8,6 };

	BinaryTreeNode* node = Construct(preNode, inNode, 8);

	cout << node->m_nValue << endl;

    return 0;
}

