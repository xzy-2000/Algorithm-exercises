#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int jump(vector<int> &nums) {
			if (nums.size() == 1)
				return 0;
			int curDistance = 0;    // 当前覆盖最远距离下标
			int ans = 0;            // 记录走的最大步数
			int nextDistance = 0;   // 下一步覆盖最远距离下标
			for (int i = 0; i < nums.size(); i++) {
				nextDistance = max(nextDistance, nums[i] + i);
				if (i == curDistance) {
					ans++;
					curDistance = nextDistance;
					if (nextDistance >= nums.size() - 1)
						break;
				}

			}
			return ans;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {2, 3, 1, 1, 4};
	cout << solution.jump(nums);
	return 0;
}

/*
2,3,1,1,4
true

3,2,1,0,4
false
*/