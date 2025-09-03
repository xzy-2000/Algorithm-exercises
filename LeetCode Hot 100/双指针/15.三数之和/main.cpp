#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> threeSum(vector<int> &nums) {
			int left = 0;
			int right = 0;
			int len = nums.size();
			vector<vector<int>> sum;
			sort(nums.begin(), nums.end());
			for (int i = 0; i < len; i++) {
				int left = i + 1, right = len - 1;
				// 去重
				if (i != 0 && nums[i] == nums[i - 1])
					continue;
				while (left < right) {
					if (nums[i] + nums[left] + nums[right] == 0) {
						sum.push_back({nums[i], nums[left], nums[right]});
						left++;
						right--;
						// 去重
						while (left < right && nums[left] == nums[left - 1])
							left++;
						while (left < right && nums[right] == nums[right + 1])
							right--;
					} else if (nums[i] + nums[left] + nums[right] > 0)
						right--;
					else
						left++;
				}
			}
			return sum;
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
		cout << endl;
	}
	return 0;
}