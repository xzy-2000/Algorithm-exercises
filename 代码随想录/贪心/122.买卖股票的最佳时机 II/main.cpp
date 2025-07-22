#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// 贪心
		int maxProfit1(vector<int> &prices) {
			int result = 0;
			for (int i = 1; i < prices.size(); i++) {
				result += max(prices[i] - prices[i - 1], 0);
			}
			return result;
		}
		// 动态规划
		int maxProfit(vector<int> &prices) {
			int n = prices.size();
			// dp[i][1]第i天持有的最多现金
			// dp[i][0]第i天持有股票后的最多现金
			// 初始化dp和dp[0][0]
			vector<vector<int>> dp(n, vector<int>(2, 0));
			dp[0][0] -= prices[0]; // 持股票
			for (int i = 1; i < n; i++) {
				// 第i天持股票所剩最多现金 = max(第i-1天持股票所剩现金, 第i-1天持现金-买第i天的股票)
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
				// 第i天持有最多现金 = max(第i-1天持有的最多现金，第i-1天持有股票的最多现金+第i天卖出股票)
				dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
			}
			return max(dp[n - 1][0], dp[n - 1][1]);
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> prices = {7, 1, 5, 3, 6, 4};
	std::cout << solution.maxProfit(prices);
	return 0;
}