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
				// used[i - 1] == true��˵��ͬһ��֦nums[i - 1]ʹ�ù�
				// used[i - 1] == false��˵��ͬһ����nums[i - 1]ʹ�ù�
				if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
					continue;
				if (used[i] == false) {
					path.push_back(nums[i]);
					used[i] = true;
					//�ݹ�
					backtracking(nums, used);
					//����
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
	for (const auto &perm : result) {         // perm ��ÿһ�����У������� vector<int>
		for (int num : perm) {                // num �������е�һ������
			cout << num << " ";
		}
		cout << endl;
	}
}