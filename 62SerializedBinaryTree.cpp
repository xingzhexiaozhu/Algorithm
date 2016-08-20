// 62SerializedBinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<sstream>
using namespace std;

//题意描述：请实现两个函数，分别用来序列化和反序列化二叉树

struct BinaryTreeNode
{
	int val;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

//序列化
void Serialize(BinaryTreeNode* pRoot) {
	if (pRoot == NULL) {
		cout << "$,";
		return;
	}

	cout << pRoot->val << ",";
	Serialize(pRoot->pLeft);
	Serialize(pRoot->pRight);
}
//反序列化
void DeSerialize(BinaryTreeNode** pRoot) {
	int number;
	if (cin>>number) {
		*pRoot = new BinaryTreeNode();
		(*pRoot)->val = number;
		(*pRoot)->pLeft = NULL;
		(*pRoot)->pRight = NULL;

		DeSerialize(&((*pRoot)->pLeft));
		DeSerialize(&((*pRoot)->pRight));
	}
}

int main()
{
	/*BinaryTreeNode* node1 = new BinaryTreeNode();
	BinaryTreeNode* node2 = new BinaryTreeNode();
	BinaryTreeNode* node3 = new BinaryTreeNode();
	BinaryTreeNode* node4 = new BinaryTreeNode();
	BinaryTreeNode* node5 = new BinaryTreeNode();

	node1->val = 1;
	node2->val = 2;
	node3->val = 3;
	node4->val = 4;
	node5->val = 5;

	node1->pLeft = node2;
	node1->pRight = node3;
	node2->pLeft = node4;
	node2->pRight = node5;

	Serialize(node1);*/

	int n[][3] = { 10,20,30,40,50,60 };
	int(*p)[3];
	p = n;

	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;

	int a = 0, b = 0, c = 0, x=35;
	if (!a) x--;
	else if (b);
	if (c) x = 3;
	else x = 4;
	cout << x << endl;


    return 0;
}

