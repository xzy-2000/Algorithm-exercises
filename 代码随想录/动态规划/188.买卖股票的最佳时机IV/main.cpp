#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProfit(int k, vector<int> &prices) {
			int len = prices.size();
			if (len == 0)
				return 0;
			// 奇数是持有，偶数是不持有
			vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));
			// 初始化
			for (int j = 1; j < 2 * k; j += 2) {
				dp[0][j] = -prices[0];
			}
			// 遍历
			for (int i = 1; i < len; i++) {
				for (int j = 1; j < 2 * k; j = j + 2) {
					// 持有 2k-1
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
					// 不持有 2k
					dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
				}
			}
			return dp[len - 1][2 * k];
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int k = 2;

	vector<int> prices = {3, 2, 6, 5, 0, 3};
	std::cout << solution.maxProfit(k, prices);
	return 0;
}
/*
示例 1：

输入：k = 2, prices = [2,4,1]

输出：2 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2。

示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]

输出：7 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4。随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
*/