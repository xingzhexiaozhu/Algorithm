// 30FindKMinNum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

#include<set>

using namespace std;

//题意描述：输入n个整数，找出其中最小的k个数。例如输入4，5，1，6，2，7，3，8这8个数字，则最小的4个数字是1，2，3，4

//解题思路一：先将n个整数排序，然后输出k个最小的数字即可
vector<int> findKMinNum(vector<int> num, int k) {
	sort(num.begin(), num.end());
	vector<int> res;

	//for each (int var in num)
	//	cout << var << " ";
	//cout << endl;

	for (int i = 0; i < k; i++)
		res.push_back(num[i]);
	return res;
}

//解题思路二：创建一个大小为k的数据容器来存储最小的k个数字，每次从n个整数中读入一个数字，
//如果容器中已有的数字小于k个则直接加入容器，如果容器中已有k个数字，则：
//(1)找到最大的那个数字；
//(2)可能在容器中删除该最大数；
//(3)可能插入一个新的数字；
//因此这里实现一个小（大）顶堆
void HeapAdjustDown(int* arr, int start, int end){
	int temp = arr[start];  //保存当前节点  
	int i = 2 * start + 1;      //该节点的左孩子在数组中的位置序号  
	while (i <= end){
		//找出左右孩子中最小的那个  
		if (i + 1 <= end && arr[i + 1]<arr[i])
			i++;
		//如果符合堆的定义，则不用调整位置  
		if (arr[i] >= temp)
			break;
		//最小的子节点向上移动，替换掉其父节点  
		arr[start] = arr[i];
		start = i;
		i = 2 * start + 1;
	}
	arr[start] = temp;
}
//得到最小的k个数，保存在arr中的最后面k个位置
void MinHeapKNum(int* arr, int len, int k){
	if (arr == NULL || len<1 || k<1 || k>len)
		return;

	int i;
	//把数组建成为小顶堆  
	//第一个非叶子节点的位置序号为(len-1)/2  
	for (i = (len - 1) / 2;i >= 0;i--)
		HeapAdjustDown(arr, i, len - 1);
	//进行堆排序  
	for (i = len - 1;i >= len - k;i--)
	{
		//堆顶元素和最后一个元素交换位置，  
		//这样最后的一个位置保存的是最小的数，  
		//每次循环依次将次小的数值在放进其前面一个位置，  
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		//将arr[0...i-1]重新调整为小顶堆  
		HeapAdjustDown(arr, 0, i - 1);
	}
}


int main()
{
	vector<int> num = {4,5,6,1,2,7,3,8};
	int k = 4;

	//解法一：
	vector<int> res = findKMinNum(num, k);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	//解法二：
	int arr[] = { 4,5,6,1,2,7,3,8 };
	int n = 8;
	MinHeapKNum(arr, n, k);
	for (int i = n - 1; i >= n - k; i--) {
		if (i == n - k)
			cout << arr[i] <<endl;
		else cout << arr[i] << " ";
	}

    return 0;
}

