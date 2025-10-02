#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void nextPermutation(vector<int> &nums) {
			int n = nums.size();

			// 第一步：从右向左找到第一个小于右侧相邻数字的数 nums[i] 1 3 5 4 2 找到了3
			int i = n - 2;
			while (i >= 0 && nums[i] >= nums[i + 1]) {
				i--;
			}

			// 如果找到了，进入第二步；否则跳过第二步，反转整个数组
			if (i >= 0) {
				// 第二步：从右向左找到 nums[i] 右边最小的大于 nums[i] 的数 nums[j] 3最小的大于3的数为4
				int j = n - 1;
				while (nums[j] <= nums[i]) {
					j--;
				}
				cout << i << " " << j << endl;
				// 交换 nums[i] 和 nums[j]
				swap(nums[i], nums[j]);
			}
			// 第三步：反转 [i+1, n-1]（如果上面跳过第二步，此时 i = -1）
			reverse(nums.begin() + i + 1, nums.end());
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 3, 5, 4, 2};
	for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;
	solution.nextPermutation(nums); // 1 4 2 3 5
	for (int n : nums) {
		cout << n << " ";
	}
	return 0;
}