#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void sortColors(vector<int> &nums) {
			int p0 = 0, p1 = 0;
			for (int i = 0; i < nums.size(); i++) {
				int x = nums[i];
				nums[i] = 2;
				if (x <= 1) {
					nums[p1++] = 1;
				}
				if (x == 0) {
					nums[p0++] = 0;
				}
			}
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {2, 0, 2, 1, 1, 0};
	for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;
	solution.sortColors(nums);
	for (int n : nums) {
		cout << n << " ";
	}
	return 0;
}