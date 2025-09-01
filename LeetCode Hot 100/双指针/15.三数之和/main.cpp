#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> threeSum(vector<int> &nums) {
			int left = 0;
			int right = 0;
			int n = nums.size();
			vector<vector<int>> Sum;
			while (right < n) {
				if (nums[right] != 0) {
					swap(nums[right], nums[left]);
					left++;
				}
				right++;
			}
			return Sum;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> threeSum = solution.threeSum(nums);
	for (auto &prems : threeSum) {
		for (int num : prems) {
			cout << num << " ";
		}
	}
	return 0;
}