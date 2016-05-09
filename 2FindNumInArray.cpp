// FindNumInArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;

//题意描述：在一个二维数组中，每一行都按从左到右的递增顺序排序，每一列也按照从上到下的递增顺序排序
//完成函数，输入一个这样的一个二维数组和一个整数，判断是否含有该整数
//例如：
//1	 2	8	9
//2	 4	9	12
//4  7	10	13
//6  8	11	15
//如果查找7返回true，如果查找5返回false

//解题思路：依次从右上遍历，如果当前值等于给定值，返回true
//          如果当前值大于给定值，则排除当前值所在整列，然后左移一列再遍历，当左边没有列时返回false
//          如果当前值小于给定值，则排除当前值所在整行，然后下移一行再遍历，当下面没有行时返回false
//之所以这样做是因为可以缩小查找范围（从左下、右上开始均可）

bool find(int* matrix, int rows, int columns, int num) {
	bool found = false;

	if (matrix != NULL && rows > 0 && columns > 0) {
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0) {
			if (matrix[row*columns + column] == num) {
				found = true;
				break;
			}
			else if (matrix[row*columns + column] > num)
				column--;
			else row++;
		}
	}

	return found;
}

int main()
{
	int array[] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
	
	bool found = find(array, 4, 4, 7);
	if (found) cout << "true" << endl;
	else cout << "false" << endl;

	found = find(array, 4, 4, 5);
	if(found) cout << "true" << endl;
	else cout << "false" << endl;

    return 0;
}

