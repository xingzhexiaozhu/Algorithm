// VerifySquenceOfBST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：输入一个整数数组，判断该数组是不是某个二叉搜索树的后序遍历的结果。如果是则返回true，否则返回false
//假设输入的数组的任意两个数字都互不相同。例如输入｛5，7，6，9，11，10，8｝返回true；输入｛7，4，6，5｝返回false

//解题思路：在后序遍历序列中，最后一个数字是树的要结点的值，前面的数字可分为两个部分：第一部分是左子树，值都比根值小；
//第二部分是右子树，值都比根大。按些规律，依次判断，如果数组处理完毕则是后序遍历序列，否则不为后序遍历序列
bool VerifySequenceOfBST(int sequence[], int length) {
	if (sequence == NULL || length <= 0)
		return false;

	int root = sequence[length - 1];
	
	//在二叉搜索树中左子树的结点值小于根结点值
	int i = 0;
	for (; i < length - 1; i++) {
		if (sequence[i] > root)
			break;
	}		

	//在二叉搜索树右子树的结点值大于根结点值
	int j = i;
	for (; j < length - 1; j++) {
		if (sequence[j] < root)
			return false;
	}
		
	//判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0)
		left = VerifySequenceOfBST(sequence, i);

	//判断左子树是不是二叉搜索树
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

