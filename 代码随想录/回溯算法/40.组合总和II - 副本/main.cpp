#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<vector<int>> result;
		vector<int> path;
		int sum;
		void backtracking(int sum, int startIndex, int target, vector<int> &candidates, vector<bool> &used) {
			// ÖÕÖ¹Ìõ¼ş
			if (sum > target) {
				return;
			}
			if (sum == target) {
				result.push_back(path);
				return;
			}
			for (int i = startIndex; i < candidates.size(); i++) {
				if (i > 0 && used[i - 1] == false && candidates[i] == candidates[i - 1])
					continue;

				sum += candidates[i];
				path.push_back(candidates[i]);
				used[i] = true;
				backtracking(sum, i + 1, target, candidates, used);
				sum -= candidates[i];
				path.pop_back();
				used[i] = false;
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
