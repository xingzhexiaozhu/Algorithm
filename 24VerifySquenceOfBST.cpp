// VerifySquenceOfBST.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ���������飬�жϸ������ǲ���ĳ�������������ĺ�������Ľ����������򷵻�true�����򷵻�false
//�������������������������ֶ�������ͬ�����������5��7��6��9��11��10��8������true�������7��4��6��5������false

//����˼·���ں�����������У����һ������������Ҫ����ֵ��ǰ������ֿɷ�Ϊ�������֣���һ��������������ֵ���ȸ�ֵС��
//�ڶ���������������ֵ���ȸ��󡣰�Щ���ɣ������жϣ�������鴦��������Ǻ���������У�����Ϊ�����������
bool VerifySequenceOfBST(int sequence[], int length) {
	if (sequence == NULL || length <= 0)
		return false;

	int root = sequence[length - 1];
	
	//�ڶ������������������Ľ��ֵС�ڸ����ֵ
	int i = 0;
	for (; i < length - 1; i++) {
		if (sequence[i] > root)
			break;
	}		

	//�ڶ����������������Ľ��ֵ���ڸ����ֵ
	int j = i;
	for (; j < length - 1; j++) {
		if (sequence[j] < root)
			return false;
	}
		
	//�ж��������ǲ��Ƕ���������
	bool left = true;
	if (i > 0)
		left = VerifySequenceOfBST(sequence, i);

	//�ж��������ǲ��Ƕ���������
	bool right = true;
	if (i < length - 1)
		right = VerifySequenceOfBST(sequence + i, length - i - 1);

	return (left && right);
}

int main()
{
	int test1[] = { 5,7,6,9,11,10,8 };
	int len1 = sizeof(test1) / sizeof(test1[0]);
	cout << VerifySequenceOfBST(test1, len1) << endl;

	int test2[] = { 7,4,6,5 };
	int len2 = sizeof(test2) / sizeof(test2[0]);
	cout << VerifySequenceOfBST(test2, len2) << endl;

    return 0;
}

