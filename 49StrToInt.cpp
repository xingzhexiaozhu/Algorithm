// 49StrToInt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

//题意描述：将输入的字符串转化为整形输出，题目要求考虑所有输入情况，但没有明确说明哪些情况，总结有以下情况：
//1. 符串前面的空格符；
//2. 然后可能有正负号（注意只取一个，如果有多个正负号，那么说这个字符串是无法转换的，返回0。比如测试用例里就有个“+-2”）；
//3. 字符串可以包含0~9以外的字符，如果遇到非数字字符，那么只取该字符之前的部分，如“-00123a66”返回为“-123”；
//4. 如果超出int的范围，返回边界值（2147483647或-2147483648）

int strToInt(string str) {
	int len = str.length();//字符串长度
	int i = 0;
	bool overFlow = false;//是否溢出位
	int sign = 1;//符号位
	int result = 0;//最终结果

	while (i < len && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))//字符串为空
		++i;
	if (i == len)
		return 0;

	if (str[i] == '-') {
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
		i++;

	while (i < len) {
		if (!isdigit(str[i]))
			break;
		if (sign == 1 && result>(INT_MAX - (str[i] - '0')) / 10 ||
			(sign == -1 && -result < (INT_MIN + (str[i] - '0')) / 10)) {
			overFlow = true;
			break;
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (overFlow)
		result = (sign == 1) ? INT_MAX : INT_MIN;
	else result = sign*result;

	return result;
}

int main()
{
	string str = "123";
	while (cin >> str) {
		cout << strToInt(str) << endl;
	}

	return 0;
}

