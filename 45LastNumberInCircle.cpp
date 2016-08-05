// 45LastNumberInCircle.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<list>
using namespace std;

//����������0��1��������n-1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ����ɾ����m�����֡������ԲȦ�����ʣ�µ�һ������

//����˼·һ��ģ��һ������Ȼ��ÿ��ɾ����m�����֣������ƽ�
int LastRemaining(int n, int m) {
	if (n < 1 || m < 1)
		return -1;
		
	list<int> num;
	for (int i = 0; i < n; i++)
		num.push_back(i);

	list<int>::iterator cur = num.begin();
	while (num.size() > 1) {//����ɾ��list�е�m����
		for (int i = 1; i < m; i++) {//ÿ��ѭ���ҵ���n����
			cur++;
			if (cur == num.end())
				cur = num.begin();
		}

		list<int>::iterator next = ++cur;
		if (next == num.end())
			next = num.begin();

		--cur;
		num.erase(cur);//ɾ��������
		cur = next;
	}
	return *(cur);
}

//����˼·��������˼·���У�������ʱ�临�Ӷ�O(mn)����˻���ϣ������ɾ��������ʲô���ɡ�
//�ݹ鹫ʽ��         0  ,                 n = 1
//         f(n,m)= {
//                   [f(n-1,m)+m] % n ,   n > 1
int LastRemaining2(int n, int m) {
	if (n < 1 || m < 1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; i++)
		last = (last + m) % i;
	return last;
}

int main()
{
	int n, k;
	while (cin >> n >> k) {
		cout << LastRemaining(n, k) << " " << LastRemaining2(n, k) << endl;
	}

    return 0;
} 

