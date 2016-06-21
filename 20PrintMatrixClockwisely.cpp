// 20PrintMatrixClockwisely.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//#include<iostream>
//using namespace std;

//��������������һ�����󣬰��մ�������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�����
//1   2   3   4  
//5   6   7   8
//9   10  11  12
//13  14  15  16
//�����1��2��3��4��8��12��16��15��14��13��9��5��6��7��11��10

//����˼·����һ�������Ҵ�ӡ�У�1--4�����ڶ������ϵ��´�ӡ�У�8--16����
//���������ҵ����ӡ�У�15--13�������Ĳ����µ��ϴ�ӡ�У�9-5����
//������������
//void PrintMatrixInCircle(int(*numbers)[4], int columns, int rows, int start) {
//	int endX = columns - 1 - start;
//	int endY = rows - 1 - start;
//
//	//�����Ҵ�ӡһ��
//	for (int i = start; i <= endX; ++i) {
//		int number = numbers[start][i];
//		cout << number << "\t";
//	}
//	//���ϵ��´�ӡһ��
//	if (start < endY) {
//		for (int i = start + 1; i <= endY; ++i) {
//			int number = numbers[i][endX];
//			cout << number << "\t";
//		}
//	}
//	//���ҵ����ӡһ��
//	if (start < endX && start < endY) {
//		for (int i = endX - 1; i >= start; --i) {
//			int number = numbers[endY][i];
//			cout << number << "\t";
//		}
//	}
//	//���µ��ϴ�ӡһ��
//	if (start < endX && start < endY - 1) {
//		for (int i = endY - 1; i >= start + 1; --i) {
//			int number = numbers[i][start];
//			cout << number << "\t";
//		}
//	}
//}
//void PrintMatrixClockwisely(int (*numbers)[4], int columns, int rows) {
//	if (numbers == NULL || columns <= 0 || rows <= 0)
//		return;
//
//	int start = 0;
//	while (columns > start * 2 && rows > start * 2) {
//		PrintMatrixInCircle(numbers, columns, rows, start);
//		++start;
//	}
//}
//
//int main()
//{
//	int nums[][4] = { {1,2,3,4}, {5,6,7,8},{9,10,11,12},{13,14,15,16} };
//	PrintMatrixClockwisely(nums, 4, 4);
//
//    return 0;
//}

#include<iostream>
#include<string>
using namespace std;

//���ڸ�������ȷ������ĶԽ��������㣬Ȼ���ӡ��һ�ܵ�Ԫ��
void PrintMatrixCircle(int **num, int sX, int sY, int eX, int eY) {
	//ֻ��һ��ֱ�Ӵ�ӡ������
	if (sX == eX) {
		for (int j = sY; j <= eY; ++j)
			cout << *(*(num + sX) + j) << "\t";

		return;
	}
	//ֻ��һ��ֱ�Ӵ�ӡ������
	if (sY == eY) {
		for (int i = sX; i <= eX; ++i)
			cout << *(*(num + i) + sY) << "\t";

		return;
	}

	//�ֱ��ӡ�ϡ��ҡ��¡���������
	for (int p = sY; p < eY; ++p)//��ӡ��
		cout << *(*(num + sX) + p) << "\t";

	for (int q = sX; q < eX; ++q)//��ӡ��
		cout << *(*(num + q) + eY) << "\t";

	for (int m = eY; m > sY; --m)//��ӡ��
		cout << *(*(num + eX) + m) << "\t";

	for (int n = eX; n > sX; --n) //��ӡ��
		cout << *(*(num + n) + sY) << "\t";
}

//�������󣬸������У���������˳ʱ���ӡ����
void PrintMatrixClockwisely(int **matrix, int rows, int columns){
	if (matrix == NULL || rows < 0 || columns < 0)
		return;

	int startX = 0;
	int startY = 0;
	int endX = rows - 1;
	int endY = columns - 1;
	while (1){
		if (startX > endX && startY > endY)
			break;
		if (startX == endX && startY > endY)
			break;
		if (startX > endX && startY == endY)
			break;

		PrintMatrixCircle(matrix, startX, startY, endX, endY);

		++startX;
		++startY;
		--endX;
		--endY;
	}
}

int main(){
	int example[6][6];
	int *point1[6] = { example[0],example[1],example[2],example[3],example[4],example[5] };
	int **point = point1;
	int n = 1;

	//��ʼ��
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			example[i][j] = n;
			++n;
		}
	}

	cout << "the original matrix is:" << endl;
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			cout << example[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "the clockwisely output of the matrix is:" << endl;
	PrintMatrixClockwisely(point, 6, 6);
	cout << endl;

	return 0;
}

