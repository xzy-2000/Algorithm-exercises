#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// ��������/ѡ��
		int quickselect(vector<int> &nums, int l, int r, int k)  {
			// ��ֹ����
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

		// �ҵ���K�����Ԫ��
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