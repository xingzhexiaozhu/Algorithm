// BinaryTreeNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树，并输出二叉树的头结点。比如：
//前序{1,2,4,7,3,5,6,8}，中序{4,7,2,1,5,3,8,6}，

struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore(int * startPreorder, int *endPreOrder, int* startInorder, int* endInorder) {
	//先序遍历的第一个结点就是根结点
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

	//在中序遍历序列中找到根结点
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;

	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw exception("Invalid input");

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0) {
		//构建左子树
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreOrder - startPreorder) {
		//构建右子树
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreOrder, rootInorder + 1, endInorder);
	}

	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;//先序、中序序列为空，或者长度小于等于0，返回空

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

