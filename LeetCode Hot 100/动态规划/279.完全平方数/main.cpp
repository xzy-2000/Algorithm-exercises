#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string decodeString(string s) {
			stack<pair<string, int>> stk; // ����ģ�������ĵݹ�
			string res;
			int k = 0;
			for (char c : s) {
				if (isalpha(c)) {
					res += c;
				} else if (isdigit(c)) {
					k = k * 10 + (c - '0');
				} else if (c == '[') {
					// ģ��ݹ�
					// �ڵݹ�֮ǰ���ѵ�ǰ�ݹ麯���еľֲ����� res �� k ���浽ջ��
					stk.push({move(res), k});
					// �ݹ飬��ʼ�� res �� k������ move �ˣ�res ��ʱΪ�գ�
					// result = ""; û��move��Ҫ��ʼ��
					k = 0;
				} else { // ']'
					// �ݹ��������ջ�лָ��ݹ�֮ǰ����ľֲ�����
					string pre_res = stk.top().first;
					int pre_k = stk.top().second;
					st.pop();
					// ��ʱ res ���²�ݹ�ķ���ֵ�������ظ� pre_k �Σ�ƴ�ӵ��ݹ�ǰ�� pre_res ֮��
					while (pre_k--) {
						pre_res += res;
					}
					res = move(pre_res);
				}
			}
			return res;
		}
};

int main(int argc, char **argv) {
	Solution solution;
	string s = "3[a]2[bc]";
	cout << solution.decodeString(s);
}