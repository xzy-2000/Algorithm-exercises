#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int findLength(vector<int> &nums1, vector<int> &nums2) {
			int len1 = nums1.size();
			int len2 = nums2.size();
			if (len1 == 0 || len2 == 0)
				return 0;
			// 定义和初始化
			// dp[i][j]指的是nums1和nums2分别到下标i和j时，公共最长子数组长度
			vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
			int result = 0;
			// 要对第一行，第一列经行初始化
			for (int i = 0; i < len1; i++) {
				if (nums1[i] == nums2[0])
					dp[i][0] = 1;
			}

			for (int j = 0; j < len2; j++) {
				if (nums2[j] == nums1[0])
					dp[0][j] = 1;
			}
			// 遍历
			for (int i = 0; i < len1; i++) {
				for (int j = 0; j < len2; j++) {
					// 递推公式
					if (nums1[i] == nums2[j] && i > 0 && j > 0) {
						dp[i][j] = dp[i - 1][j - 1] + 1;
					}
					if (dp[i][j] > result)
						result = dp[i][j];
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums1 = {1, 1, 0, 0, 1, 1};
	vector<int> nums2 = {0, 0};
	std::cout << solution.findLength(nums1, nums2);
	return 0;
}