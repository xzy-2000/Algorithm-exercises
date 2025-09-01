#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int longestConsecutive(vector<int> &nums) {
			int result = 0;
			if (nums.size() <= 1)
				return nums.size();
			unordered_map<int, int> map;
			for (const auto &num : nums) {
				if (map[num] == 0) {
					int left = map[num - 1];
					int right = map[num + 1];
					int now = left + right + 1;

					map[num] = now;
					map[num - left] = now;
					map[num + right] = now;
					
					result = max(result, now);
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 0, 1, 2};
	cout << solution.longestConsecutive(nums);
	return 0;
}
/*
100, 4, 200, 1, 3, 2
4

0,3,7,2,5,8,4,6,0,1
9

1,0,1,2
3
*/