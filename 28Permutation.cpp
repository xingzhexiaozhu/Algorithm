// 28Permutation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��������������һ�ַ�������ӡ�����ַ������ַ����������С����������ַ���abc��
//���ӡ�����ַ�a��b��c�������г����������ַ���abc,acb,bac,bca,cab��cba

//����˼·һ�����������̷ֳ������������ǣ�
//��1�����ַ���������������ɣ���һ���ַ� + ���������ַ���
//��2��������п��ܳ����ڵ�һ��λ�õ��ַ���
//��3���̶���һ���ַ�����������ַ����п��ܵ����У�
//Ϊ�����������123��ʾ���¡�123��ȫ������123��132��213��231��312��321������
//���ȿ���213��321�����������εó��ģ���Ȼ�������123�е�1�ֱ���������������õ���
//Ȼ����Խ�123�ĵڶ�������ÿ�����������õ�132��ͬ����Ը���213��321����231��312
//��˿���֪��---ȫ���о��Ǵӵ�һ��������ÿ�����ֱ�������������ֽ���
//�ҵ�������ɺ󣬵ݹ�Ĵ���ͺ�����д�����ˣ�
void Permutation(char* str, char* pStr);
void Permutation(char* str) {
	if (str == NULL)
		return;
	Permutation(str, str);
}
void Permutation(char* pStr, char* pBegin) {
	if (*pBegin == '\0')
		cout << pStr << endl;
	else {
		for (char* pCh = pBegin; *pCh != '\0'; pCh++) {
			swap(*pBegin, *pCh);
			Permutation(pStr, pBegin + 1);
			swap(*pBegin, *pCh);
		}
	}
}

//����˼·����k��ʾ��ǰѡȡһ�ڼ�������m��ʾ���ж��ٸ���
//void Permutation2(char* pStr, int k, int m) {
//	//assert(pStr);
//
//	if (k == m) {
//		static int num = 1;//�ֲ���̬����������ͳ��ȫ���еĸ���
//		cout << "��" << num++ << "������" << pStr << endl;
//	}
//	else {
//		for (int i = k; i <= m; i++) {
//			swap(*(pStr + k), *(pStr + i));
//			Permutation2(pStr, k + 1, m);
//			swap(*(pStr), *(pStr + i));
//		}
//	}
//}


int main()
{
	char str[] = "abc";
	Permutation(str);
	cout << endl;
	
	//Permutation2(str, 0, strlen(str) - 1);
	return 0;
}