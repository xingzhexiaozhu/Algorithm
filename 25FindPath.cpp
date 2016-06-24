// 25FindPath.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

//��������������һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·�����磺
//     10
//    /  \
//   5   12
//  / \
// 4   7

//����˼·������ջ������������ȱ����������ǰ���ΪҶ�ӽ�㲢�ҴӸ���㵽��ǰ����ֵ�ĺ͵��ڸ���ֵ�����ҵ�һ��·������ӡ
//���������Ҷ���������߷�����һ����������һ��ʱ��Ҫ�ڵ�ǰ����ĺ͵Ļ����ϼ�ȥ��ǰ����ֵ

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

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


void findPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int currentSum) {
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	//�����Ҷ��㣬����·���Ͻ��ĺ͵��������ֵ��ӡ������·��
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

	//�������Ҷ���
	if (pRoot->m_pLeft != NULL)
		findPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if (pRoot->m_pRight != NULL)
		findPath(pRoot->m_pRight, expectedSum, path, currentSum);

	//�ڷ��ظ����֮ǰ����·����ɾ����ǰ���
	path.pop_back();
}

void findPath(BinaryTreeNode* pRoot, int expectedSum) {
	if (pRoot == NULL)
		return;

	vector<int> path;
	int currentSum = 0;
	findPath(pRoot, expectedSum, path, currentSum);
}


//�������
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
