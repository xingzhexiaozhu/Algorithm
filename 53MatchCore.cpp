// 53MatchCore.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//题意描述：实现一个实现匹配包含'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示出现任意次（包含0次）.
//在本题中，匹配是指字符串的所有字符匹配整个模式。
//如字符串“aaa”与模式“a.a”和“ab*ac*a”匹配，但与“aa.a”及"ab*a"不匹配。

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

