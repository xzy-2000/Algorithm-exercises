#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool isSubsequence(string s, string t) {
			int len1 = s.size();
			int len2 = t.size();
			if (len1 == 0)
				return true;
			else if (len2 == 0)
				return false;
			// 定义和初始化
			// dp[i][j]指的是nums1和nums2分别到下标i和j时，公共最长子数组长度
			vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
			int result = 0;
			// 要对第一行，第一列经行初始化
			int result1 = 0;
			for (int i = 0; i < len1; i++) {
				if (s[i] == t[0]) {
					result1 = 1;
				}
				dp[i][0] = result1;

			}
			int result2 = 0;
			for (int j = 0; j < len2; j++) {
				if (t[j] == s[0])
					result2 = 1;
				dp[0][j] = result2;
			}
			// 遍历
			for (int i = 0; i < len1; i++) {
				for (int j = 0; j < len2; j++) {
					// 递推公式
					if (i > 0 && j > 0) {
						if (s[i] == t[j]) {
							dp[i][j] = dp[i - 1][j - 1] + 1;
						} else
							dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
					}

					if (dp[i][j] > result)
						result = dp[i][j];
					// cout << dp[i][j] << " ";
				}
				// cout << endl;
			}
			if (result == len1)
				return true;
			return false;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string s = "ahbgd";
	string t = "ahbgdc";
	std::cout << solution.isSubsequence(s, t);
	return 0;
}