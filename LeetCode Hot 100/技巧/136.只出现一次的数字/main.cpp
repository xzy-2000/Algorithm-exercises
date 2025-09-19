#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int singleNumber(vector<int> &nums) {
			int ans = 0;
			for (int n : nums) {
				ans ^= n;
			}
			return ans;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {2, 2, 1};
	cout << solution.singleNumber(nums);
	return 0;
}