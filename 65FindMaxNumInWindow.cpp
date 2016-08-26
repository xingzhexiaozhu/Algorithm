// 65FindMaxNumInWindow.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>

#include<deque>

using namespace std;

//��������������һ������ͻ������ڵĴ�С�����ҳ����л�������������ֵ�����磬������������2��3��4��2��6��2��5��1�����������ڴ�СΪ3��
//��ôһ������6���������ڣ����ǵ����ֵΪ��4��4��6��6��6��5��

//����˼·һ������������⣬�㷨ʱ�临�Ӷ�ΪO(nk)
int findMax(vector<int> num, int low, int high) {
	int max = num[low];
	for(int i=low+1; i<high; i++)
		if(num[i] > max)
			max = num[i];
	return max;
}
vector<int> MaxNumInWindow(vector<int> num, int k) {
	vector<int> res;
	int len = num.size();

	int high = (len < k ? len : k);

	for (int low = 0; high <= len; low++, high++)
		res.push_back(findMax(num, low, high));
	
	return res;
}

//����˼·����
vector<int> maxInWindows(const vector<int>& num, int size) {
	vector<int> maxInWindows;
	if (num.size() >= size && size >= 1) {
		deque<int> index;
		for (int i = 0; i < size; i++) {
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			index.push_back(i);
		}
		for (int i = size; i < num.size(); i++) {
			maxInWindows.push_back(num[index.front()]);
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			if (!index.empty() && index.front() <= (i - size))
				index.pop_front();

			index.push_back(i);
		}
		maxInWindows.push_back(num[index.front()]);
	}
	return maxInWindows;
}

int main()
{
	vector<int> num = {2,3,4,2,6,2,5,1};

	vector<int> res = MaxNumInWindow(num, 3);
	for (int x : res)
		cout << x << " ";
	cout << endl;

	vector<int> res2 = MaxNumInWindow(num, 3);
	for (int x : res2)
		cout << x << " ";
	cout << endl;

    return 0;
}

