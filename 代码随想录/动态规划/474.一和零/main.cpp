#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int findMaxForm(vector<string> &strs, int m, int n) {
			vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));// Ä¬ÈÏ³õÊ¼»¯0
			for (auto str : strs) {
				int oneNum = 0, zeroNum = 0;
				for (auto c : str) {
					if (c == '0')
						zeroNum++;
					else
						oneNum++;
				}
				for (int i = m; i >= zeroNum; i--) {
					for (int j = n; j >= oneNum; j--) {
						dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
					}
				}
			}
			return dp[m][n];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<string> strs = {"10", "0001", "111001", "1", "0"};
	int m = 5, n = 3;
	cout << solution.findMaxForm(strs, m, n);
	return 0;
}
