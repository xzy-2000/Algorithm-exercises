#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int findLengthOfLCIS(vector<int> &nums) {
			if (nums.size() <= 1)
				return nums.size();
			// 定义和初始化 以下标i为结尾的连续递增的子序列长度为dp[i]。
			vector<int> dp(nums.size(), 1);
			// 定义最大子序列长度为result
			int result = 0;
			for (int i = 1; i < nums.size(); i++) {
				if (nums[i] > nums[i - 1])
					dp[i] = max(dp[i], dp[i - 1] + 1);
				if (dp[i] > result)
					result = dp[i];
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 3, 5, 4, 7};
	std::cout << solution.findLengthOfLCIS(nums);
	return 0;
}