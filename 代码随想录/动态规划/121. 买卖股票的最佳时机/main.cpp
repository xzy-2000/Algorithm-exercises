#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.size() == 0)
				return 0;
			// dp[i][n]数组代表第i天持有最多现金
			// dp[i][0]是持有股票，dp[i][1]是不持有股票
			vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
			// 初始化dp数组
			dp[0][0] = -prices[0];
			dp[0][1] = 0;
			for (int i = 1; i < prices.size(); i++) {
				dp[i][0] = max(dp[i - 1][0], - prices[i]);
				dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
			}
			return dp[prices.size() - 1][0];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> prices = {7, 1, 5, 3, 6, 4};
	std::cout << solution.maxProfit(prices);
	return 0;
}