#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// 快速排序/选择
		int quickselect(vector<int> &nums, int l, int r, int k)  {
			// 终止条件
			if (l >= r) {
				return nums[k];
			}
			int partition = nums[l], i = l - 1, j = r + 1;;
			while (i < j) {
				do
					i++;
				while (nums[i] < partition);
				do
					j--;
				while (nums[j] > partition);
				if (i < j)
					swap(nums[i], nums[j]);
			}
			if (k <= j)
				quickselect(nums, l, j, k);
			else
				quickselect(nums, j + 1, r, k);
		}

		// 找到第K个最大元素
		int findKthLargest(vector<int> &nums, int k) {
			return quickselect(nums, 0, nums.size() - 1, nums.size() - k);
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {3, 2, 1, 5, 6, 4};
	int k = 2;
	cout << solution.findKthLargest(nums, k);
	return 0;
}