// ImplementQueueUsingStacks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;

//题意描述：用两个栈来模拟一个队列的操作
//解题思路：用两个stack实现一个queue
//算法如下：
//栈s1和s2，s1用作入队，s2出队
//（1）判队满：如果s1满且s2不为空，则队满
//（2）判队空：如果s1和s2都为空，则队空
//（3）入队：1)栈s1若不满，则直接压入栈s1
//        2)若s1满，则将s1中的所有元素弹出到栈s2中，然后再将元素入栈s1
//（4）出队：1)若s2空就将s1中的所有元素弹出到栈s2中，然后出栈
//        2)s2不空就直接从s2中弹出元素

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

