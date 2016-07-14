// 36InversePairs.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//�����������������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
//����һ�����飬�����������е�����Ե�����

//����˼·һ��ÿɨ�赽һ�����־�����Ƚϸ����ֺ�����������ֵĴ�С������Ⱥ��������С�����������־����һ�������
//����n�����ֵ��㷨ʱ�临�Ӷ�ΪO(n^2)
int InversePairs(int* data, int length) {
	if (data == NULL || length < 2)
		return 0;

	int totalInversePairs = 0;
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1;j < length;j++) {
			if (data[i] > data[j])
				++totalInversePairs;
		}
	}
	return totalInversePairs;
}

//����˼·����Ϊ����ʱ�临�Ӷ�ΪO(n^2)��ÿ��ɨ������ʱ���������ͺ�������ֱȽ�
//������ݹ黮�ֳ����������飬��ÿ�������鳤��Ϊ1�������κϲ����������飬���������������������Լ����ӣ�������
//��ȫ��������ϡ�ʱ�临�Ӷ�ΪO(nlogn)
int InversePairsCore(int* data, int* copy, int start, int end) {
	if (start == end) {
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;
	
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start&&j >= start + length + 1) {
		if (data[i] > data[j]) {
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else {
			copy[indexCopy--] = data[j--];
		}
	}

	for (;i >= start;--i)
		copy[indexCopy--] = data[i];
	for (;j >= start + length + 1;--j)
		copy[indexCopy--] = data[j];

	return left + right + count;
}
int InversePairs2(int* data, int length) {
	if (data == NULL || length < 0)
		return 0;
	
	int* copy = new int[length];
	for (int i = 0; i < length; i++)
		copy[i] = data[i];

	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;

	return count;
}


int main()
{
	int data[] = { 7,5,6,4 };
	cout << InversePairs(data, sizeof(data) / sizeof(data[0])) << endl;
	
	cout<<InversePairs2(data, sizeof(data) / sizeof(data[0])) << endl;

    return 0;
}

