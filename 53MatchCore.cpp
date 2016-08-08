// 53MatchCore.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//����������ʵ��һ��ʵ��ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��������Σ�����0�Σ�.
//�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
//���ַ�����aaa����ģʽ��a.a���͡�ab*ac*a��ƥ�䣬���롰aa.a����"ab*a"��ƥ�䡣

bool matchCore(char* str, char*pattern) {
	if (*str == '\0' && *pattern == '\0')
		return true;

	if (*str != '\0' && pattern == '\0')
		return false;

	if (*(pattern + 1) == '*') {
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			return matchCore(str + 1, pattern + 2);
		else return matchCore(str, pattern + 2);
	}

	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);

	return false;
}

bool match(char* str, char* pattern) {
	if (str == NULL || pattern == NULL)
		return false;

	return matchCore(str, pattern);
}

int main()
{
	
	char* str1 = "aaa";
	char* str2[] = { "a.a", "ab*ac*a","aa.a","ab*a"};

	for (int i = 0; i < 4; i++) {
		if (match(str1, str2[i]))
			cout << "Match!" << endl;
		else cout << "Failure!" << endl;
	}

    return 0;
}

