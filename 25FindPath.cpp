// 25FindPath.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

//题意描述：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。如：
//     10
//    /  \
//   5   12
//  / \
// 4   7

//解题思路：借助栈，进行深度优先遍历，如果当前结点为叶子结点并且从根结点到当前结点的值的和等于给定值，则找到一条路径并打印
//否则继续向叶结点遍历或者返回上一级，返回上一级时需要在当前计算的和的基础上减去当前结点的值

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


void findPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int currentSum) {
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	//如果是叶结点，并且路径上结点的和等于输入的值打印出这条路径
	bool isLeaf = (pRoot->m_pLeft == NULL) && (pRoot->m_pRight == NULL);
	
	if (isLeaf && (currentSum == expectedSum)) {
		cout << "A path is found: ";
		//vector<int>::iterator it = path.begin();
		//for (; it != path.end(); ++it)
		//	cout << *it << " ";
		for (vector<int>::size_type i = 0; i < path.size(); i++)
			cout << path[i] << " ";
		cout << endl;
	}

	//如果不是叶结点
	if (pRoot->m_pLeft != NULL)
		findPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if (pRoot->m_pRight != NULL)
		findPath(pRoot->m_pRight, expectedSum, path, currentSum);

	//在返回父结点之前，在路径上删除当前结点
	path.pop_back();
}

void findPath(BinaryTreeNode* pRoot, int expectedSum) {
	if (pRoot == NULL)
		return;

	vector<int> path;
	int currentSum = 0;
	findPath(pRoot, expectedSum, path, currentSum);
}


//先序遍历
void InOrder(BinaryTreeNode* pTreeRoot) {	
	if (pTreeRoot->m_pLeft != NULL)
		InOrder(pTreeRoot->m_pLeft);
	cout << pTreeRoot->m_nValue << " ";
	if (pTreeRoot->m_pRight != NULL)
		InOrder(pTreeRoot->m_pRight);
}

int main()
{
	BinaryTreeNode* node1 = CreateBinaryTreeNode(10);
	BinaryTreeNode* node2 = CreateBinaryTreeNode(5);
	BinaryTreeNode* node3 = CreateBinaryTreeNode(12);
	BinaryTreeNode* node4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* node5 = CreateBinaryTreeNode(7);

	ConnectionTreeNodes(node1, node2, node3);
	ConnectionTreeNodes(node2, node4, node5);

	InOrder(node1);
	cout << endl;

	findPath(node1, 22);

    return 0;
}

//*************************************
//class A {
//public:
//	A() {
//		show();
//	}
//	~A() {
//		show();
//	}
//	virtual void show() {
//		cout << "A" << endl;
//	}
//};
//
//class B : public A {
//public:
//	B() {
//		show();
//	}
//
//	~B() {
//		show();
//	}
//
//	 virtual void show() override{
//		cout << "B" << endl;
//	}
//};
//
//int main() {
//	A* a = new B();
//	delete a;
//}

//******************************
