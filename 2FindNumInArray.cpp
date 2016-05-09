// FindNumInArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
using namespace std;

//������������һ����ά�����У�ÿһ�ж��������ҵĵ���˳������ÿһ��Ҳ���մ��ϵ��µĵ���˳������
//��ɺ���������һ��������һ����ά�����һ���������ж��Ƿ��и�����
//���磺
//1	 2	8	9
//2	 4	9	12
//4  7	10	13
//6  8	11	15
//�������7����true���������5����false

//����˼·�����δ����ϱ����������ǰֵ���ڸ���ֵ������true
//          �����ǰֵ���ڸ���ֵ�����ų���ǰֵ�������У�Ȼ������һ���ٱ����������û����ʱ����false
//          �����ǰֵС�ڸ���ֵ�����ų���ǰֵ�������У�Ȼ������һ���ٱ�����������û����ʱ����false
//֮��������������Ϊ������С���ҷ�Χ�������¡����Ͽ�ʼ���ɣ�

bool find(int* matrix, int rows, int columns, int num) {
	bool found = false;

	if (matrix != NULL && rows > 0 && columns > 0) {
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0) {
			if (matrix[row*columns + column] == num) {
				found = true;
				break;
			}
			else if (matrix[row*columns + column] > num)
				column--;
			else row++;
		}
	}

	return found;
}

int main()
{
	int array[] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
	
	bool found = find(array, 4, 4, 7);
	if (found) cout << "true" << endl;
	else cout << "false" << endl;

	found = find(array, 4, 4, 5);
	if(found) cout << "true" << endl;
	else cout << "false" << endl;

    return 0;
}

