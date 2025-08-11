#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int numDistinct(string s, string t) {
			// 定义dp数组含义和初始化
			// dp[i][j]指的是s从0到i-1和t从0到j-1时有几个匹配项
			vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
			// 初始化
			// dp[i][0] 表示：以i-1为结尾的s可以随便删除元素，出现空字符串的个数。
			for (int i = 0; i < s.size(); i++) {
				dp[i][0] = 1;
			}
			// dp[0][j]：空字符串s可以随便删除元素，出现以j-1为结尾的字符串t的个数。
			for (int j = 1; j < t.size(); j++) {
				dp[0][j] = 0;
			}
			// 遍历
			for (int i = 1; i <= s.size(); i++) {
				for (int j = 1; j <= t.size(); j++) {
					if (s[i - 1] == t[j - 1])
						dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
					else
						dp[i][j] = dp[i - 1][j];
//					cout << dp[i][j] << " ";
				}
//				cout << endl;
			}
			return dp[s.size()][t.size()];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "baegg";
	string t = "bag";
	std::cout << solution.numDistinct(s, t);
	return 0;
}