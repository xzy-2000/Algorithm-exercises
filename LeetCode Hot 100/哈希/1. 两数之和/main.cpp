#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int> &nums, int target) {
			int index = 0;
			int size = nums.size();
			unordered_map<int, int> mp;
			while (index < size) {
				auto it = mp.find(target - nums[index]);
				if (it != mp.end()) {
					return {index, it->second};
				}
				mp[nums[index]] = index;
				index++;
			}
			return {};
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