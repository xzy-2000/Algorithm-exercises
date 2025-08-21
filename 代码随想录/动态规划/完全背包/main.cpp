#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, weight;
	cin >> n >> weight;
	vector<int> w(n), v(n);
	// ��i����Ʒ��Ӧ������w[i]�Ͷ�Ӧ�ļ�ֵv[i]

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	// ��̬�滮����dp[i][j]��ʾװ����i����Ʒ��ʱ�򣬳���Ϊjʱ���ļ�ֵ
	vector<vector<int>> dp(n, vector<int>(weight + 1, 0));

	// ��ʼ��
	// ��������Ϊ0ʱ������ֵΪ0

	for (int i = 0; i < n; i++) {
		dp[i][0] = 0;
	}
	// ��ֻװ��һ����Ʒʱ��j��������װdp[0][j-1]����dp[0][j-w[i]]+v[i]��ֵ����Ʒ0

	for (int j = w[0]; j <= weight; j++) {
		dp[0][j] = dp[0][j - w[0]] + v[0];
	}
	// ���ƹ�ʽ

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= weight; j++) {
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	// ���
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