#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void moveZeroes(vector<int> &nums) {
			int n = nums.size();
			int left = 0; // ��¼���������λ��
			int right = 0;// ��¼�����λ��
			while (right < n) {
				if (nums[right] != 0) {
					swap(nums[left], nums[right]);
					left++;
				}
				right++;
			}
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {0, 1, 0, 3, 12};
	solution.moveZeroes(nums);
	for (auto &num : nums)
		cout << num << " ";
	return 0;
}

