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
			// ������ͷ����Ԫ�أ��������һ��Ԫ���⣩ ������ӵ�����β��
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
			// ������ͷ����Ԫ�أ��������һ��Ԫ���⣩ ������ӵ�����β��
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
	cout << myStack.pop() << endl; // ���� 1
	cout << myStack.top() << endl; // ���� 2
	cout << myStack.pop() << endl; // ���� 2
	cout << myStack.empty() << endl; // ���� False
	return 0;
}