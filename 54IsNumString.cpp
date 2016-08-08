// 54IsNumString.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//����������ʵ��һ�������ж��ַ����Ƿ��ʾ��ֵ������������С����
//�����ַ�����+100������5e2������-123������3.1416������-E-16������ʾ��ֵ
//����12e������1a3.14������1.2.3������+-5������12e+5.4����������ֵ

//����˼·�������������ַ�������������������[sign]integral-digits[.[fractional-digits]][e|E[sign]exonential-digits]
void isBetween0To9(char **str) {
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);
}
bool isExponential(char **str) {
	if (**str != 'e' || **str != 'E')
		return false;

	++(*str);
	if (**str == '+' || **str == '-')
		++(*str);

	if (**str == '\0')
		return false;

	isBetween0To9(str);
	return (**str == '\0') ? true : false;
}
bool isNumberic(char *str) {
	if (str == NULL)
		return false;

	if (*str == '+' || *str == '-')
		++str;
	if (*str == '\0')
		return false;

	bool numeric = true;

	isBetween0To9(&str);
	if (*str != '\0') {
		if (*str == '.') {
			++str;
			isBetween0To9(&str);
			if (*str == 'e' || *str == 'E')
				numeric = isExponential(&str);
		}
		else if(*str == 'e' || *str == 'E')
			numeric = isExponential(&str);
		else numeric = false;
	}

	return numeric && *str == '\0';
}

int main()
{
	char* str = new char[100];
	while (cin >> str) {
		cout << isNumberic(str) << endl;
	}

    return 0;
}

