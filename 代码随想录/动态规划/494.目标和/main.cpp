#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int findTargetSumWays(vector<int> &nums, int target) {
			int sum = 0;
			for (int i = 0; i < nums.size(); i++)
				sum += nums[i];
			// 无解方案
			if (abs(target) > sum)
				return 0; // 此时没有方案
			if ((target + sum) % 2 == 1)
				return 0; // 此时没有方案

			int bagSize = (target + sum) / 2;

			vector<vector<int>> dp(nums.size(), vector<int>(bagSize + 1, 0));
			//dp[i][j] 0~i的物品，j是容量

			// 初始化
			// 初始化最上行
			if (nums[0] <= bagSize)
				dp[0][nums[0]] = 1;
			// 初始化最左列，最左列其他数值在递推公式中就完成了赋值
			dp[0][0] = 1;
			int numZero = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] == 0)
					numZero++;
				dp[i][0] = (int) pow(2.0, numZero);
			}

			for (int i = 1; i < nums.size(); i++) { //行
				for (int j = 0; j <= bagSize; j++) { //列
					//递推公式
					if (nums[i] > j)
						dp[i][j] = dp[i - 1][j];
					else
						dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
				}
			}
			return dp[nums.size() - 1][bagSize];
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int target = 3;

	vector<int> nums = {1, 1, 1, 1, 1};
	cout << solution.findTargetSumWays(nums, target);
	return 0;
}