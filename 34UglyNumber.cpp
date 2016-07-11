// 34UglyNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：我们把只包含因子2、3、5的数称作丑数（Ugly Number）.求按从小到大的顺序的第1500个丑数。
//例如6、8都是丑数，但14不为丑数因为它包含因子7。习惯上我们把1当作第一个丑数

//解题思路一：逐个判断数字是否为丑数，如果是丑数计数加1，如果不是则继续判断下一个
bool isUglyNumber(int n) {//判断数字n是否为丑数
	while ((n >= 5) && (n % 5 == 0))
		n = n / 5;
	while ((n >= 3) && (n % 3 == 0))
		n = n / 3;
	while ((n >= 2) && (n % 2 == 0))
		n = n / 2;

	return (n == 1) ? true : false;
}
int GetUglyNumber(int index) {//求第index个丑数
	if (index <= 0)
		return 0;

	int count = 0;
	int num;
	for (num = 1; count != index; ++num)
		if (isUglyNumber(num))
			++count;
	return num - 1;
}

//解题思路二：前面的计算效率低是因为对每个数不论是否为丑数，都要对其进行判断.
//根据定义一个丑数应该是另一个丑数乘2、3或5的结果，因此可以创建一个数组，保存已求得的丑数
int Min(int num1, int num2, int num3) {
	int min = (num1 < num2) ? num1 : num2;
	min = (min < num3) ? min : num3;
	return min;
}
int GetUglyNumber2(int index) {
	if (index <= 0)
		return 0;

	int* pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *p2 = pUglyNumbers;
	int *p3 = pUglyNumbers;
	int *p5 = pUglyNumbers;

	while (nextUglyIndex < index) {
		int min = Min(*p2 * 2, *p3 * 3, *p5 * 5);
		while (*p2 * 2 < pUglyNumbers[nextUglyIndex])
			++p2;
		while (*p3 * 3 < pUglyNumbers[nextUglyIndex])
			++p3;
		while (*p5 * 5 < pUglyNumbers[nextUglyIndex])
			++p5;

		++nextUglyIndex;
	}

	int theNumber = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return theNumber;
}


int main()
{
	cout << GetUglyNumber2(150) << endl;//得到第150个丑数

    return 0;
}

