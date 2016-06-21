// 20PrintMatrixClockwisely.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include<iostream>
//using namespace std;

//题意描述：输入一个矩阵，按照从外向里顺时针的顺序依次打印出每一个数字。如下
//1   2   3   4  
//5   6   7   8
//9   10  11  12
//13  14  15  16
//输出：1、2、3、4、8、12、16、15、14、13、9、5、6、7、11、10

//解题思路：第一步从左到右打印行（1--4）；第二步从上到下打印列（8--16）；
//第三步从右到左打印行（15--13）；第四步从下到上打印列（9-5）；
//后面依次类推
//void PrintMatrixInCircle(int(*numbers)[4], int columns, int rows, int start) {
//	int endX = columns - 1 - start;
//	int endY = rows - 1 - start;
//
//	//从左到右打印一行
//	for (int i = start; i <= endX; ++i) {
//		int number = numbers[start][i];
//		cout << number << "\t";
//	}
//	//从上到下打印一列
//	if (start < endY) {
//		for (int i = start + 1; i <= endY; ++i) {
//			int number = numbers[i][endX];
//			cout << number << "\t";
//		}
//	}
//	//从右到左打印一行
//	if (start < endX && start < endY) {
//		for (int i = endX - 1; i >= start; --i) {
//			int number = numbers[endY][i];
//			cout << number << "\t";
//		}
//	}
//	//从下到上打印一列
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

//对于给定矩阵确定矩阵的对角线上两点，然后打印这一周的元素
void PrintMatrixCircle(int **num, int sX, int sY, int eX, int eY) {
	//只有一行直接打印，返回
	if (sX == eX) {
		for (int j = sY; j <= eY; ++j)
			cout << *(*(num + sX) + j) << "\t";

		return;
	}
	//只有一列直接打印，返回
	if (sY == eY) {
		for (int i = sX; i <= eX; ++i)
			cout << *(*(num + i) + sY) << "\t";

		return;
	}

	//分别打印上、右、下、左四条边
	for (int p = sY; p < eY; ++p)//打印行
		cout << *(*(num + sX) + p) << "\t";

	for (int q = sX; q < eX; ++q)//打印列
		cout << *(*(num + q) + eY) << "\t";

	for (int m = eY; m > sY; --m)//打印行
		cout << *(*(num + eX) + m) << "\t";

	for (int n = eX; n > sX; --n) //打印列
		cout << *(*(num + n) + sY) << "\t";
}

//给定矩阵，给定行列，由外向内顺时针打印数字
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

	//初始化
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

