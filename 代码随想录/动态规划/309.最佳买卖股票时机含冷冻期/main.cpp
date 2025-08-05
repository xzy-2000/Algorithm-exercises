#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.size() == 0)
				return 0;
			// dp[i][n]��������i���������ֽ�
			// dp[i][0]�������ڳ��й�Ʊ��dp[i][1]�������ڣ������䶳�ڣ������й�Ʊ
			// dp[i][2]�ǽ��������ڲ����й�Ʊ��dp[i][3]���䶳�ڲ����й�Ʊ
			vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
			// ��ʼ��dp����
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