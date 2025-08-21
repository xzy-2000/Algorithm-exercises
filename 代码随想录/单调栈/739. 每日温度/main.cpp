#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> dailyTemperatures(vector<int> &temperatures) {
//			stack<int> st;
//			int size = temperatures.size();
//			vector<int> result(size, 0);
//			st.push(0);
//			for (int i = 1; i < size; i++) {
//				if (temperatures[i] <= temperatures[st.top()]) {
//					st.push(i);
//				} else {
//					// 需要判断栈内是否为空
//					while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
//						result[st.top()] = i - st.top();
//						st.pop();
//					}
//					st.push(i); // 最后还要将元素压入栈内
//				}
//			}
//			return result;
			stack<int> st; // 递增栈
			vector<int> result(temperatures.size(), 0);
			for (int i = 0; i < temperatures.size(); i++) {
				while (!st.empty() && temperatures[i] > temperatures[st.top()]) { // 注意栈不能为空
					result[st.top()] = i - st.top();
					st.pop();
				}
				st.push(i);

			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> Temp = solution.dailyTemperatures(temperatures);
	for (int i = 0; i < Temp.size(); i++) {
		cout << Temp[i] << " ";
	}
	return 0;
}
/*
[73, 74, 75, 71, 69, 72, 76, 73]
[1, 1, 4, 2, 1, 1, 0, 0]。
*/