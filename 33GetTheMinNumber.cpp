// 33GetTheMinNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
//题意描述：输入一个正整数数组，把数组里面所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
//如:输入数组｛3，32，321｝，则打印出这三个数字能排成最小的数字为321323

//解题思路一：自定义排序顺序，然后对vector进行排序、组合再输出
//先将数字转换成字符串，再直接对字符串进行排序即可
bool cmp(const int &num1, const int &num2) {
	string _str1 = to_string(num1);
	string _str2 = to_string(num2);
	//_str1.append(_str2);
	//_str2.append(_str1);
	string str1 = _str1 + _str2;
	string str2 = _str2 + _str1;

	return str1 < str2;
}
string PrintMinNumber(vector<int> numbers) {
	sort(numbers.begin(), numbers.end(), cmp);
	string res;
	for (int i = 0; i < numbers.size(); i++)
		res += to_string(numbers[i]);
	return res;
}

int main()
{
	vector<int> v = { 3,32,321 };
	cout << PrintMinNumber(v) << endl;

    return 0;
}


//解法一：
//int compare1(string str1, string str2)//自定义的比较大小的函数，str1 "小"的话，返回true
//{
//	string tmp1 = str1.append(str2);
//	string tmp2 = str2.append(str1);
//	if (tmp1.compare(tmp2)<0)
//		return true;
//	return false;
//}
//
//int main()
//{
//	int num[] = { 3,32,321 };
//	int len = sizeof(num) / sizeof(int);
//	cout << "len = " << len << endl;
//	string *word = new string[len];
//	stringstream sst;
//	for (int i = 0; i<len; i++)//讲int整数转化成字符串
//	{
//		sst << num[i];
//		sst >> word[i];
//		sst.clear();
//	}
//	cout << endl;
//	sort(word, word + len, compare1);//利用泛型算法排序
//	for (int i = 0; i<len; i++)
//	{
//		cout << word[i];
//	}
//	getchar();
//	return 0;
//}


//解法二：虚函数
//struct num_compare
//{
//	bool operator()(const int &lhs, const int &rhs) {
//		return to_string(lhs) + to_string(rhs) < to_string(rhs) + to_string(lhs);
//	}
//};
//string PrintMinNumber(vector<int> numbers) {
//	sort(numbers.begin(), numbers.end(), num_compare());
//	string res;
//	for (int i = 0; i < numbers.size(); i++)
//		res += to_string(numbers[i]);
//	return res;
//}
//
//int main() {
//	vector<int> v = { 3,32,321 };
//	cout << PrintMinNumber(v) << endl;
//}


//
//bool cmp(const string &str1, const string &str2) {
//	string _str1 = str1;
//	string _str2 = str2;
//	_str1.append(str2);
//	_str2.append(str1);
//
//	return _str1 < _str2;
//}
//int num[200];
//string str_num[200];
//int main() {
//	int n;
//	while (cin >> n) {
//		for (int i = 0; i < n; i++) {
//			cin >> num[i];
//			stringstream stream;
//			stream << num[i];
//			str_num[i] = stream.str();
//		}
//
//		sort(str_num, str_num + n, cmp);
//
//		for (int i = 0; i < n; i++) {
//			cout << str_num[i];
//		}
//		cout << endl;
//	}
//
//	return 0;
//}