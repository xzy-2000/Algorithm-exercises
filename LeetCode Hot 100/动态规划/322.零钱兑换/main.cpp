#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int coinChange(vector<int> &coins, int amount) {
			int n = coins.size();
			vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX / 2));
			// ��ʼ��
			// ��ʼ��������
			for (int j = 0; j <= amount; j++) {
				if (j % coins[0] == 0)
					dp[0][j] = j / coins[0];
			}
			// ��ʼ��������
			for (int i = 0; i < coins.size(); i++) {
				dp[i][0] = 0;
			}
			// ����
			// ��Ʒ
			for (int i = 1; i < n; i++) {
				// ����
				for (int j = 0; j <= amount; j++) {
					// ���ƹ�ʽ
					if (j >= coins[i]) {
						dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
					} else {
						dp[i][j] = dp[i - 1][j];
					}
//					cout << dp[i][j] << " ";
				}
//				cout << endl;
			}
			int ans = dp[n - 1][amount];
			return ans < INT_MAX / 2 ? ans : -1;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> coins = {1, 2, 5};
	int amount = 11;
	cout << solution.coinChange(coins, amount);
	return 0;
}