// 8RotationArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
using namespace std;

//��������������һ����������������һ����ת���������ת�������СԪ�ء����磺
//���룺{3,4,5,1,2}����{1,2,3,4,5}��һ����ת����������������Сֵ

//����˼·����ת������ص�������������������飬���ö��ֲ��ҵ�˼�룬
//�ֱ�������ָ��ָ������ĵ�һ��Ԫ�غ����һ��Ԫ�أ���һ��Ԫ��Ӧ���Ǵ������һ��Ԫ�صģ�Ȼ���ҵ��м�Ԫ�أ�
//����м�Ԫ��λ��ǰ��ĵ��������飬�������ڵ��ڵ�һ��ָ��ָ���Ԫ�أ���ʱ�ѵ�һ��ָ��ָ����м�Ԫ��
//����м�Ԫ��λ�ں���ĵ��������飬����С�ڵ��ڵڶ���ָ��ָ���Ԫ�أ���ʱ�ѵڶ���ָ��ָ����м�Ԫ��
//������С���ҷ�Χ�����յ�һ��ָ��ָ��ǰ���������������һ��Ԫ�أ��ڶ���ָ��ָ��������������ĵ�һ��Ԫ�أ�

//int Min(int* numbers, int length) {
//	if (numbers == NULL || length <= 0)
//		throw new exception("Invalid parameters!");
//
//	int index1 = 0;
//	int index2 = length - 1;
//	int indexMid = index1;
//	while (numbers[index1] >= numbers[index2]) {
//		if (index2 - index1 == 1) {//�ҵ��������������飬����	
//			indexMid = index2;
//			break;
//		}
//
//		indexMid = (index1 + index2) / 2;
//		if (numbers[indexMid] >= numbers[index1])
//			index1 = indexMid;
//		else if (numbers[indexMid] <= numbers[index2])
//			index2 = indexMid;
//	}
//
//	return numbers[indexMid];
//}

//����Ľ���������⣬����{1,0,1,1,1}��{1,1,1,0,1}������һ�����֡����һ�����ֺ��м����ֶ���1ʱ��
//�����޷�ȷ���м������1���ڵ�һ�����������黹�ǵڶ������������顣������������Ǿ���Ҫ����˳�����
int MinInOrder(int* numbers, int index1, int index2) {
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; i++)
		if (result > numbers[i])
			result = numbers[i];

	return result;
}

int Min(int* numbers, int length) {
	if (numbers == NULL || length <= 0)
		throw new exception("Invalid parameters!");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {//�ҵ��������������飬����	
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;
		//����±�Ϊindex1��index2��indexMinָ�������������ȣ���ֻ��˳�����
		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);

		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
}

int main()
{
	int data[] = { 3,4,5,1,2 };
	cout << Min(data, 5) << endl;

	int nums[] = { 1,1,1,0,1 };
	cout << Min(nums, 5) << endl;

    return 0;
}

