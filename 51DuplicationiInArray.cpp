// 51DuplicationiInArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//������������һ������Ϊn���������������ֶ���0-(n-1)֮�䣬������ĳЩ�������ظ��ģ�����֪�����������ظ��ˣ�Ҳ��֪���ظ��˼��Ρ�
//���ҳ�����������һ���ظ������֡�����������볤Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3

//����˼·һ������Ȼ��������ҵ���һ���ظ������֡������ʱ�临�Ӷ�����ΪO(nlogn)�����в���ʱ�临�Ӷȡ�

//����˼·������ϣ��ʱ�临�Ӷ�ΪO(n)������Ҫ����Ŀռ䡿

//����˼·������ͷ�������飬a[i]��i�ȣ�����������һλ������������index=a[i]Ȼ��a[i]��a[index]��������һ�˽����Ϳ����ҵ��ظ�Ԫ��
bool duplicate(int num[], int length, int *duplicateNum) {
	if(num == NULL || length < 1)
		return false;

	for (int i = 0; i < length; i++) {
		while (num[i] != i) {
			if (num[i] == num[num[i]]) {
				*duplicateNum = num[i];
				return true;
			}
			int temp = num[i];
			num[i] = num[temp];
			num[temp] = temp;
		}
	}

	return false;
}

int main()
{
	int num[] = { 2,3,1,0,2,5,3 };
	int res;
	if (duplicate(num, sizeof(num) / sizeof(num[0]), &res))
		cout << res << endl;
	else cout << "No duplicate num!" << endl;

    return 0;
}

