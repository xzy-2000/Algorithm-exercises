#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;

int dp[maxn];

int main() {
	int num, temp_max = 0, cnt = 0;
	int a[maxn];
	dp[0] = 0;
	cin >> num;
	for (int i = 1; i <= num; i++ ) {
		cin >> a[i];
		dp[i] = a[i];
	}
	for (int i = 1; i <= num; i++ ) {
		if (a[i] > temp_max ) {
			dp[i] = max(dp[i], dp[i - 1] + a[i]);
			temp_max = a[i];
			cnt++;
		} else
			dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[num] << ' ' << cnt;
	return 0;
}
/*
10
3 18 7 14 10 12 23 41 16 24
*/