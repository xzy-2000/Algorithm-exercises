#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int change(int amount, vector<int> &coins) {
			int num = coins.size();
			// ��ȷdp ��̬���������
			vector<vector<int>> dp(num, vector<int>(amount + 1, 0));
			// ��ʼ��
			// ��ʼ��������
			for (int j = 0; j <= amount; j++) {
				if (j % coins[0] == 0)
					dp[0][j] = 1;
			}
			// ��ʼ��������
			for (int i = 0; i < num; i++) {
				dp[i][0] = 1;
			}
			for (int i = 0; i < num; i++) {
				for (int j = 0; j <= amount; j++) {
					if (j > coins[i])
						dp[i][j] = max(dp[i][j], dp[i][j - coins[i]] + 1);
					else
						dp[i][j] = dp[i][j - 1];
				}
			}
			return dp[num - 1][amount];
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int amount = 5;

	vector<int> coins = {2, 3, 5};
	cout << solution.change(amount, coins);
}