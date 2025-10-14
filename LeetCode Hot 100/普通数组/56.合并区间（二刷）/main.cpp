#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> merge(vector<vector<int>> &intervals) {
			int	n = intervals.size();
			if (n == 0) {
				return {};
			}
			sort(intervals.begin(), intervals.end());

			vector<vector<int>> result;
			for (int i = 0; i < n; i++) {
				int start = intervals[i][0], end = intervals[i][1];
				if (result.empty() || start > result.back()[1]) {
					result.push_back({start, end});
				} else {
					result.back()[1] = max(result.back()[1], end);
				}
			}
			return result;
		}
};

int main(int argc, char **argv) {
	Solution solution;

	vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	vector<vector<int>> result = solution.merge(intervals);
	for (const auto perms : result) {
		for (int num : perms) {
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}