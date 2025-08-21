#include <bits/stdc++.h>
using namespace std;

class MyStack {
	public:
		queue<int> que;
		MyStack() {

		}

		void push(int x) {
			que.push(x);
		}

		int pop() {
			int size = que.size();
			size--;
			// 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
			while (size--) {
				que.push(que.front());
				que.pop();
			}
			int result = que.front();
			que.pop();
			return result;
		}

		int top() {
			int size = que.size();
			size--;
			// 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
			while (size--) {
				que.push(que.front());
				que.pop();
			}
			int result = que.front();
			que.push(result);
			que.pop();
			return result;
		}

		bool empty() {
			return que.empty();
		}
};


int main(int argc, char **argv) {
	MyStack myStack;
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	cout << myStack.pop() << endl; // 返回 1
	cout << myStack.top() << endl; // 返回 2
	cout << myStack.pop() << endl; // 返回 2
	cout << myStack.empty() << endl; // 返回 False
	return 0;
}