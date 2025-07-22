#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// ̰��
		int maxProfit1(vector<int> &prices) {
			int result = 0;
			for (int i = 1; i < prices.size(); i++) {
				result += max(prices[i] - prices[i - 1], 0);
			}
			return result;
		}
		// ��̬�滮
		int maxProfit(vector<int> &prices) {
			int n = prices.size();
			// dp[i][1]��i����е�����ֽ�
			// dp[i][0]��i����й�Ʊ�������ֽ�
			// ��ʼ��dp��dp[0][0]
			vector<vector<int>> dp(n, vector<int>(2, 0));
			dp[0][0] -= prices[0]; // �ֹ�Ʊ
			for (int i = 1; i < n; i++) {
				// ��i��ֹ�Ʊ��ʣ����ֽ� = max(��i-1��ֹ�Ʊ��ʣ�ֽ�, ��i-1����ֽ�-���i��Ĺ�Ʊ)
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
				// ��i���������ֽ� = max(��i-1����е�����ֽ𣬵�i-1����й�Ʊ������ֽ�+��i��������Ʊ)
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