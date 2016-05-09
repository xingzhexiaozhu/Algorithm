// 3ReplaceSpace.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;

//题意描述：实现一个函数把字符串中的每个空格替换成“20%”
//例如:
//输入“we are happy”
//输出“we%20are%20happy”

//解题思路：如果从前往后遍历，遇到空格再将字符向后移动，则假设有O(n)个空格的时间效率就是O(n^2)。
//因此优化的解法就是一次移到位，先遍历一次字符串，可同时得到字符串的长度和字符串中空格的数量，然后对于1个空格用“%20”3个字符替换，
//所以可以计算出最终字符串应该有的长度，两个指针，一个指向最终字符串的末尾，一个指向原始字符串的末尾，依次复制，遇空格便替换，当两
//指针重合（即指向同一位置），则说明空格替换完毕。如此做法时间效率就是O(n)

void replaceBlank(char string[], int length) {//length为字符数组的总容量
	if (string == NULL || length <= 0)
		return;

	int originalLength = 0;//字符串的原长度
	int numberOfBlank = 0; //空格个数
	int i = 0;
	while (string[i] != '\0') {
		originalLength++;
		if (string[i] == ' ')
			numberOfBlank++;
		i++;
	}

	int newLength = originalLength + numberOfBlank * 2;//新字符串的长度
	if (newLength > length)
		return;

	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew >= indexOfOriginal) {
		if (string[indexOfOriginal] == ' ') {
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else {
			string[indexOfNew--] = string[indexOfOriginal];
		}
		indexOfOriginal--;
	}

	for (int i = 0; string[i] != '\0'; i++)
		cout << string[i];
	cout << endl;
}


int main()
{
	char ch[100] = { 'h','e','l','l','o',' ','w','o','r','l','d' };
	for (int i = 0; ch[i] != '\0'; i++)
		cout << ch[i];
	cout << endl;
	replaceBlank(ch, 100);
    return 0;
}

