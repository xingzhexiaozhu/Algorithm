// 54IsNumString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：实现一个函数判断字符串是否表示数值（包括整数、小数）
//例如字符串“+100”、“5e2”、“-123”、“3.1416”及“-E-16”均表示数值
//但“12e”、“1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是数值

//解题思路：符合条件和字符串特征满足以下条件[sign]integral-digits[.[fractional-digits]][e|E[sign]exonential-digits]
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

