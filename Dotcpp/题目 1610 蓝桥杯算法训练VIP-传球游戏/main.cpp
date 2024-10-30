#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;

int dp[maxn][maxn] = {0};
int num, cnt;

int caculation(int x) {
	if (x == 0)
		return num;
	if (x == num + 1)
		return 1;
	return x;
}

int main(int argc, char **argv) {

	cin >> num >> cnt;
	dp[0][1] = 1;
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= num; j++) {
			dp[i][j] = dp[i - 1][caculation(j - 1)] + dp[i - 1][caculation(j + 1)];
		}
	}
	cout << dp[cnt][1];
	return 0;
}
/*
n个同学 m次传球
3 3
*/