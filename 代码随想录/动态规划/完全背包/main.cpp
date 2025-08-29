#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, weight;
	cin >> n >> weight;
	vector<int> w(n), v(n);
	// 第i个物品对应的重量w[i]和对应的价值v[i]

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	// 动态规划数组dp[i][j]表示装到第i个物品的时候，承重为j时最大的价值
	vector<vector<int>> dp(n, vector<int>(weight + 1, 0));

	// 初始化
	// 背包重量为0时，最大价值为0

	for (int i = 0; i < n; i++) {
		dp[i][0] = 0;
	}
	// 在只装第一个物品时，j容量可以装dp[0][j-1]或者dp[0][j-w[i]]+v[i]价值的物品0

	for (int j = w[0]; j <= weight; j++) {
		dp[0][j] = dp[0][j - w[0]] + v[0];
	}
	// 递推公式

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= weight; j++) {
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	// 输出
	cout << dp[n - 1][weight];
	return 0;
}

/*
4 5
1 2
2 4
3 4
4 5

10
*/