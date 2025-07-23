#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int rob(vector<int> &nums) {
			if (nums.size() == 0)
				return 0;
			if (nums.size() == 1)
				return nums[0];
			vector<int> dp(nums.size() + 1, 0);
			// 初始化
			dp[0] = nums[0];
			dp[1] = max(dp[0], nums[1]);
			for (int i = 2; i < nums.size(); i++) {
				dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
			}
			return dp[nums.size() - 1];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 2, 3, 1};
	cout << solution.rob(nums);
	return 0;
}
/*
示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4

示例 2:

输入: amount = 3, coins = [2]
输出: 0
*/