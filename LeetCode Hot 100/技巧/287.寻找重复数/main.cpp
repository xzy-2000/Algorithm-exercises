#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int findDuplicate(vector<int> &nums) {
			int n = nums.size() - 1;
			int l = 1, r = n;
			while (l < r) {
				int mid = (r + l) >> 1, count = 0;
				// 遍历整个数组，统计所有小于等于 mid 的数字的个数 count。
				for (int i = 0; i <= n ; i++) {
					if (nums[i] <= mid)
						count++;
				}
//				cout << "mid = " << mid << " count = " << count << endl;
				// 如果 count <= mid 说明 [1, mid] 这个区间内的数字“没有超额”，所有重复数字都正常出现了。
				if (count <= mid) {
					l = mid + 1;
//					cout << "l = mid + 1 = " << l << endl;
				} else {
					r = mid;
//					cout << "r = mid = " << r << endl;
				}
			}
			return l;
		}
		/*
		int findDuplicate(vector<int> &nums) {
			int slow = 0, fast = 0;
			while (true) {
				slow = nums[slow];
				fast = nums[nums[fast]];
				if (fast == slow) {
					break;
				}
			}
			int finder = 0;
			while (true) {
				slow = nums[slow];
				finder = nums[finder];
				if (finder == slow) {
					return finder;
				}
			}
		}
		*/
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 3, 4, 2, 2};
	for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;
	cout << solution.findDuplicate(nums);
	return 0;
}