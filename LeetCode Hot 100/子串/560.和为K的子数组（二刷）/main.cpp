#include <bits/stdc++.h>
using namespace std;

// 前缀和 + 哈希表优化
class Solution {
	public:
		int subarraySum(vector<int> &nums, int k) {
			int n = nums.size();
			vector<int> s(n + 1, 0);
			for (int i = 0; i < n; i++) {
				s[i + 1] = s[i] + nums[i];
			}
			int res = 0;
			unordered_map<int, int> mp;
			for (int j = 0; j <= n; j++) {
				int si = s[j] - k;
				if (mp.find(si) != mp.end()) {
					res += mp[si];
				}
				mp[s[j]]++;
			}
			return res;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 1, 1};
	int k = 2;
	cout << solution.subarraySum(nums, k);
	return 0;
}