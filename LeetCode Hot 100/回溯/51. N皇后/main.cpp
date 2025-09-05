#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> solveNQueens(int n) {
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
	int n = 4;
	vector<vector<int>> result = solution.solveNQueens(n);

	for (const auto &perms : result) {
		for (auto num : perms) {
			cout << num << " ";
		}
		cout << endl;
	}
}