#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int climbStairs(int n) {
			if (n <= 1)
				return n;
			vector<int> dp(n + 1);
			dp[1] = 1;
			dp[2] = 2;
			for (int i = 3; i <= n; i++) { // ע��i�Ǵ�3��ʼ��
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			return dp[n];
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int n = 3;
	cout << solution.climbStairs(n);
	return 0;
}
