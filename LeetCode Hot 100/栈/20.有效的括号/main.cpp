#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool isValid(string s) {
			if (s.length() % 2) { // s 长度必须是偶数
				return false;
			}
			stack<char> st;
			for (char c : s) {
				if (c == '(') {
					st.push(')'); // 入栈对应的右括号
				} else if (c == '[') {
					st.push(']');
				} else if (c == '{') {
					st.push('}');
				} else { // c 是右括号
					if (st.empty() || st.top() != c)
						return false; // 没有左括号，或者左括号类型不对
					st.pop();
				}
			}
			if (st.empty())
				return true;
			else
				return false;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s =  "()[]{}";
	cout << solution.isValid(s);
	return 0;
}