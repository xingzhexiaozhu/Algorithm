// 40OnceNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<set>
using namespace std;

//题意描述：一个数组中除了一个数字出现了一次，其他数字均出现了两次，请写程序寻找出这个数字

//解题思路一：在Java中可以用HashSet数据结构，当元素出现第二次就删除，最后留下的元素即为所求
//解题思路二：利用异或运算，3^5=6、6^5=3，所以当完成一次遍历，即找到所求，且这种方法效率最高
int findSingleNum(int data[], int len) {
	if (data == NULL || len <= 0)
		return -1;

	int res =  0;
	for (int i = 0; i < len; i++)
		res = res ^ data[i];

	return res;
}


//题目升级：一个数组中除了两个数字只出现了一次，其他数字均出现了两次，请写程序找出这两个数字

//解题思路一：跟上一题思路一一样，利用HashSet找出所求结果
//解题思路二：借鉴上面思路二的解法，先异或一遍，得到数字temp，此数字是两个只出现一次的数字的异或的结果，
//            然后找到temp二进制形式中第一位为1的，依据此将数组中数字划分成两部分，然后分别再对两个子数组异或，
//            两个子数组异或的结果即为所求
int findFirst1Bit(int num) {
	int indexBit = 0;
	while ((num & 1 == 0) && (indexBit < 8 * sizeof(int))) {
		num = num >> 1;
		++indexBit;
	}
	
	return indexBit;
}
bool isBit1(int num, int index) {
	num = num >> index;
	return (num & 1);
}
void findSingleNum2(int data[], int len, int* num1, int* num2) {
	if (data == NULL || len <= 0)
		return;

	int resultDivide = 0;
	for (int i = 0; i < len; i++)
		resultDivide = resultDivide ^ data[i];

	int bit1 = findFirst1Bit(resultDivide);
	*num1 = 0;
	*num2 = 0;
	for (int i = 0; i < len; i++) {
		if (isBit1(data[i],bit1))
			*num1 ^= data[i];
		else *num2 ^= data[i];
	}
}


int main()
{
	int num[] = { 1,2,3,4,5,6,5,4,3,2,1 };
	cout << findSingleNum(num, sizeof(num) / sizeof(num[0])) << endl;

	int num2[] = { 1,2,3,4,5,6,7,5,4,3,2,7 };
	int res1, res2;
	findSingleNum2(num2, sizeof(num2) / sizeof(num2[0]), &res1, &res2);
	cout << res1 << "\t" << res2 << endl;

    return 0;
}

