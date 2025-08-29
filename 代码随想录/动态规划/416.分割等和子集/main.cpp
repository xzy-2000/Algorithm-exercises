#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool canPartition(vector<int> &nums) {
			// Ç°×ººÍ
//			int size = nums.size();
//			for (int i = 1; i < size; i++) {
//				nums[i] += nums[i - 1];
//				cout << nums[i] << " ";
//			}
//			for (int i = 0; i < size; i++) {
//				if (nums[i] == nums[size - 1] - nums[i]) {
//					return true;
//				}
//			}
//			return false;
//		}
			vector<int> dp(10001, 0);
			int sum = accumulate(nums.begin(), nums.end(), 0);
			if (sum % 2 == 1)
				return false;
			int target = sum / 2;
			for (int i = 0; i < nums.size(); i++) {
				for (int j = target; j >= nums[i]; j--) {
					dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
				}
			}
			if (dp[target] == target)
				return true;
			return false;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 5, 11, 5};
	cout << solution.canPartition(nums);
	return 0;
}