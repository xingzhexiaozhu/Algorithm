// 40OnceNumber.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<set>
using namespace std;

//����������һ�������г���һ�����ֳ�����һ�Σ��������־����������Σ���д����Ѱ�ҳ��������

//����˼·һ����Java�п�����HashSet���ݽṹ����Ԫ�س��ֵڶ��ξ�ɾ����������µ�Ԫ�ؼ�Ϊ����
//����˼·��������������㣬3^5=6��6^5=3�����Ե����һ�α��������ҵ����������ַ���Ч�����
int findSingleNum(int data[], int len) {
	if (data == NULL || len <= 0)
		return -1;

	int res =  0;
	for (int i = 0; i < len; i++)
		res = res ^ data[i];

	return res;
}


//��Ŀ������һ�������г�����������ֻ������һ�Σ��������־����������Σ���д�����ҳ�����������

//����˼·һ������һ��˼·һһ��������HashSet�ҳ�������
//����˼·�����������˼·���Ľⷨ�������һ�飬�õ�����temp��������������ֻ����һ�ε����ֵ����Ľ����
//            Ȼ���ҵ�temp��������ʽ�е�һλΪ1�ģ����ݴ˽����������ֻ��ֳ������֣�Ȼ��ֱ��ٶ��������������
//            �������������Ľ����Ϊ����
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

