#include <bits/stdc++.h>
using namespace std;

class MyQueue {
	public:
		stack<int> stIn;
		stack<int> stOut;
		/*
		push(x) -- ��һ��Ԫ�ط�����е�β����
		pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
		peek() -- ���ض����ײ���Ԫ�ء�
		empty() -- ���ض����Ƿ�Ϊ�ա�
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
			int res = this->pop(); // ֱ��ʹ�����е�pop����
			stOut.push(res); // ��Ϊpop����������Ԫ��res����������ӻ�ȥ
			return res;
		}

		bool empty() {
			return stIn.empty() && stOut.empty();
		}
};

int main(int argc, char **argv) {
	MyQueue myQueue; // ��ȷ��������ʵ��
	myQueue.push(3); // queue is: [1]
	myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
	cout << myQueue.peek() << endl; // return 1
	cout << myQueue.pop() << endl; // return 1, queue is [2]
	cout << myQueue.empty() << endl; // return false
	return 0;
}