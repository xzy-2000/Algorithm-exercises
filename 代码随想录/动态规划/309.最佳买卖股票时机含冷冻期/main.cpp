#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.size() == 0)
				return 0;
			// dp[i][n]数组代表第i天持有最多现金
			// dp[i][0]是买入期持有股票，dp[i][1]是卖出期（过了冷冻期）不持有股票
			// dp[i][2]是今天卖出期不持有股票，dp[i][3]是冷冻期不持有股票
			vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
			// 初始化dp数组
			dp[0][0] = -prices[0];
			dp[0][1] = 0;
			dp[0][2] = 0;
			dp[0][3] = 0;
			for (int i = 1; i < prices.size(); i++) {
				dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]));
				dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
				dp[i][2] = dp[i - 1][0] + prices[i];
				dp[i][3] = dp[i - 1][2];
			}
			return max(dp[prices.size() - 1][3], max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]));
		}
};

int main(int argc, char **argv) {
	Solution solution;

	// 1->2=1  0->2=2 : 1 + 2 = 3

	vector<int> prices = {1, 2, 3, 0, 2};
	std::cout << solution.maxProfit(prices);
	return 0;
}