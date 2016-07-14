// 37FirstCommonNode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//�����������������������ҳ����ǵ�һ���������
struct  ListNode
{
	int value;
	ListNode* pNext;
};

//����˼·������ÿ����㶼��һ��pNextָ�룬����������й�����㣬��ӵ�һ����������������ȫ�غϣ�������й�����㣬�����й���β���� 
//��������ķ�������Ϳ��Ե�������������ˣ���˽ⷨһ�ǲ���ջ���ռ任ʱ�䣩���ⷨ����������ã����£�
//�ֱ�õ���������m��n���ϳ���������|m-n|����Ȼ��ͬ�������������ĵ�һ��������㼴Ϊ����
int GetListLength(ListNode *head) {//����������
	int len = 0;
	ListNode* tempNode = head;
	while (tempNode != NULL){
		++len;
		tempNode = tempNode->pNext;
	}

	return len;
}
ListNode* FirstCommonNode(ListNode* head1, ListNode* head2) {
	int m = GetListLength(head1);
	int n = GetListLength(head2);

	//�ֱ�õ�������Ͷ����������߳��Ȳ�
	ListNode* LongList = head1;
	ListNode* ShortList = head2;
	int diffLen = m - n;
	if (m < n) {
		LongList = head2;
		ShortList = head1;
		diffLen = n - m;
	}

	for (int i = 0;i < diffLen;i++)//�������ȴ�ͷ���ǰ��diffLen������
		LongList = LongList->pNext;

	while (LongList != NULL && ShortList != NULL && LongList->value != ShortList->value) {
		LongList = LongList->pNext;
		ShortList = ShortList->pNext;
	}
	return LongList;
}

int main()
{
	ListNode* node1 = new ListNode();
	ListNode* node2 = new ListNode();
	ListNode* node3 = new ListNode();
	ListNode* node4 = new ListNode();
	ListNode* node5 = new ListNode();
	ListNode* node6 = new ListNode();
	ListNode* node7 = new ListNode();

	node1->value = 1;
	node2->value = 2;
	node3->value = 3;

	node4->value = 6;
	node5->value = 7;
	
	node6->value = 4;
	node7->value = 5;

	node1->pNext = node2;
	node2->pNext = node3;
	node3->pNext = node4;

	node4->pNext = node5;

	node6->pNext = node7;
	node7->pNext = node4;

	ListNode* node = FirstCommonNode(node1, node6);
	cout << node->value << endl;

    return 0;
}

