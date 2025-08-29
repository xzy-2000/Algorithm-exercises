#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int integerBreak(int n) {
			vector<int> dp(n + 1);
			dp[2] = 1;
			for (int i = 3; i <= n; i++) {
				for (int j = 1; j <= i / 2; j++) {
					dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
				}
//				cout << "dp[" << i << "] = " << dp[i] << endl;
			}
			return dp[n];
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int n = 10;
	cout << solution.integerBreak(n);
	return 0;
}