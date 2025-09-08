#include <bits/stdc++.h>
using namespace std;

// 前缀和 + 哈希表优化
class Solution {
	public:
		int subarraySum(vector<int> &nums, int k) {
			int n = nums.size();
			vector<int> pre(n + 1, 0);
			for (int i = 0; i < n; i++) {
				pre[i + 1] = pre[i] + nums[i];
			}
			int result = 0;
			// 哈希表 mp，以和为键，出现次数为对应的值，
			// 记录 pre[i] 出现的次数，从左往右边更新 mp 边计算答案
			unordered_map<int, int> mp;

			for (int j = 0; j <= n; j++) {
				auto it = mp.find(pre[j] - k);
				// 说明之前就有pre[i] - k
				if (it != mp.end()) {
					result += mp[pre[j] - k];
				}
				mp[pre[j]]++;
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 1, 1};
	int k = 2;
	cout << solution.subarraySum(nums, k);
	return 0;
}