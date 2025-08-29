#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lastStoneWeightII(vector<int> &stones) {
			vector<int> dp(15001, 0);
			int sum = accumulate(stones.begin(), stones.end(), 0);
			int target = sum / 2;
			int size = stones.size();
			for (int i = 0; i < size; i++) {
				for (int j = target; j >= stones[i]; j--) {
					dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
				}
			}
			return abs(sum - 2 * dp[target]);
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> stones = {2, 7, 4, 1, 8, 1};
	cout << solution.lastStoneWeightII(stones);
	return 0;
}