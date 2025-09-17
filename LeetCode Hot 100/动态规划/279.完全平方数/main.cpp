#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string decodeString(string s) {
			stack<pair<string, int>> stk; // 用于模拟计算机的递归
			string res;
			int k = 0;
			for (char c : s) {
				if (isalpha(c)) {
					res += c;
				} else if (isdigit(c)) {
					k = k * 10 + (c - '0');
				} else if (c == '[') {
					// 模拟递归
					// 在递归之前，把当前递归函数中的局部变量 res 和 k 保存到栈中
					stk.push({move(res), k});
					// 递归，初始化 res 和 k（由于 move 了，res 此时为空）
					// result = ""; 没有move就要初始化
					k = 0;
				} else { // ']'
					// 递归结束，从栈中恢复递归之前保存的局部变量
					string pre_res = stk.top().first;
					int pre_k = stk.top().second;
					st.pop();
					// 此时 res 是下层递归的返回值，将其重复 pre_k 次，拼接到递归前的 pre_res 之后
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