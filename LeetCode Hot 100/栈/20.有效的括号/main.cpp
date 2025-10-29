#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool isValid(string s) {
			if (s.length() % 2) { // s ���ȱ�����ż��
				return false;
			}
			stack<char> st;
			for (char c : s) {
				if (c == '(') {
					st.push(')'); // ��ջ��Ӧ��������
				} else if (c == '[') {
					st.push(']');
				} else if (c == '{') {
					st.push('}');
				} else { // c ��������
					if (st.empty() || st.top() != c)
						return false; // û�������ţ��������������Ͳ���
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