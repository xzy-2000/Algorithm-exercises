#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int countSubstrings(string s) {
			// 定义dp数组含义和初始化
			// 布尔类型的dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，
			// 如果是dp[i][j]为true，否则为false。
			vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
			int cnt = 0;
			// 初始化
			// dp[i][i] 表示：以s[i]是否为回文串，肯定是，因为只有一个字符
//			for (int i = 0; i < s.size(); i++) {
//				dp[i][i] = 1;
//			}
			// 遍历
			for (int i = s.size() - 1; i >= 0; i--) {
				for (int j = i; j < s.size(); j++) {
					if (s[i] == s[j]) {
						if (i + 1 == j || i == j) { // 此时是s[i]和s[j]隔着1 位或者相同1 位
							dp[i][j] = true;
							cnt++;
						} else if (dp[i + 1][j - 1] == true) { // j 大于i，且[i + 1,j - 1]已经是回文串了
							dp[i][j] = true;
							cnt++;
						}
						// cout << "s[i] = " << s[i] << " s[j] = " << s[j] << " i = " << i << " j = " << j << " dp[i][j] = " << dp[i][j] << endl;
					}
				}
			}
			return cnt;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "aaa"; // a a b a aa aa aba aba
	std::cout << solution.countSubstrings(s);
	return 0;
}
/*
s[i] = a s[j] = a i = 2 j = 2
s[i] = a s[j] = a i = 1 j = 1
s[i] = a s[j] = a i = 1 j = 2
s[i] = a s[j] = a i = 0 j = 0
s[i] = a s[j] = a i = 0 j = 1
*/