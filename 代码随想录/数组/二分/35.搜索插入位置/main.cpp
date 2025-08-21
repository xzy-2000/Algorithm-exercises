#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target) {
	int l = 0, r = nums.size() - 1;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (nums[mid] <= target)
			l = mid;
		else
			r = mid - 1;
	}
	return nums[r] >= target ? r : r + 1;
}

int main() {
	vector<int> nums = {1, 3, 5, 6};
	int target = 6;
	int ans = searchInsert(nums, target);
	cout << ans;
	return 0;
}