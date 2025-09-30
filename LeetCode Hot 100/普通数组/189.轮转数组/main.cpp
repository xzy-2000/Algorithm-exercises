#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void rotate(vector<int> &nums, int k) {
			k %= nums.size(); // 轮转 k 次等于轮转 k % n 次
			reverse(nums.begin(), nums.end());
			reverse(nums.begin(), nums.begin() + k);
			reverse(nums.begin() + k, nums.end());
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	int k = 3;
	solution.rotate(nums, k);
	for (int num : nums) {
		cout << num << " ";
	}
	return 0;
}