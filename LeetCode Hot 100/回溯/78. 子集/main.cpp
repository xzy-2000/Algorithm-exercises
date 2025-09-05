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
			// ��ֹ����
			if (StartIndex >= nums.size()) {
				return;
			}
			// ����
			for (int i = StartIndex; i < nums.size(); i++) {
				path.push_back(nums[i]);
				// �ݹ�
				backtracing(nums, i + 1);
				// ����
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