#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.size() == 0)
				return 0;
			// dp[i][n]数组代表第i天持有最多现金
			// dp[i][0]是没有操作
			// dp[i][1]是第一次持有股票，dp[i][2]是第一次不持有股票
			// dp[i][3]是第二次持有股票，dp[i][4]是第二次不持有股票
			vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
			// 初始化dp数组
			dp[0][1] = -prices[0];
			dp[0][3] = -prices[0];

			for (int i = 1; i < prices.size(); i++) {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
				dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
				dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
				dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
			}
			return max(max(dp[prices.size() - 1][0], dp[prices.size() - 1][2]), dp[prices.size() - 1][4]);
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
	std::cout << solution.maxProfit(prices);
	return 0;
}
/*
示例 1:

输入：prices = [3,3,5,0,0,3,1,4]

输出：6 解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3。

示例 2：

输入：prices = [1,2,3,4,5]

输出：4 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4。注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

示例 3：

输入：prices = [7,6,4,3,1]

输出：0 解释：在这个情况下, 没有交易完成, 所以最大利润为0。

示例 4：

输入：prices = [1] 输出：0
*/