#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxSubArray(vector<int> &nums) {
//			// ̰��
//			int n = nums.size();
//			int res = INT_MIN, sum = 0;;
//			for (int i = 0; i < n; i++) {
//				sum += nums[i];
//				res = max(res, sum);
//				if (sum < 0) {
//					sum = 0;
//				}
//			}
//			return res;
			// ��̬�滮
			int n = nums.size();
			// ����dp����
			vector<int> dp(n, 0);
			// ��ʼ��
			dp[0] = nums[0];
			int res = dp[0];
			// ����
			for (int i = 1; i < n; i++) {
				// ���ƹ�ʽ
				dp[i] = max(dp[i - 1] + nums[i], nums[i]);
				res = max(dp[i], res);
			}
			return res;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << solution.maxSubArray(nums);
	return 0;
}