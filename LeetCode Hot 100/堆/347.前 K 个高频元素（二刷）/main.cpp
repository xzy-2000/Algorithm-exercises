#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> topKFrequent(vector<int> &nums, int k) {
			unordered_map<int, int> mp;
			int max_cnt = INT_MIN;
			for (int num : nums) {
				mp[num]++;
				max_cnt = max(max_cnt, mp[num]);
			}
			vector<vector<int>> buckets(max_cnt + 1);
			for (auto&[key, value] : mp) {
				buckets[value].push_back(key);
			}
			vector<int> result;
			for (int i = max_cnt; i >= 0 && result.size() < k; i--) {
				for (int num : buckets[i]) {
					result.push_back(num);
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 1, 1, 2, 2, 3};
	int k = 2;
	vector<int> result = solution.topKFrequent(nums, k);
	for (int num : result) {
		cout << num << " ";
	}
	return 0;
}
