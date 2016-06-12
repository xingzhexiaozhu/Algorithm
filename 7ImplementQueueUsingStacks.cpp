// ImplementQueueUsingStacks.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
using namespace std;

//����������������ջ��ģ��һ�����еĲ���
//����˼·��������stackʵ��һ��queue
//�㷨���£�
//ջs1��s2��s1������ӣ�s2����
//��1���ж��������s1����s2��Ϊ�գ������
//��2���жӿգ����s1��s2��Ϊ�գ���ӿ�
//��3����ӣ�1)ջs1����������ֱ��ѹ��ջs1
//        2)��s1������s1�е�����Ԫ�ص�����ջs2�У�Ȼ���ٽ�Ԫ����ջs1
//��4�����ӣ�1)��s2�վͽ�s1�е�����Ԫ�ص�����ջs2�У�Ȼ���ջ
//        2)s2���վ�ֱ�Ӵ�s2�е���Ԫ��

template<typename T> class CQueue {
public :
	CQueue(void);
	~CQueue(void);

	void appenTail(const T& node);
	T deletedHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& element) {
	stack1.push(element);
}

template<typename T> T CQueue<T>::deletedHead() {
	if (stack2.size() <= 0) {
		while (stack1.size() > 0) {
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		throw new exception("queue is empty!");
	
	T head = stack2.top();
	stack2.pop();

	return head;
}

int main()
{
    return 0;
}

