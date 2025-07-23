#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int combinationSum4(vector<int> &nums, int target) {
			int size = nums.size();
			vector<unsigned> dp(target + 1, 0);
			// 初始化
			dp[0] = 1;
			for (int i = 1; i <= target; i++)
				for (int j = 0; j < size; j++)
					if (i >= nums[j]) {
						// 递推公式
						dp[i] = dp[i] + dp[i - nums[j]];
						// cout << "dp[" << i << "]=" << dp[i] << endl;
					}
			return dp[target];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 2, 3};
	int target = 4;
	std::cout << solution.combinationSum4(nums, target);
}