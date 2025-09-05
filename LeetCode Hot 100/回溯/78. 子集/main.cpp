#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> subsets(vector<int> &nums) {
			backtracing(nums, 0);
			return result;
		}
	private:
		vector<vector<int>> result;
		vector<int> path;
		void backtracing(vector<int> &nums, int StartIndex) {
			result.push_back(path);
			// 终止条件
			if (StartIndex >= nums.size()) {
				return;
			}
			// 遍历
			for (int i = StartIndex; i < nums.size(); i++) {
				path.push_back(nums[i]);
				// 递归
				backtracing(nums, i + 1);
				// 回溯
				path.pop_back();
			}
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> nums = {1, 2, 3};
	vector<vector<int>> result = solution.subsets(nums);
	for (const auto &perms : result) {
		for (auto num : perms) {
			cout << num << " ";
		}
		cout << endl;
	}
}