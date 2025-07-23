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
				if (used[i] == true)
					continue;
				path.push_back(nums[i]);
				used[i] = true;
				//递归
				backtracking(nums, used);
				//回溯
				path.pop_back();
				used[i] = false;
			}
		}
	public:
		vector<vector<int>> permute(vector<int> &nums) {
			vector<bool> used(nums.size(), false);
			backtracking(nums, used);
			return result;
		}
};
int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 2, 3};
	vector<vector<int>> result = solution.permute(nums);
	for (const auto &perm : result) {         // perm 是每一个排列，类型是 vector<int>
		for (int num : perm) {                // num 是排列中的一个数字
			cout << num << " ";
		}
		cout << endl;
	}
}