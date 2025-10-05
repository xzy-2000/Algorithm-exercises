#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxSubArray(vector<int> &nums) {
			int n = nums.size();
			int result = INT_MIN;
			vector<int> dp(n);
			// ≥ı ºªØ
			dp[0] = nums[0];
			result = dp[0];
			// ±È¿˙
			for (int i = 1; i < n; i++) {
				dp[i] = max(dp[i - 1] + nums[i], nums[i]);
				result = max(result, dp[i]);
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << solution.maxSubArray(nums);
	return 0;
}