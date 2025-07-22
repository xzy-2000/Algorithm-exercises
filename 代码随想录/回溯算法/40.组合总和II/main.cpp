#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<vector<int>> result;
		vector<int> path;
		int sum;
		void backtracking(int sum, int startIndex, int target, vector<int> &candidates, vector<bool> &used) {
			// 终止条件
			if (sum > target) {
				return;
			}
			if (sum == target) {
//				cout << "get!";
				result.push_back(path);
				return;
			}
			// 遍历
			for (int i = startIndex; i < candidates.size(); i++) {
				if (i > 0 && candidates[i] == candidates[i - 1]
				        && used[i - 1] == false)
					// 代表相同元素，第一个未使用，则说明是相同元素第二个或之后元素开始遍历，树层剪枝
					continue;

				sum += candidates[i];
				path.push_back(candidates[i]);
				used[i] = true;
				// cout << "sum = " << sum << endl;
				// 递归
				backtracking(sum, i + 1, target, candidates, used); // 关键点:用i+1了，表示不可以重复读取当前的数
				// 回溯
				sum -= candidates[i];
				path.pop_back();
				used[i] = false;
				// cout << "sum = " << sum << endl;
			}
		}
	public:
		vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
			vector<bool> used(candidates.size(), false);
			sort(candidates.begin(), candidates.end());
			backtracking(0, 0, target, candidates, used);
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
	int target = 8;
	vector<vector<int>> result = solution.combinationSum2(candidates, target);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
