#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// 完全背包
		int change(int amount, vector<int> &coins) {
			/*
			int num = coins.size();
			// 明确dp 动态数组的意义,代表容量为j，物品为0-i个时，有多少种策略
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
					if (coins[i] > j)
						dp[i][j] = dp[i - 1][j];
					else
						dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
			//					cout << dp[i][j] << " ";
				}
			//				cout << endl;
			}
			return dp[num - 1][amount];
			*/
			// 滚动数组
			int num = coins.size();
			// 明确dp 动态数组的意义,代表容量为j，物品为0-i个时，有多少种策略
			vector<int> dp(amount + 1, 0);
			//初始化
			for (int j = 0; j <= amount; j++) {
				if (j % coins[0] == 0)
					dp[j] = 1;
			}
			for (int i = 1; i < num; i++) {
				for (int j = coins[i]; j <= amount; j++) {
						dp[j] = dp[j] + dp[j - coins[i]];
				}
			}
			return dp[amount];
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int amount = 5;

	vector<int> coins = {2, 3, 5};
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