#include <bits/stdc++.h>
using namespace std;

class MyQueue {
	public:
		stack<int> stIn;
		stack<int> stOut;
		/*
		push(x) -- 将一个元素放入队列的尾部。
		pop() -- 从队列首部移除元素。
		peek() -- 返回队列首部的元素。
		empty() -- 返回队列是否为空。
		*/
		MyQueue() {

		}

		void push(int x) {
			stIn.push(x);
		}

		int pop() {
			if (stOut.empty()) {
				while (!stIn.empty()) {
					int out = stIn.top();
					stOut.push(out);
					stIn.pop();
				}
			}
			int queue_out = stOut.top();
			stOut.pop();
			return queue_out;
		}

		int peek() {
			int res = this->pop(); // 直接使用已有的pop函数
			stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
			return res;
		}

		bool empty() {
			return stIn.empty() && stOut.empty();
		}
};

int main(int argc, char **argv) {
	MyQueue myQueue; // 正确创建对象实例
	myQueue.push(3); // queue is: [1]
	myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
	cout << myQueue.peek() << endl; // return 1
	cout << myQueue.pop() << endl; // return 1, queue is [2]
	cout << myQueue.empty() << endl; // return false
	return 0;
}