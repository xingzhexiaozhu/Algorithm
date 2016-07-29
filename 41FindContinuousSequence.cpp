// 41FindContinuousSequence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ������Num����ӡ�����к�ΪNum�������������У����ٺ�����������
//��������15������1+2+3+4+5=14+5+6=7+8=15�����Դ�ӡ3������������1-5��4-6��7-8

//����˼·�������һ��Ŀ��˼·����Ϊ���������������������������֣������������������ֲ���ʼ��begin=1��end=2�������к�Ϊ3��
//��Num=9Ϊ����3<9��end=3�����к�Ϊ6��	6<9��end=4�����к�Ϊ10��	10>9��bedgin=2�����к�Ϊ9�� Ȼ���������ƣ���beginΪ(Num+1)/2���ҵ����з���������
void PrintSequence(int begin, int end) {//��ӡ����
	for (int i = begin; i <= end; i++)
		cout << i << " ";
	cout << endl;
}
void FindContinuousSequence(int num) {//������
	if (num < 3)
		return;

	int begin = 1, end = 2;
	int curSum = begin + end;
	int threshold = (num + 1) / 2;
	while (begin < threshold) {
		if (curSum == num)
			PrintSequence(begin, end);
		//else if (curSum < num) {//����ⷨ������ѭ��
		//	++end;
		//	curSum += end;
		//}
		//else {
		//	curSum -= begin;
		//	++begin;
		//}
		while (curSum > num && begin < threshold) {
			curSum -= begin;
			begin++;

			if (curSum == num)
				PrintSequence(begin, end);
		}
		end++;
		curSum += end;
	}
}

int main()
{
	int num;
	while (cin >> num) {
		FindContinuousSequence(num);
	}

    return 0;
}

