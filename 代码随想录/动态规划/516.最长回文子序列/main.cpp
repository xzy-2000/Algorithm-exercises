#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int longestPalindromeSubseq(string s) {
			// 定义dp数组含义和初始化
			// dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串长度
			vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
			// 初始化
			for (int j = 0; j < s.size(); j++) {
				dp[j][j] = 1;
			}
			// 遍历
			for (int i = s.size() - 1; i >= 0; i--) {
				for (int j = i + 1; j < s.size(); j++) {
					if (s[i] == s[j]) {
						dp[i][j] = dp[i + 1][j - 1] + 2;
					} else {
						dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
					}
//					cout << "s[" << i << "] = " << s[i] << " s[" << j << "] = " << s[j];
//					cout << " dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
				}
			}
			return dp[0][s.size() - 1];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "bbbab"; // bbbb 4
	std::cout << solution.longestPalindromeSubseq(s);
	return 0;
}
/*
示例 1：

输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。
示例 2：

输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。
*/