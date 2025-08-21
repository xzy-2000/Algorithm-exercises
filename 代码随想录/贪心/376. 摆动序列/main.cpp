#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int wiggleMaxLength(vector<int> &nums) {
			if (nums.size() <= 1)
				return nums.size();
			int curDiff = 0; // 当前一对差值
			int preDiff = 0; // 前一对差值
			int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
			int flag = 1;
			switch (flag) {
				//贪心
				case 0:
//					cout << "贪心";
					for (int i = 0; i < nums.size() - 1; i++) {
						curDiff = nums[i + 1] - nums[i];
						// 出现峰值
						if ((preDiff >= 0 && curDiff < 0) || (preDiff <= 0 && curDiff > 0)) {
							result++;
							preDiff = curDiff;
						}
					}
					break;
				//动态规划
				case 1:
//					cout << "动态规划";
// 设 dp 状态dp[i][0]，表示考虑前 i 个数，第 i 个数作为山峰的摆动子序列的最长长度
// 设 dp 状态dp[i][1]，表示考虑前 i 个数，第 i 个数作为山谷的摆动子序列的最长长度
					vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
					//初始化
					dp[0][0] = 1;
					dp[0][1] = 1;
					//遍历
					for (int i = 1; i < nums.size(); i++) {
						dp[i][0] = dp[i][1] = 1;
						//状态转移方程
						for (int j = 0; j < i; ++j) {
							if (nums[i] < nums[j]) {
								dp[i][1] = max(dp[i][1], dp[j][0] + 1);
							}
						}
						for (int j = 0; j < i; ++j) {
							if (nums[i] > nums[j]) {
								dp[i][0] = max(dp[i][0], dp[j][1] + 1);
							}
						}
					}
					result = max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
					break;
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 7, 4, 9, 2, 5};
	cout << solution.wiggleMaxLength(nums);
	return 0;
}