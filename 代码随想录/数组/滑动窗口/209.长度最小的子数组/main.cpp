#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int minSubArrayLen(int target, vector<int> &nums) {
			int result = INT32_MAX; // 最终的结果
			int sum = 0; // 滑动窗口数值之和
			int i = 0; // 滑动窗口起始位置
			int subLength = 0; // 滑动窗口的长度
			for (int j = 0; j < nums.size(); j++) {
				sum += nums[j];
				while (sum >= target) {
					subLength = j - i + 1;
					result = min(result, subLength);
					sum -= nums[i++];
				}
			}
			return result == INT32_MAX ? 0 : result;
		}
};

int main() {
	Solution solution;
	int target = 7;
	vector<int> nums = {2, 3, 1, 2, 4, 3};
	int ans = solution.minSubArrayLen(target, nums);
	cout << ans;
}