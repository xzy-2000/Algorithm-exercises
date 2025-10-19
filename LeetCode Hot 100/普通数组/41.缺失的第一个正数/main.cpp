#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int firstMissingPositive(vector<int> &nums) {
			int n = nums.size();
			for (int &num : nums) {
				if (num <= 0) {
					num = n + 1;
				}
			}
			for (int i = 0; i < n; i++) {
				int a = abs(nums[i]);
				if (a <= n)
					nums[a - 1] = -abs(nums[a - 1]);
			}
			for (int i = 0; i < n; i++) {
				if (nums[i] > 0)
					return i + 1;
			}
			return n + 1;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {3, 4, -1, 1};
	cout << solution.firstMissingPositive(nums);
	return 0;
}