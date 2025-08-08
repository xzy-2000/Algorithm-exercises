#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int findLength(vector<int> &nums1, vector<int> &nums2) {
			int len1 = nums1.size();
			int len2 = nums2.size();
			if (len1 == 0 || len2 == 0)
				return 0;
			// ����ͳ�ʼ��
			// dp[i][j]ָ����nums1��nums2�ֱ��±�i��jʱ������������鳤��
			vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
			int result = 0;
			// Ҫ�Ե�һ�У���һ�о��г�ʼ��
			for (int i = 0; i < len1; i++) {
				if (nums1[i] == nums2[0])
					dp[i][0] = 1;
			}

			for (int j = 0; j < len2; j++) {
				if (nums2[j] == nums1[0])
					dp[0][j] = 1;
			}
			// ����
			for (int i = 0; i < len1; i++) {
				for (int j = 0; j < len2; j++) {
					// ���ƹ�ʽ
					if (nums1[i] == nums2[j] && i > 0 && j > 0) {
						dp[i][j] = dp[i - 1][j - 1] + 1;
					}
					if (dp[i][j] > result)
						result = dp[i][j];
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums1 = {1, 1, 0, 0, 1, 1};
	vector<int> nums2 = {0, 0};
	std::cout << solution.findLength(nums1, nums2);
	return 0;
}