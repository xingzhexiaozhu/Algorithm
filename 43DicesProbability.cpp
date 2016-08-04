// 43DicesProbability.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//������������n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s�����п��ܵ�ֵ���ֵĸ���

//����˼·һ���Ƚ�n�����ӷ�Ϊ���ѣ���һ��ֻ��һ������һ����(n-1)������������һ�����ܳ���1-6�ĵ�����
//            ������Ҫ�����1��6�ĵ�����ÿ�ֵ�����ʣ�µ�(n-1)����������������ͣ�
//            ��������(n-1)�ֳ����ѣ���һ����1�����ڶ�����(n-2)�������ݹ���
//����һ������Ϊ(6n-n+1)�����飬��Ϊs�ĵ������ֵĴ������浽�����(s-n)��Ԫ������
void Probability(int original, int current, int sum, int* probabilities) {
	if (current == 1)
		probabilities[sum - original]++;
	else {
		for (int i = 1; i <= 6; i++)
			Probability(original, current - 1, i + sum, probabilities);
	}
}
void Probability(int n, int* probabilities) {
	for (int i = 1; i <= 6; i++)
		Probability(n, n, i, probabilities);
}
void PrintProbability(int n) {
	if (n < 1)
		return;

	int maxSum = 6 * n;
	int* probabilities = new int[maxSum - n + 1];
	for (int i = n;i <= maxSum;i++)
		probabilities[i - n] = 0;

	Probability(n, probabilities);

	int total = pow(6, n);
	for (int i = n; i < maxSum; i++) {
		double ratio = probabilities[i - n] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] probabilities;
}

//����˼·���������������飬��һ��ѭ���е�һ�������еĵ�n�����ֱ�ʾ���Ӻ�Ϊn���ֵĴ���������һ��ѭ���У����Ǽ���
//��һ���µ����ӣ���ʱ��Ϊn�����ӳ��ֵĴ�����Ӧ��һ��ѭ�������ӵ�����Ϊn-1��n-2��n-3��n-4��n-5��n-6�Ĵ����ܺ�
void PrintProbability2(int n) {
	if (n < 1)
		return;

	int* probabilities[2];
	probabilities[0] = new int[6 * n + 1];
	probabilities[1] = new int[6 * n + 1];
	for (int i = 0; i < 6 * n + 1; i++) {
		probabilities[0][i] = 0;
		probabilities[1][i] = 0;
	}

	int flag = 0;
	for (int i = 1; i <= 6; i++)
		probabilities[flag][i] = 1;

	for (int k = 2; k <= n; k++) {
		for (int i = 0; i < k; i++)
			probabilities[1 - flag][i] = 0;

		for (int i = k; i <= 6 * k; i++) {
			probabilities[1 - flag][i] = 0;
			for (int j = 1; j <= i&&j <= 6; j++)
				probabilities[1 - flag][i] += probabilities[flag][1 - j];
		}

		flag = 1 - flag;
	}

	double total = pow(6, n);
	for (int i = n; i <= 6 * n; i++) {
		double ratio = (double)probabilities[flag][i] / total;
		printf("%d : %e\n", i, ratio);
	}

	delete[] probabilities[0];
	delete[] probabilities[1];
}

int main()
{
	int n;
	while (cin >> n)
		PrintProbability2(n);

    return 0;
}

