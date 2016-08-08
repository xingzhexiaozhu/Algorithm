// 55CharStatistics.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//������������ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
//���磺���롰go����һ��ֻ����һ�ε��ַ��ǡ�g����
//      ���롰google����һ��ֻ����һ�ε��ַ��ǡ�l��

//����˼·һ������ģ�⣬�����±��ʾ��Ӧ���ַ�
char firstNotRepeatChar(char* pStr) {
	if (pStr == NULL)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (int i = 0; i < tableSize; i++)
		hashTable[i] = 0;

	char *p = pStr;
	while (*p != '\0')
		hashTable[*(p++)]++;

	p = pStr;
	while (*p != '\0') {
		if (hashTable[*p] == 1)
			return *p;
		p++;
	}
	return '\0';
}

//����˼·����˼·ͬ��
class CharStatistics {
private:
	int occurrence[256];
	int index;
public:
	CharStatistics() :index(0) {
		for (int i = 0; i < 256; i++)
			occurrence[i] = -1;
	}
	void Insert(char ch) {
		if (occurrence[ch] == -1)
			occurrence[ch] = index;
		else if (occurrence[ch] >= 0)
			occurrence[ch] = -2;

		index++;
	}
	char FirstAppearingOnce() {
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();
		for (int i = 0; i < 256; i++) {
			if (occurrence[i] >= 0 && occurrence[i] < minIndex) {
				ch = (char)i;
				minIndex = occurrence[i];
			}
			return ch;
		}
	}
	//occurrence[i]: a char with ASCII value i
	//occurrence[i]=-1 the char has not found
	//occurrence[i]=-2 the char has been found multiple times
	//occurrence[i]>=0 the char has been found only once
};

int main()
{
	char ch[] = "abaccdeff";
	cout << firstNotRepeatChar(ch) << endl;

    return 0;
}

