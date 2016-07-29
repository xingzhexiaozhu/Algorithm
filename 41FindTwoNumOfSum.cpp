// 41FindTwoNumOfSum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<map>
using namespace std;

//��������������һ����������������һ������Sum���������в�����������ʹ�����ǵĺ�������Sum������ж�Ժ�ΪSum���������һ�Լ���

//����˼·һ����Java������HashMap���ϣ�key = Sum - curNum��value = curNum��ÿ��������һ������ʱ���жϸ������Ƿ���map�е�key���ֹ����������ҵ�
//ͬ��ʹ��set
bool FindNumersWithSum(int data[], int len, int sum, int* num1, int* num2) {
	if (data == NULL || len <= 0)
		return false;

	map<int, int> mymap;
	for (int i = 0; i < len; i++) {
		map<int, int>::iterator it = mymap.find(data[i]);
		if (it != mymap.end()) {//�ҵ�����
			*num1 = it->first;
			*num2 = it->second;
			return true;
		}
		//���û�ҵ�����������뵱ǰ��ֵ�ԣ�key=sum-data[i]��value=data[i]
		mymap.insert(pair<int, int>(sum - data[i], data[i]));
	}
	return false;
}
//����˼·����ʹ������ָ�룬���һ��ָ��ָ������ͷ���ڶ���ָ��ָ������β��Ȼ����ͣ�
//           >sum�ڶ���ָ��ǰ�ƣ�<sum���һ��ָ����ƣ�=sum�򷵻�
bool FindNumbersWithSum2(int data[], int len, int sum, int* num1, int* num2) {
	if (data == NULL || len <= 0)
		return false;

	int ahead = 0, tail = len - 1;
	while (tail > ahead) {
		if (data[ahead] + data[tail] > sum) {
			tail--;
		}
		else if(data[ahead] + data[tail] < sum) {
			ahead++;
		}else {
			*num1 = data[ahead];
			*num2 = data[tail];
			return true;
		}
	}

	return false;
}

int main()
{
	int num[] = { 1,2,4,7,11,15 };
	int num1, num2, sum = 15;
	//if (FindNumersWithSum(num, sizeof(num) / sizeof(int), sum, &num1, &num2)) {
	//	cout << num1 << "\t" << num2 << endl;
	//}
	//else cout << "Not Found!" << endl;

	if (FindNumbersWithSum2(num, sizeof(num) / sizeof(int), sum, &num1, &num2)) {
		cout << num1 << "\t" << num2 << endl;
	}
	else cout << "Not Found!" << endl;

    return 0;
}

