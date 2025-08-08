#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int longestCommonSubsequence(string text1, string text2) {
			int len1 = text1.size();
			int len2 = text2.size();
			if (len1 == 0 || len2 == 0)
				return 0;
			// 定义和初始化
			// dp[i][j]指的是nums1和nums2分别到下标i和j时，公共最长子数组长度
			vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
			int result = 0;
			// 要对第一行，第一列经行初始化
			int result1 = 0;
			for (int i = 0; i < len1; i++) {
				if (text1[i] == text2[0]) {
					result1 = 1;
				}
				dp[i][0] = result1;

			}
			int result2 = 0;
			for (int j = 0; j < len2; j++) {
				if (text2[j] == text1[0])
					result2 = 1;
				dp[0][j] = result2;
			}
			// 遍历
			for (int i = 0; i < len1; i++) {
				for (int j = 0; j < len2; j++) {
					// 递推公式
					if (i > 0 && j > 0) {
						if (text1[i] == text2[j]) {
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
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	string text1 = "abcde";
	string text2 = "ace";
	std::cout << solution.longestCommonSubsequence(text1, text2);
	return 0;
}