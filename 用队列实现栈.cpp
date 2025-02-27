﻿//使用队列实现栈的下列操作：
//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//注意 :
//你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
//链接：https ://leetcode-cn.com/problems/implement-stack-using-queues
class MyStack {
private:
	queue<int> q1;
	queue<int> q2;
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		if (!q1.empty())
			q1.push(x);
		else
			q2.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (q1.empty())
		{
			while (q2.size() > 1)
			{
				int front = q2.front();
				q2.pop();
				q1.push(front);
			}
			int front = q2.front();
			q2.pop();
			return front;
		}
		else
		{
			while (q1.size() > 1)
			{
				int front = q1.front();
				q1.pop();
				q2.push(front);
			}
			int front = q1.front();
			q1.pop();
			return front;
		}

	}

	/** Get the top element. */
	int top() {
		if (!q1.empty())
			return q1.back();
		else
			return q2.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q2.empty() && q1.empty();
	}
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/