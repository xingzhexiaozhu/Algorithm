// 8RotationArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;

//题意描述：输入一个递增排序的数组的一个旋转，输出该旋转数组的最小元素。例如：
//输入：{3,4,5,1,2}（即{1,2,3,4,5}的一个旋转），输出该数组的最小值

//解题思路：旋转数组的特点就是由两个递增子数组，利用二分查找的思想，
//分别用两个指针指向数组的第一个元素和最后一个元素，第一个元素应该是大于最后一个元素的，然后找到中间元素，
//如果中间元素位于前面的递增子数组，则它大于等于第一个指针指向的元素，此时把第一个指针指向该中间元素
//如果中间元素位于后面的递增子数组，则它小于等于第二个指针指向的元素，此时把第二个指针指向该中间元素
//不断缩小查找范围，最终第一个指针指向前面递增子数组的最后一个元素，第二个指针指向后面递增子数组的第一个元素，

//int Min(int* numbers, int length) {
//	if (numbers == NULL || length <= 0)
//		throw new exception("Invalid parameters!");
//
//	int index1 = 0;
//	int index2 = length - 1;
//	int indexMid = index1;
//	while (numbers[index1] >= numbers[index2]) {
//		if (index2 - index1 == 1) {//找到两个递增子数组，返回	
//			indexMid = index2;
//			break;
//		}
//
//		indexMid = (index1 + index2) / 2;
//		if (numbers[indexMid] >= numbers[index1])
//			index1 = indexMid;
//		else if (numbers[indexMid] <= numbers[index2])
//			index2 = indexMid;
//	}
//
//	return numbers[indexMid];
//}

//上面的解题存在问题，比如{1,0,1,1,1}、{1,1,1,0,1}，当第一个数字、最后一个数字和中间数字都是1时，
//我们无法确定中间的数字1属于第一个递增子数组还是第二个递增子数组。这种情况下我们就需要采用顺序查找
int MinInOrder(int* numbers, int index1, int index2) {
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; i++)
		if (result > numbers[i])
			result = numbers[i];

	return result;
}

int Min(int* numbers, int length) {
	if (numbers == NULL || length <= 0)
		throw new exception("Invalid parameters!");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {//找到两个递增子数组，返回	
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;
		//如果下标为index1、index2和indexMin指向的三个数字相等，则只能顺序查找
		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);

		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
}

int main()
{
	int data[] = { 3,4,5,1,2 };
	cout << Min(data, 5) << endl;

	int nums[] = { 1,1,1,0,1 };
	cout << Min(nums, 5) << endl;

    return 0;
}

