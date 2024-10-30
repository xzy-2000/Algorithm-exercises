#include <bits/stdc++.h>

using namespace std;

const int num = 2;
const int maxn = 45;

int height;

int a[num] = {1, 2};
int dp[maxn];

int climbStairs(int n) {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < maxn; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[height];
}

int main(int argc, char **argv) {
	int m = 0;
	cin >> height;
	m =	climbStairs(height);
	cout << m;
	return 0;
}