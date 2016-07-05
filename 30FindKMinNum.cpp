// 30FindKMinNum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

#include<set>

using namespace std;

//��������������n���������ҳ�������С��k��������������4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4

//����˼·һ���Ƚ�n����������Ȼ�����k����С�����ּ���
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

//����˼·��������һ����СΪk�������������洢��С��k�����֣�ÿ�δ�n�������ж���һ�����֣�
//������������е�����С��k����ֱ�Ӽ����������������������k�����֣���
//(1)�ҵ������Ǹ����֣�
//(2)������������ɾ�����������
//(3)���ܲ���һ���µ����֣�
//�������ʵ��һ��С���󣩶���
void HeapAdjustDown(int* arr, int start, int end){
	int temp = arr[start];  //���浱ǰ�ڵ�  
	int i = 2 * start + 1;      //�ýڵ�������������е�λ�����  
	while (i <= end){
		//�ҳ����Һ�������С���Ǹ�  
		if (i + 1 <= end && arr[i + 1]<arr[i])
			i++;
		//������϶ѵĶ��壬���õ���λ��  
		if (arr[i] >= temp)
			break;
		//��С���ӽڵ������ƶ����滻���丸�ڵ�  
		arr[start] = arr[i];
		start = i;
		i = 2 * start + 1;
	}
	arr[start] = temp;
}
//�õ���С��k������������arr�е������k��λ��
void MinHeapKNum(int* arr, int len, int k){
	if (arr == NULL || len<1 || k<1 || k>len)
		return;

	int i;
	//�����齨��ΪС����  
	//��һ����Ҷ�ӽڵ��λ�����Ϊ(len-1)/2  
	for (i = (len - 1) / 2;i >= 0;i--)
		HeapAdjustDown(arr, i, len - 1);
	//���ж�����  
	for (i = len - 1;i >= len - k;i--)
	{
		//�Ѷ�Ԫ�غ����һ��Ԫ�ؽ���λ�ã�  
		//��������һ��λ�ñ��������С������  
		//ÿ��ѭ�����ν���С����ֵ�ڷŽ���ǰ��һ��λ�ã�  
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		//��arr[0...i-1]���µ���ΪС����  
		HeapAdjustDown(arr, 0, i - 1);
	}
}


int main()
{
	vector<int> num = {4,5,6,1,2,7,3,8};
	int k = 4;

	//�ⷨһ��
	vector<int> res = findKMinNum(num, k);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	//�ⷨ����
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

