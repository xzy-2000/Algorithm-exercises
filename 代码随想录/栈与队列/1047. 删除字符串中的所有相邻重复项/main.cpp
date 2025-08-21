#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string removeDuplicates(string s) {
//			stack<char> st;
//			for (int i = 0; i < s.size(); i++) {
//				if (st.empty() || s[i] != st.top()) {
//					st.push(s[i]);
//				} else {
//					st.pop();
//				}
//			}
//			string result = "";
//			while (!st.empty()) { // ��ջ��Ԫ�طŵ�result�ַ�������
//				result += st.top();
//				st.pop();
//			}
//			reverse (result.begin(), result.end()); // ��ʱ�ַ�����Ҫ��תһ��
//			return result;
			string result;
			for (char std : s) {
				if (result.empty() || result.back() != std) {
					result.push_back(std);
				} else {
					result.pop_back();
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;
	string s = "abbaca";
	cout << solution.removeDuplicates(s);
	return 0;
}