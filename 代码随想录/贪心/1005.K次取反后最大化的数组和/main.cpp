#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int largestSumAfterKNegations(vector<int> &nums, int k) {
			int result = 0;
			if (nums.size() == 0)
				return result;
			sort(nums.begin(), nums.end(), [](int a, int b) {
				return abs(a) > abs(b);
			});
//			for (auto num : nums) {
//				cout << num << " ";
//			}
//			cout << endl;
			for (int i = 0; i < nums.size(); i++) {
				if (k > 0 && nums[i] < 0) {
					nums[i] *= -1;
					k--;
				}
			}
			if (k % 2 == 1)
				nums[nums.size() - 1] *= -1;
			result = accumulate(nums.begin(), nums.end(), 0.0);
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {-8, 3, -5, -3, -5, -2};
	int k = 6;
	cout << solution.largestSumAfterKNegations(nums, k);
	return 0;
}