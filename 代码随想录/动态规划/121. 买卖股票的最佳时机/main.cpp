#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.size() == 0)
				return 0;
			// dp[i][n]��������i���������ֽ�
			// dp[i][0]�ǳ��й�Ʊ��dp[i][1]�ǲ����й�Ʊ
			vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
			// ��ʼ��dp����
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