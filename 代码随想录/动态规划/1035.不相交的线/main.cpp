#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
			int len1 = nums1.size();
			int len2 = nums2.size();
			if (len1 == 0 || len2 == 0)
				return 0;
			// ����ͳ�ʼ��
			// dp[i][j]ָ����nums1��nums2�ֱ��±�i��jʱ������������鳤��
			vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
			// ����
			for (int i = 1; i <= len1; i++) {
				for (int j = 1; j <= len2; j++) {
					// ���ƹ�ʽ
					if (nums1[i - 1] == nums2[j - 1]) {
						dp[i][j] = dp[i - 1][j - 1] + 1;
					} else {
						dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
					}
				}
			}
			return dp[len1 ][len2];
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums1 = {2, 5, 1, 2, 5};
	vector<int> nums2 = {10, 5, 2, 1, 5, 2};
	std::cout << solution.maxUncrossedLines(nums1, nums2);
	return 0;
}