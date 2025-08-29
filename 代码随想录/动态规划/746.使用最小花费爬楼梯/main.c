#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int minCostClimbingStairs(vector<int> &cost) {
			int N = cost.size();
			vector<int> dp(N + 1);
			dp[0] = 0;
			dp[1] = 0;
			for (int i = 2; i <= N; i++) {
				dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
			}
			return dp[N];
		}
};

int main(int argc, char **argv) {
	Solution solution;

//	vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	vector<int> cost = {10, 15, 20};
	cout << solution.minCostClimbingStairs(cost);
	return 0;
}
