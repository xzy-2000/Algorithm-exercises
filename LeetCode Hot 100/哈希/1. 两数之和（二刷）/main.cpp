#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int> &nums, int target) {
			int n = nums.size();
			unordered_map<int, int> mp;
			for (int i = 0; i < n; i++) {
				if (mp.find(target - nums[i]) != mp.end()) {
					return {mp.find(target - nums[i])->second, i};
				}
				mp[nums[i]] = i;
			}
			return {0, 0};
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	vector<int> result = solution.twoSum(nums, target);

	for (int num : result) {
		cout << num << " ";
	}
	return 0;
}