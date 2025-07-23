#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		vector<vector<int>> result;
		vector<int> path;
		void backtracking(vector<int> &nums, vector<bool> &used) {
			// ��ֹ����
			if (nums.size() == path.size()) {
				result.push_back(path);
				return;
			}
			// ����
			for (int i = 0; i < nums.size(); i++) {
				if (used[i] == true)
					continue;
				path.push_back(nums[i]);
				used[i] = true;
				//�ݹ�
				backtracking(nums, used);
				//����
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
	for (const auto &perm : result) {         // perm ��ÿһ�����У������� vector<int>
		for (int num : perm) {                // num �������е�һ������
			cout << num << " ";
		}
		cout << endl;
	}
}