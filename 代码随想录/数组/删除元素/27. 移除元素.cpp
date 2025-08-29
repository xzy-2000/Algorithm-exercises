#include <bits/stdc++.h>
using namespace std;

vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};

int removeElement(vector<int> &nums, int val) {
	int slowIndex = 0;
	for (auto fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
		if (nums[fastIndex] != val) {
			nums[slowIndex++] = nums[fastIndex];
		}
	}
	return slowIndex;
}

int main() {
	int val = 2;
	int ans = removeElement(nums, val);
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
		cout << nums[i] << " ";
	}
	return 0;
}