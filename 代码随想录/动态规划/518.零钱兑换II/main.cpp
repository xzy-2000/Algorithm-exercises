#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// 完全背包
		int change(int amount, vector<int> &coins) {
			int num = coins.size();
			// 明确dp 动态数组的意义
			vector<vector<int>> dp(num, vector<int>(amount + 1, 0));
			// 初始化
			// 初始化最上行
			for (int j = 0; j <= amount; j++) {
				if (j % coins[0] == 0)
					dp[0][j] = 1;
			}
			// 初始化最左列
			for (int i = 0; i < num; i++) {
				dp[i][0] = 1;
			}
			for (int i = 1; i < num; i++) {
				for (int j = 0; j <= amount; j++) {
					if (j < coins[i])
						dp[i][j] = dp[i - 1][j];
					else
						dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
				}
			}
			return dp[num - 1][amount];
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int amount = 4;

	vector<int> coins = {1, 2, 5};
	cout << solution.change(amount, coins);
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