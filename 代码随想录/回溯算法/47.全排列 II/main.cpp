#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<vector<int>> result;
		vector<int> path;
		void backtracking(vector<int> &nums, vector<bool> &used) {
			// 终止条件
			if (nums.size() == path.size()) {
				result.push_back(path);
				return;
			}
			// 遍历
			for (int i = 0; i < nums.size(); i++) {
				// used[i - 1] == true，说明同一树枝nums[i - 1]使用过
				// used[i - 1] == false，说明同一树层nums[i - 1]使用过
				if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
					continue;
				if (used[i] == false) {
					path.push_back(nums[i]);
					used[i] = true;
					//递归
					backtracking(nums, used);
					//回溯
					path.pop_back();
					used[i] = false;
				}
			}
		}
	public:
		vector<vector<int>> permuteUnique(vector<int> &nums) {
			vector<bool> used(nums.size(), false);
			sort(nums.begin(), nums.end());
			backtracking(nums, used);
			return result;
		}
};
int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 1, 3};
	vector<vector<int>> result = solution.permuteUnique(nums);
	for (const auto &perm : result) {         // perm 是每一个排列，类型是 vector<int>
		for (int num : perm) {                // num 是排列中的一个数字
			cout << num << " ";
		}
		cout << endl;
	}
}