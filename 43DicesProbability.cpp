// 43DicesProbability.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率

//解题思路一：先将n个骰子分为两堆，第一堆只有一个，另一堆有(n-1)个，单独的那一个可能出现1-6的点数。
//            我们需要计算从1到6的点数，每种点数和剩下的(n-1)个骰子来计算点数和；
//            接下来把(n-1)分成两堆，第一堆有1个，第二堆有(n-2)个……递归解决
//定义一个长度为(6n-n+1)的数组，和为s的点数出现的次数保存到数组第(s-n)个元素里面
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

//解题思路二：采用两个数组，在一次循环中第一个数组中的第n个数字表示骰子和为n出现的次数。在下一次循环中，我们加上
//上一个新的骰子，此时和为n的骰子出现的次数对应上一次循环中骰子点数和为n-1、n-2、n-3、n-4、n-5、n-6的次数总和
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

