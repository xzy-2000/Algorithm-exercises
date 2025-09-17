#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// 最大值/不超过
		int find_high(vector<int> &nums, int l, int r, int target) {
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				if (nums[mid] <= target)
					l = mid;
				else
					r = mid - 1;
			}
			return l;
		}
		// 最小值/至少
		int find_low(vector<int> &nums, int l, int r, int target) {
			while (l < r) {
				int mid = (l + r) >> 1;
				if (nums[mid] >= target)
					r = mid;
				else
					l = mid + 1;
			}
			return l;
		}
		vector<int> searchRange(vector<int> &nums, int target) {
			int low, high;
			int l = 0, r = nums.size() - 1;
			low = find_low(nums, l, r, target);
			if (low == nums.size() || nums[low] != target)
				return {-1, -1};
			high = find_high(nums, l, r, target);
			return {low, high};
		}
};

int main(int argc, char **argv) {
	Solution solution;
	int target = 8;

	vector<int> nums = {5, 7, 7, 8, 8, 10};
	vector<int> result = solution.searchRange(nums, target);
	for (int n : result) {
		cout << n << " ";
	}
	return 0;
}
