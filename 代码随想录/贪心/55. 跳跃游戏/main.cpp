#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool canJump(vector<int> &nums) {
			// 只有一个元素，就是能达到
			if (nums.size() == 1)
				return true;
			int cover = 0;
			for (int i = 0; i <= cover; i++) {
				cover = max(cover, i + nums[i]);
				// cout << "i = " << i << " cover = " << cover << endl;
				if (cover >= nums.size() - 1)
					return true;
			}
			return false;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {2, 3, 1, 1, 4};
	cout << solution.canJump(nums);
	return 0;
}

/*
2,3,1,1,4
true

3,2,1,0,4
false
*/