#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int rob(vector<int> &nums) {
			if (nums.size() == 0)
				return 0;
			if (nums.size() == 1)
				return nums[0];
			int dp1 = robRange(nums, 0, nums.size() - 2);
			int dp2 = robRange(nums, 1, nums.size() - 1);
			return max(dp1, dp2);
		}

		int robRange(vector<int> &nums, int begin, int end) {
			if (end == begin)
				return nums[begin];
			vector<int> dp(nums.size() + 1);
			// 初始化
			dp[begin] = nums[begin];
			dp[begin + 1] = max(dp[begin], nums[begin + 1]);
//			cout << begin << " " << end << endl;
//			cout << dp[begin] << " " << dp[begin + 1] << endl;
			for (int i = begin + 2; i <= end; i++) {
				dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//				cout << dp[i] << " ";
			}
//			cout << endl;
//			cout << dp[end] << endl;
			return dp[end];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {200, 3, 140, 20, 10}; // 200, 3, 140, 20, 10 -> 200 140 = 340
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