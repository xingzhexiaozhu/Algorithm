// 29MoreThanHalfNum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>//����sort()����
using namespace std;

//������������������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}������2

//����˼·һ���Ƚ���������������Խ������ŵ�˼�룻Ȼ���������ֳ��ִ����������鳤�ȵ�һ�룬����ֱ�ӷ���(n/2)�������ּ���
int moreThanHalfNum(vector<int> num) {
	if (num.size() == 0)
		return -1;
	sort(num.begin(), num.end());
	return num[num.size() / 2];
}

//����˼·������Ϊ������ĳ���ֳ��ִ�������һ�룬���Դ�ͷ��ʼͳ�����֣�
//����һ����������һ��������ͬ������+1����ͬ����-1��������Ϊ0ʱ�����±�����һ�����ֲ����ü���Ϊ1
//���һ�ΰѴ�������Ϊ1�����ּ�Ϊ����
int moreThanHalfNum2(vector<int> num) {
	if (num.size() == 0)
		return -1;
	int res = num[0];//����
	int count = 1;//����
	for (int i = 1; i < num.size(); i++) {
		if (count == 0) {
			res = num[i];
			count = 1;
		}else if (res == num[i])
				count++;
		else count--;
	}

	return res;
}

int main()
{
	vector<int> num = { 1,2,3,2,2,2,5,4,2 };
	
	cout << moreThanHalfNum(num) << endl;

	cout << moreThanHalfNum2(num) << endl;

    return 0;
}

