#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int majorityElement(vector<int> &nums) {
			int hp = 0, ans = 0;
			for (int x : nums) {
				if (hp == 0) {
					ans = x;
					hp = 1;
				} else {
					if (x != ans) {
						hp--;
					} else {
						hp++;
					}
				}
			}
			return ans;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
	cout << solution.majorityElement(nums);
	return 0;
}